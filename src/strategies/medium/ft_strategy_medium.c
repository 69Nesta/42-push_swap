/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strategy_medium.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirard <lgirard@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 10:40:33 by rpetit            #+#    #+#             */
/*   Updated: 2025/12/16 16:54:36 by lgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(int *tab, int size, int start)
{
	int	i;
	int	temp;

	i = 0;
	while (i < size - start)
	{
		if (tab[start] > tab[size - 1 - i])
		{
			temp = tab[start];
			tab[start] = tab[size - 1 - i];
			tab[size - 1 - i] = temp;
		}
		i++;
	}
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	count;

	count = 0;
	while (count < size)
	{
		sort(tab, size, count);
		count++;
	}
}

int	*ft_dup_and_sort(t_push_swap *push_swap, int *stack)
{
	int	*sorted_stack;
	int	i;

	sorted_stack = malloc (push_swap->stack_size * sizeof(int));
	if (!sorted_stack)
		return (NULL);
	i = 0;
	while (i < push_swap->stack_size)
	{
		sorted_stack[i] = stack[i];
		i++;
	}
	ft_sort_int_tab(sorted_stack, i);
	return (sorted_stack);
}

void	ft_push_to_a(t_push_swap *push_swap, int *sorted_stack, int limit)
{
	int	deep;

	while (push_swap->stack_b_size)
	{
		if (push_swap->stack_b[0] == sorted_stack[limit])
		{
			ft_operation_p(push_swap, STACK_A);
			limit--;
		}
		else
		{
			deep = 0;
			while (push_swap->stack_b[0] != sorted_stack[limit])
			{
				ft_operation_r(push_swap, STACK_B);
				deep++;
			}
			while (deep--)
			{
				ft_operation_rr(push_swap, STACK_B);
				ft_operation_s(push_swap, STACK_B);
			}
		}
	}
	free(sorted_stack);
}

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
}
