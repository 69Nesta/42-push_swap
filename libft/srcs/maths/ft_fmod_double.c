/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fmod_double.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 16:16:58 by rpetit            #+#    #+#             */
/*   Updated: 2025/12/16 16:41:33 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_fmod_double(double x, double y)
{
	double	result;

	result = x - ft_floor_double(x / y) * y;
	return (result);
}
