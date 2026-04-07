/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 09:10:38 by rpetit            #+#    #+#             */
/*   Updated: 2025/12/17 13:45:53 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_type_s(const char *string, const t_args *arg)
{
	int	count;
	int	len;

	count = 0;
	if (!string && arg->has_precision)
		len = 6;
	else if (!string)
		len = 6;
	else if (string)
		len = ft_strlen(string);
	if (string && len > arg->precision && arg->has_precision)
		len = arg->precision;
	else if (!string && len > arg->precision && arg->has_precision)
		len = 0;
	ft_swrite(&count, ft_right_align(arg, ' ', len, 1));
	if (!string && len)
		ft_swrite(&count, ft_write_n("(null)", len, arg->fd));
	else if (string)
		ft_swrite(&count, ft_write_n(string, len, arg->fd));
	ft_swrite(&count, ft_left_align(arg, ' ', len));
	return (count);
}

int	ft_istype_s(const t_args *arg)
{
	return (arg->type == 's');
}
