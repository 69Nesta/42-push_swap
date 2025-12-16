/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strategy_complex.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirard <lgirard@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 10:40:33 by rpetit            #+#    #+#             */
/*   Updated: 2025/12/16 15:20:04 by lgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_repeat_func(int count, t_push_swap *push_swap,
				void (*f)(t_push_swap *, t_mode), t_mode mode);
static void	ft_medium_create_block(t_push_swap *push_swap);
static int	get_max_index(int *stack, int size);

void	ft_strategy_complex(t_push_swap *push_swap)
{
	int	max_index;

	ft_medium_create_block(push_swap);
	while (push_swap->stack_b_size)
	{
		max_index = get_max_index(push_swap->stack_b, push_swap->stack_b_size);
		if (max_index <= push_swap->stack_b_size / 2)
			ft_repeat_func(max_index, push_swap, ft_operation_r, STACK_B);
		else
			ft_repeat_func(push_swap->stack_b_size - max_index, push_swap,
				ft_operation_rr, STACK_B);
		ft_operation_p(push_swap, STACK_A);
	}
}

static void	ft_medium_create_block(t_push_swap *push_swap)
{
	int	count_pushed;
	int	block_size;
	int	current_block_max;

	count_pushed = 0;
	block_size = 3;
	current_block_max = 0;
	while (push_swap->stack_a_size)
	{
		if (push_swap->stack_a[0] <= current_block_max)
		{
			ft_operation_p(push_swap, STACK_B);
			if (push_swap->stack_b[0] < current_block_max - block_size / 2)
				ft_operation_r(push_swap, STACK_B);
		}
		else
			ft_operation_r(push_swap, STACK_A);
		if (count_pushed == block_size)
		{
			count_pushed = 0;
			current_block_max += block_size;
		}
		count_pushed++;
	}
}

static int	get_max_index(int *stack, int size)
{
	int	index;
	int	max_index;

	index = 0;
	max_index = 0;
	while (index < size)
	{
		if (stack[max_index] < stack[index])
			max_index = index;
		index++;
	}
	return (max_index);
}

static void	ft_repeat_func(int count, t_push_swap *push_swap,
				void (*f)(t_push_swap *, t_mode), t_mode mode)
{
	int	i;

	i = 0;
	while (i < count)
	{
		f(push_swap, mode);
		i++;
	}
}
