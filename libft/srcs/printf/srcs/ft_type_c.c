/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 09:06:29 by rpetit            #+#    #+#             */
/*   Updated: 2025/12/17 13:45:53 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_type_c(char c, const t_args *arg)
{
	int	count;

	count = ft_right_align(arg, ' ', 1, 1);
	ft_swrite(&count, ft_putchar_arg(c, arg));
	ft_swrite(&count, ft_left_align(arg, ' ', 1));
	return (count);
}

int	ft_istype_c(const t_args *arg)
{
	return (arg->type == 'c');
}
