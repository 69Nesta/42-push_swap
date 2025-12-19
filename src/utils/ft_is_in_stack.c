/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_in_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 11:01:40 by rpetit            #+#    #+#             */
/*   Updated: 2025/12/19 11:03:05 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_in_stack(int *stack, int size, int nbr)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (stack[i] == nbr)
			return (1);
		i++;
	}
	return (0);
}
