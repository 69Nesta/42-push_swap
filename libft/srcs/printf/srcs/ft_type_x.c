/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 10:03:09 by rpetit            #+#    #+#             */
/*   Updated: 2025/12/17 15:10:46 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_right_align_x(const t_args *arg, int nlen, unsigned int hex);
static int	ft_middle_align_x(const t_args *arg, int nlen, unsigned int hex);

int	ft_type_x(unsigned int hex, const t_args *arg)
{
	int	count;
	int	len;

	count = 0;
	len = ft_putnbr_base_len(hex, 16);
	if (arg->alternate_form && hex != 0)
		len += 2;
	if (hex == 0 && arg->has_precision && arg->precision == 0)
		len = 0;
	ft_swrite(&count, ft_right_align_x(arg, len, hex));
	ft_swrite(&count, ft_middle_align_x(arg, len, hex));
	if (!(hex == 0 && arg->has_precision && arg->precision == 0))
		ft_swrite(&count, ft_putnbr_base_r(hex, "0123456789abcdef", 16, arg));
	ft_swrite(&count, ft_left_align(arg, ' ', len));
	return (count);
}

int	ft_istype_x(const t_args *arg)
{
	return (arg->type == 'x');
}

static int	ft_right_align_x(const t_args *arg, int nlen, unsigned int hex)
{
	int	i;
	int	printed;

	i = 0;
	printed = 0;
	if (arg->left_align)
		return (printed);
	if (arg->alternate_form && arg->zero_pad && hex != 0)
		ft_swrite(&printed, ft_write_n("0x", 2, arg->fd));
	while ((ft_max(nlen, arg->precision)) + i < arg->width)
	{
		ft_swrite(&printed, ft_putchar_arg(
				' ' * (!arg->zero_pad || arg->has_precision)
				+ '0' * (arg->zero_pad && !arg->has_precision), arg));
		i++;
	}
	return (printed);
}

static int	ft_middle_align_x(const t_args *arg, int nlen, unsigned int hex)
{
	int	i;
	int	printed;

	i = 0;
	printed = 0;
	if (arg->alternate_form && !arg->zero_pad && hex != 0)
		ft_swrite(&printed, ft_write_n("0x", 2, arg->fd));
	if (!(arg->zero_pad || arg->precision > (nlen)))
		return (printed);
	while (nlen + i < arg->precision)
	{
		ft_swrite(&printed, ft_putchar_arg('0', arg));
		i++;
	}
	return (printed);
}
