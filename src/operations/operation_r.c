/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_r.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 15:18:07 by lgirard           #+#    #+#             */
/*   Updated: 2025/12/15 15:37:57 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_r(int *stack, int stack_size)
{
	int	i;
	int	temp;

	if (stack_size < 2)
		return ;
	temp = stack[0];
	i = 0;
	while (i < stack_size - 1)
	{
		stack[i] = stack[i + 1];
		i++;
	}
	stack[stack_size - 1] = temp;
}

void	ft_operation_r(t_push_swap *push_swap, t_mode mode)
{
	int	stack_size;

	stack_size = ft_stack_len(push_swap, mode);
	if (mode == STACK_A)
	{
		ft_r(push_swap->stack_a, stack_size);
		ft_printf("ra\n");
	}
	else if (mode == STACK_B)
	{
		ft_r(push_swap->stack_b, stack_size);
		ft_printf("rb\n");
	}
	else
	{
		ft_r(push_swap->stack_a, push_swap->stack_a_size);
		ft_r(push_swap->stack_b, push_swap->stack_b_size);
		ft_printf("rr\n");
	}
}
