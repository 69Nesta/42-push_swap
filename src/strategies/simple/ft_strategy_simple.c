/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strategy_simple.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 15:32:25 by rpetit            #+#    #+#             */
/*   Updated: 2025/12/15 09:59:16 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_strategy_simple(t_push_swap *push_swap)
{
	int	index;
	int stack_size;
	
	stack_size = push_swap->stack_a_size;
	while (ft_disorder(push_swap) != (float)0)
	{
		index = 0;
		while (index < stack_size - 1)
		{
			if (push_swap->stack_a[0] > push_swap->stack_a[1])
				ft_operation_s(push_swap, STACK_A);
			ft_operation_r(push_swap, STACK_A);
			index++;
		}
		ft_operation_r(push_swap, STACK_A);
	}
}
