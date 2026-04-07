/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 08:44:55 by rpetit            #+#    #+#             */
/*   Updated: 2025/12/11 16:15:59 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_nl(const char *str, size_t size)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (i < size && str[i] && str[i] != '\n')
		i++;
	return (i);
}

size_t	ft_fill_line(char *line, char *buffer, size_t size)
{
	size_t	i;

	i = 0;
	if (!line && size > 0)
		return (0);
	while (i < size)
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[size] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (i + (buffer[size] == '\n'));
}

char	*ft_realloc_gnl(char *src, size_t size, size_t add_size)
{
	size_t	i;
	char	*new_src;

	i = 0;
	new_src = malloc(sizeof(char) * (size + add_size + 1));
	if (!new_src)
	{
		free(src);
		return (NULL);
	}
	while (i < size)
	{
		new_src[i] = src[i];
		i++;
	}
	if (size > 0)
		free(src);
	new_src[i] = '\0';
	return (new_src);
}
