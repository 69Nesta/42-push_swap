/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_mod.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 12:24:26 by rpetit            #+#    #+#             */
/*   Updated: 2025/12/17 15:33:53 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_type_mod(const t_args *arg)
{
	(void)arg;
	return (ft_putchar_fd('%', arg->fd));
}

int	ft_istype_mod(const t_args *arg)
{
	return (arg->type == '%');
}
