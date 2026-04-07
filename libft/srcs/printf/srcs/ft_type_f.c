/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 08:33:29 by rpetit            #+#    #+#             */
/*   Updated: 2025/12/17 13:45:50 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_type_f_calc(double n, t_printf_values *vals, const t_args *arg);

int	ft_type_f(double n, const t_args *arg)
{
	int				count;
	t_printf_values	vals;

	count = 0;
	ft_type_f_calc(n, &vals, arg);
	ft_swrite(&count, ft_right_align(arg, ' ', vals.printed_len, 0));
	if (vals.neg)
		ft_swrite(&count, ft_putchar_arg('-', arg));
	else if (arg->show_sign)
		ft_swrite(&count, ft_putchar_arg('+', arg));
	else if (arg->space_sign)
		ft_swrite(&count, ft_putchar_arg(' ', arg));
	ft_swrite(&count, ft_middle_zero(arg, '0', vals.printed_len));
	ft_swrite(&count, ft_putnbr_double(vals.int_part, vals.frac_part,
			vals.precision, arg->fd));
	ft_swrite(&count, ft_left_align(arg, ' ', vals.printed_len));
	return (count);
}

static void	ft_type_f_calc(double n, t_printf_values *vals, const t_args *arg)
{
	vals->neg = ft_signbit(n);
	vals->absn = n;
	if (vals->neg)
		vals->absn = -vals->absn;
	if (arg->has_precision && arg->precision > 0)
		vals->precision = arg->precision;
	else
		vals->precision = 6;
	vals->pow10 = ft_pow10_double(10.0, vals->precision);
	vals->rounded = ft_floor_double(vals->absn * vals->pow10 + 0.5);
	vals->frac_part = (unsigned long)ft_fmod_double(vals->rounded, vals->pow10);
	vals->int_part = (long long)(vals->rounded / vals->pow10);
	vals->printed_len = 0;
	if (vals->int_part == 0)
		vals->printed_len = 1;
	else
		vals->printed_len = ft_get_int_len(vals->int_part);
	if (vals->precision > 0)
		vals->printed_len += 1 + vals->precision;
	if (vals->neg || arg->show_sign || arg->space_sign)
		vals->printed_len++;
}

int	ft_istype_f(const t_args *arg)
{
	return (arg->type == 'f');
}
