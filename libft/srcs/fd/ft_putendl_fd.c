/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 12:29:25 by rpetit            #+#    #+#             */
/*   Updated: 2025/12/17 13:45:53 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putendl_fd(char *s, int fd)
{
	int	total;

	if (!s)
		return (0);
	total = 0;
	total += ft_putstr_fd(s, fd);
	total += ft_putchar_fd('\n', fd);
	return (total);
}
