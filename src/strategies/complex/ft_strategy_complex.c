/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strategy_complex.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 10:40:33 by rpetit            #+#    #+#             */
/*   Updated: 2025/12/18 15:33:05 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_get_max_stack(int *stack, int size);
static void	ft_radix_sort(t_push_swap *push_swap, int max_bits);

void	ft_strategy_complex(t_push_swap *push_swap)
{
	int	max;
	int	max_bits;

	max = ft_get_max_stack(push_swap->stack_a, push_swap->stack_a_size);
	max_bits = 0;
	while ((max >> max_bits) != 0)
		max_bits++;
	ft_radix_sort(push_swap, max_bits);
}

static void	ft_radix_sort(t_push_swap *push_swap, int max_bits)
{
	int	i;
	int	bit;
	int	stack_size;

	bit = 0;
	stack_size = push_swap->stack_a_size;
	while (bit < max_bits)
	{
		i = 0;
		while (i < stack_size)
		{
			if (((push_swap->stack_a[0] >> bit) & 1) == 0)
				ft_operation_p(push_swap, STACK_B);
			else
				ft_operation_r(push_swap, STACK_A);
			i++;
		}
		while (push_swap->stack_b_size)
			ft_operation_p(push_swap, STACK_A);
		bit++;
	}
}

static int	ft_get_max_stack(int *stack, int size)
{
	int	index;
	int	max_index;

	index = 0;
	max_index = 0;
	while (index < size)
	{
		if (stack[index] > stack[max_index])
			max_index = index;
		index++;
	}
	return (stack[max_index]);
}
