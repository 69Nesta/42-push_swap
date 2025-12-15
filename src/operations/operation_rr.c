/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 15:18:07 by lgirard           #+#    #+#             */
/*   Updated: 2025/12/15 15:38:20 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rr(int *stack, int stack_size)
{
	int	i;
	int	temp;

	if (stack_size < 2)
		return ;
	temp = stack[stack_size - 1];
	i = stack_size - 1;
	while (i > 0)
	{
		stack[i] = stack[i - 1];
		i--;
	}
	stack[0] = temp;
}

void	ft_operation_rr(t_push_swap *push_swap, t_mode mode)
{
	int	stack_size;

	stack_size = ft_stack_len(push_swap, mode);
	if (mode == STACK_A)
	{
		ft_rr(push_swap->stack_a, stack_size);
		ft_printf("rra\n");
	}
	else if (mode == STACK_B)
	{
		ft_rr(push_swap->stack_b, stack_size);
		ft_printf("rrb\n");
	}
	else
	{
		ft_rr(push_swap->stack_a, push_swap->stack_a_size);
		ft_rr(push_swap->stack_b, push_swap->stack_b_size);
		ft_printf("rrr\n");
	}
}
