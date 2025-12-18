/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirard <lgirard@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 11:12:32 by lgirard           #+#    #+#             */
/*   Updated: 2025/12/18 11:26:34 by lgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_s(t_push_swap *push_swap, int *stack, int stack_size, t_mode mode)
{
	int	temp;

	if (stack_size < 2)
		return (1);
	temp = stack[0];
	stack[0] = stack[1];
	stack[1] = temp;
	if (mode == STACK_A)
		push_swap->bench.sa++;
	else if (mode == STACK_B)
		push_swap->bench.sb++;
	return (0);
}

void	ft_operation_s(t_push_swap *push_swap, t_mode mode)
{
	if (mode == STACK_A)
	{
		if (ft_s(push_swap, push_swap->stack_a, push_swap->stack_a_size, mode))
			return ;
		if (PRINT_OPERATION)
			ft_putstr("sa\n");
	}
	else if (mode == STACK_B)
	{
		if (ft_s(push_swap, push_swap->stack_b, push_swap->stack_b_size, mode))
			return ;
		if (PRINT_OPERATION)
			ft_putstr("sb\n");
	}
	else if (mode == BOTH)
	{
		if (push_swap->stack_b_size < 2 || push_swap->stack_a_size < 2)
			return ;
		ft_s(push_swap, push_swap->stack_b, push_swap->stack_b_size, mode);
		ft_s(push_swap, push_swap->stack_a, push_swap->stack_a_size, mode);
		push_swap->bench.ss++;
		if (PRINT_OPERATION)
			ft_putstr("ss\n");
	}
}
