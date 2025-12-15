/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 11:24:03 by lgirard           #+#    #+#             */
/*   Updated: 2025/12/15 15:37:12 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_add_top(int *stack, int value, int *stack_size)
{
	int	i;

	i = *stack_size;
	while (i > 0)
	{
		stack[i] = stack[i - 1];
		i--;
	}
	stack[0] = value;
	*stack_size += 1;
}

void	ft_del_top(int *stack, int *stack_size)
{
	int	i;

	i = 0;
	while (i < *stack_size - 1)
	{
		stack[i] = stack[i + 1];
		i++;
	}
	stack[*stack_size - 1] = 0;
	*stack_size -= 1;
}

void	ft_p(t_push_swap *push_swap, t_mode mode, int *src, int *dest)
{
	if (ft_stack_len(push_swap, mode) < 1)
		return ;
	if (mode == STACK_A)
	{
		ft_add_top(dest, src[0], &push_swap->stack_b_size);
		ft_del_top(src, &push_swap->stack_a_size);
	}
	else if (mode == STACK_B)
	{
		ft_add_top(dest, src[0], &push_swap->stack_a_size);
		ft_del_top(src, &push_swap->stack_b_size);
	}
}

void	ft_operation_p(t_push_swap *push_swap, t_mode mode)
{
	if (push_swap->stack_size < 1)
		return ;
	if (mode == STACK_A)
	{
		ft_p(push_swap, STACK_B, push_swap->stack_b, push_swap->stack_a);
		ft_putstr("pa\n");
	}
	else if (mode == STACK_B)
	{
		ft_p(push_swap, STACK_A, push_swap->stack_a, push_swap->stack_b);
		ft_putstr("pb\n");
	}
}
