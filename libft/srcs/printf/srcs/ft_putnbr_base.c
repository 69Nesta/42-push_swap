/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 09:31:12 by rpetit            #+#    #+#             */
/*   Updated: 2025/12/17 14:01:47 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base_r(unsigned long n, const char *base, int base_len,
				const t_args *arg)
{
	int	count;

	count = 0;
	if (n / base_len > 0)
		count = ft_putnbr_base_r(n / base_len, base, base_len, arg);
	ft_swrite(&count, ft_putchar_arg(base[n % base_len], arg));
	return (count);
}

int	ft_putnbr_base_len(unsigned long n, int base_len)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= base_len;
		count++;
	}
	return (count);
}
