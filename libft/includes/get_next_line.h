/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 08:42:59 by rpetit            #+#    #+#             */
/*   Updated: 2025/12/11 17:10:28 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 65536
# endif
# ifndef FD_MAX
#  define FD_MAX 8
# endif

# include <unistd.h>
# include <stdlib.h>

typedef struct s_gnl
{
	ssize_t	buffer_index;
	char	buffer[BUFFER_SIZE];
	ssize_t	bytes_read;
}	t_gnl;

char	*get_next_line(int fd);

/* Utils */
size_t	ft_strlen_nl(const char *str, size_t size);
char	*ft_realloc_gnl(char *src, size_t size, size_t add_size);
size_t	ft_fill_line(char *line, char *buffer, size_t size);

#endif