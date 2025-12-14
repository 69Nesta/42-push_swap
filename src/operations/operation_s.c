/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirard <lgirard@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 11:12:32 by lgirard           #+#    #+#             */
/*   Updated: 2025/12/14 12:14:39 by lgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_s(int *stack)
{
	int	temp;

	temp = stack[0];
	stack[0] = stack[1];
	stack[1] = temp;
}

void	ft_operation_s(t_push_swap *push_swap, t_mode mode)
{
	if (mode == STACK_A)
	{
		if (push_swap->stack_a_size < 2)
			return ;
		ft_s(push_swap->stack_a);
		ft_putstr("sa\n");
	}
	else if (mode == STACK_B)
	{
		if (push_swap->stack_b_size < 2)
			return ;
		ft_s(push_swap->stack_b);
		ft_putstr("sb\n");
	}
	else if (mode == BOTH)
	{
		if (push_swap->stack_b_size < 2 || push_swap->stack_a_size < 2)
			return ;
		ft_s(push_swap->stack_b);
		ft_s(push_swap->stack_a);
		ft_putstr("ss\n");
	}
}
