/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swrite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 19:19:40 by rpetit            #+#    #+#             */
/*   Updated: 2025/12/04 14:02:02 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_swrite(int *count, int write_value)
{
	if (write_value < 0)
		*count = -1;
	if (*count >= 0)
		*count += write_value;
}
