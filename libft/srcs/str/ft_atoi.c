/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 10:15:57 by rpetit            #+#    #+#             */
/*   Updated: 2025/11/14 11:21:11 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	ft_atol(const char *nptr)
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
			return ((sign == 1) * -1);
	}
	return (sign * res);
}

int	ft_atoi(const char *nptr)
{
	return ((int) ft_atol(nptr));
}
