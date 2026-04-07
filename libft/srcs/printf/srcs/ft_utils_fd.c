/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_fd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 15:11:17 by rpetit            #+#    #+#             */
/*   Updated: 2025/12/17 15:12:06 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar_to_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}

int	ft_putstr_to_fd(const char *str, int fd)
{
	if (!str)
		return (0);
	return ((int)write(fd, str, ft_strlen(str)));
}

int	ft_ischarset(char c, char *set)
{
	int	i;

	i = 0;
	while (set[i] && set[i] != c)
		i++;
	return (c == set[i]);
}
