/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floor_double.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 16:17:08 by rpetit            #+#    #+#             */
/*   Updated: 2025/12/16 16:42:07 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_floor_double(double x)
{
	double	result;

	result = (double)(long)(x);
	if (x < 0 && result != x)
		result -= 1.0;
	return (result);
}
