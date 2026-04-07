/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 14:33:26 by rpetit            #+#    #+#             */
/*   Updated: 2025/12/17 15:11:03 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putchar_arg(char c, const t_args *arg)
{
	if (!arg)
		return (ft_putchar(c));
	return ((int)write(arg->fd, &c, 1));
}

int	ft_putstr(const char *str)
{
	if (!str)
		return (0);
	return (write(1, str, ft_strlen(str)));
}

int	ft_write_n(const char *s, int n, int fd)
{
	if (!s || n <= 0)
		return (0);
	return ((int)write(fd, s, n));
}

/* fd variants for fprintf support (kept for non-printf usage) */
