/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 08:37:44 by rpetit            #+#    #+#             */
/*   Updated: 2025/12/11 16:17:58 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	ft_read(int fd, t_gnl *gnl, char **line, int *stop);
static void	ft_processes(t_gnl *gnl, char **line, size_t *line_size, int *stop);
static void	ft_free_on_fail(char **line, int *stop);

char	*get_next_line(int fd)
{
	static t_gnl	gnl[FD_MAX] = {0};
	char			*line;
	size_t			line_size;
	int				stop;

	stop = 0;
	line = NULL;
	line_size = 0;
	if (fd < 0 || fd >= FD_MAX)
		return (NULL);
	while (!stop)
	{
		ft_read(fd, &(gnl[fd]), &line, &stop);
		if (!stop)
			ft_processes(&(gnl[fd]), &line, &line_size, &stop);
	}
	return (line);
}

static void	ft_read(int fd, t_gnl *gnl, char **line, int *stop)
{
	if (gnl->buffer_index >= gnl->bytes_read)
	{
		gnl->bytes_read = read(fd, gnl->buffer, BUFFER_SIZE);
		if ((gnl->bytes_read <= 0 && !*line) || (gnl->bytes_read < 0 && *line))
		{
			ft_free_on_fail(line, stop);
			return ;
		}
		else if (gnl->bytes_read == 0)
		{
			*stop = 1;
			return ;
		}
		if (gnl->bytes_read < BUFFER_SIZE)
			gnl->buffer[gnl->bytes_read] = 0;
		gnl->buffer_index = 0;
	}
}

static void	ft_processes(t_gnl *gnl, char **line, size_t *line_size, int *stop)
{
	size_t	len_to_nl;

	len_to_nl = ft_strlen_nl(gnl->buffer + gnl->buffer_index,
			gnl->bytes_read - gnl->buffer_index);
	*line = ft_realloc_gnl(*line, *line_size,
			len_to_nl + (gnl->buffer[gnl->buffer_index + len_to_nl] == '\n'));
	if (!*line)
	{
		ft_free_on_fail(line, stop);
		return ;
	}
	*line_size += ft_fill_line(*line + *line_size,
			gnl->buffer + gnl->buffer_index, len_to_nl);
	if (gnl->buffer[gnl->buffer_index + len_to_nl] == '\n')
	{
		gnl->buffer_index += len_to_nl + 1;
		*stop = 1;
		return ;
	}
	else
		gnl->buffer_index += len_to_nl;
}

static void	ft_free_on_fail(char **line, int *stop)
{
	if (*line)
		free(*line);
	*line = NULL;
	*stop = 1;
}
