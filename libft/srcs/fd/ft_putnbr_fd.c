/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 12:35:36 by rpetit            #+#    #+#             */
/*   Updated: 2025/12/17 13:45:53 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_putnbr(unsigned int n, int fd);

int	ft_putnbr_fd(int n, int fd)
{
	int	total;

	total = 0;
	if (n < 0)
	{
		total += ft_putchar_fd('-', fd);
		total += ft_putnbr((unsigned int)(-n), fd);
	}
	else
		total += ft_putnbr((unsigned int)n, fd);
	return (total);
}

static int	ft_putnbr(unsigned int n, int fd)
{
	int	cnt;

	cnt = 0;
	if (n / 10 > 0)
		cnt += ft_putnbr(n / 10, fd);
	cnt += ft_putchar_fd(n % 10 + '0', fd);
	return (cnt);
}
