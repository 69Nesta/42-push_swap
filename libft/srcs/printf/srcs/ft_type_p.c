/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 09:16:05 by rpetit            #+#    #+#             */
/*   Updated: 2025/12/17 15:10:25 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_type_p(unsigned long ptr, const t_args *arg)
{
	int	count;
	int	len;

	count = 0;
	if (!ptr)
		len = 5;
	else
		len = ft_putnbr_base_len(ptr, 16) + 2;
	if (ptr && arg->show_sign)
		len++;
	ft_swrite(&count, ft_right_align(arg, ' ', len, ptr == 0));
	if (!ptr)
		ft_swrite(&count, ft_write_n("(nil)", 5, arg->fd));
	else
	{
		if (arg->show_sign)
			ft_swrite(&count, ft_putchar_arg('+', arg));
		else if (arg->space_sign)
			ft_swrite(&count, ft_putchar_arg(' ', arg));
		ft_swrite(&count, ft_write_n("0x", 2, arg->fd));
		ft_swrite(&count, ft_middle_zero(arg, '0', len));
		ft_swrite(&count, ft_putnbr_base_r(ptr, "0123456789abcdef", 16, arg));
	}
	ft_swrite(&count, ft_left_align(arg, ' ', len));
	return (count);
}

int	ft_istype_p(const t_args *arg)
{
	return (arg->type == 'p');
}
