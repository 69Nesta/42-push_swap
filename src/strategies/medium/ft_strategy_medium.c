/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strategy_medium.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirard <lgirard@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 10:40:33 by rpetit            #+#    #+#             */
/*   Updated: 2025/12/18 10:00:37 by lgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_strategy_medium(t_push_swap *push_swap);
static void	ft_push_to_a(t_push_swap *push_swap, int *sorted_stack, int limit);

void	ft_strategy_medium(t_push_swap *push_swap)
{
	int	index;
	int	chunk;
	int	*sorted_stack;
	int	limit;

	index = 1;
	chunk = ft_sqrt(push_swap->stack_size);
	sorted_stack = ft_dup_and_sort(push_swap, push_swap->stack_a);
	if (!sorted_stack)
		return ;
	while (push_swap->stack_a_size)
	{
		limit = ft_min(chunk * index, push_swap->stack_size - 1);
		if (push_swap->stack_a[0] < sorted_stack[limit]
			|| limit == push_swap->stack_size - 1)
			ft_operation_p(push_swap, STACK_B);
		else
			ft_operation_r(push_swap, STACK_A);
		if (push_swap->stack_b[0] < push_swap->stack_b[1])
			ft_operation_s(push_swap, STACK_B);
		if (push_swap->stack_b_size == limit)
			index++;
	}
	ft_push_to_a(push_swap, sorted_stack, limit);
	free(sorted_stack);
}

static void	ft_push_to_a(t_push_swap *push_swap, int *sorted_stack, int limit)
{
	int	deep;

	while (push_swap->stack_b_size)
	{
		if (push_swap->stack_b[0] == sorted_stack[limit])
		{
			ft_operation_p(push_swap, STACK_A);
			limit--;
		}
		deep = 0;
		while (push_swap->stack_b[0] != sorted_stack[limit] && ++deep)
		{
			ft_operation_r(push_swap, STACK_B);
			if (push_swap->stack_b[0] < push_swap->stack_b[1]
				&& push_swap->stack_b[1] != sorted_stack[limit])
				ft_operation_s(push_swap, STACK_B);
		}
		while (deep--)
		{
			ft_operation_rr(push_swap, STACK_B);
			ft_operation_s(push_swap, STACK_B);
		}
	}
}
