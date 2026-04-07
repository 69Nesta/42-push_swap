/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alignment.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 09:50:13 by rpetit            #+#    #+#             */
/*   Updated: 2025/12/17 13:45:53 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_left_align(const t_args *arg, const char fill, int printed_w)
{
	int	i;
	int	printed;

	i = 0;
	printed = 0;
	if (arg->width == 0 || !arg->left_align)
		return (printed);
	while (printed_w + i < arg->width)
	{
		ft_swrite(&printed, ft_putchar_arg(fill, arg));
		i++;
	}
	return (printed);
}

int	ft_middle_zero(const t_args *arg, const char fill, int printed_w)
{
	int	i;
	int	printed;

	i = 0;
	printed = 0;
	if (arg->width == 0 || !arg->zero_pad || arg->left_align)
		return (printed);
	while (printed_w + i < arg->width)
	{
		ft_swrite(&printed, ft_putchar_arg(fill, arg));
		i++;
	}
	return (printed);
}

int	ft_right_align(const t_args *arg, const char fill, int w, int is_null)
{
	int	i;
	int	printed;

	i = 0;
	printed = 0;
	if (arg->width == 0 || arg->left_align || (arg->zero_pad && !is_null))
		return (printed);
	while (w + i < arg->width)
	{
		ft_swrite(&printed, ft_putchar_arg(fill, arg));
		i++;
	}
	return (printed);
}
