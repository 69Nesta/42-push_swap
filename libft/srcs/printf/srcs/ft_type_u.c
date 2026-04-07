/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 08:33:29 by rpetit            #+#    #+#             */
/*   Updated: 2025/12/17 13:45:50 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_right_align_u(const t_args *arg, int nlen);
static int	ft_middle_align_u(const t_args *arg, int nlen);

int	ft_type_u(unsigned int n, const t_args *arg)
{
	int	count;
	int	len;

	count = 0;
	len = ft_putnbr_len(n, arg);
	if (arg->space_sign || arg->show_sign)
		len--;
	if (n == 0 && arg->has_precision && arg->precision == 0)
		len = 0;
	ft_swrite(&count, ft_right_align_u(arg, len));
	ft_swrite(&count, ft_middle_align_u(arg, len));
	if (!(n == 0 && arg->has_precision && arg->precision == 0))
		ft_swrite(&count, ft_putnbr_r(n, arg));
	ft_swrite(&count, ft_left_align(arg, ' ', count));
	return (count);
}

int	ft_istype_u(const t_args *arg)
{
	return (arg->type == 'u');
}

static int	ft_right_align_u(const t_args *arg, int nlen)
{
	int	i;
	int	printed;

	i = 0;
	printed = 0;
	if (arg->left_align)
		return (printed);
	while ((ft_max(nlen, arg->precision)) + i < arg->width)
	{
		ft_swrite(&printed, ft_putchar(
				' ' * (!arg->zero_pad || arg->has_precision)
				+ '0' * (arg->zero_pad && !arg->has_precision)));
		i++;
	}
	return (printed);
}

static int	ft_middle_align_u(const t_args *arg, int nlen)
{
	int	i;
	int	printed;

	i = 0;
	printed = 0;
	if (!(arg->zero_pad || arg->precision > (nlen)))
		return (printed);
	while (nlen + i < arg->precision)
	{
		ft_swrite(&printed, ft_putchar('0'));
		i++;
	}
	return (printed);
}
