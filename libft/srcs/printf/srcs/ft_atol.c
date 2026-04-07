/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 10:15:57 by rpetit            #+#    #+#             */
/*   Updated: 2025/12/11 16:52:59 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_atol	ft_return(long res, int len)
{
	t_atol	result;

	result.value = res;
	result.len = len;
	return (result);
}

t_atol	ft_atol_pf(const char *nptr)
{
	unsigned long	res;
	unsigned long	new_val;
	int				sign;
	size_t			i;

	res = 0;
	sign = 1;
	i = 0;
	while ((nptr[i] >= '\t' && nptr[i] <= '\r') || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i++] == '-')
			sign *= -1;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		new_val = res * 10 + nptr[i++] - '0';
		if (new_val >= res)
			res = new_val;
		else
			return (ft_return((sign == 1) * -1, i));
	}
	return (ft_return(sign * res, i));
}
