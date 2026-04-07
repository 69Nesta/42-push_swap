/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 09:53:31 by rpetit            #+#    #+#             */
/*   Updated: 2025/12/17 13:45:49 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_r(unsigned int n, const t_args *arg)
{
	int	count;

	count = 0;
	if (n / 10 > 0)
		count = ft_putnbr_r(n / 10, arg);
	ft_swrite(&count, ft_putchar_arg(n % 10 + '0', arg));
	return (count);
}

int	ft_putnbr_len(unsigned int n, const t_args *arg)
{
	int	count;

	count = 0;
	if (arg->space_sign || arg->show_sign)
		count++;
	if (n == 0)
		return (count + 1);
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}
