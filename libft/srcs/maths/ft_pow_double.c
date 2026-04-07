/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow_double.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 16:16:45 by rpetit            #+#    #+#             */
/*   Updated: 2025/12/16 16:42:14 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_pow10_double(double base, int exp)
{
	double	result;
	int		i;

	result = 1.0;
	i = 0;
	while (i < exp)
	{
		result *= base;
		i++;
	}
	return (result);
}
