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

static void	ft_normalize_stack(t_push_swap *push_swap);
static void	ft_radix_sort(t_push_swap *push_swap, int max_bits);

void	ft_strategy_complex(t_push_swap *push_swap)
{
	int	max_bits;

	ft_normalize_stack(push_swap);
	max_bits = 0;
	if (push_swap->stack_a_size > 0)
	{
		int max = push_swap->stack_a_size - 1;
		while ((max >> max_bits) != 0)
			max_bits++;
	}
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

static void	ft_normalize_stack(t_push_swap *push_swap)
{
	int	*n_sorted;
	int	i;
	int	j;

	if (push_swap->stack_a_size <= 1)
		return ;
	n_sorted = ft_dup_and_sort(push_swap, push_swap->stack_a);
	if (!n_sorted)
		return ;
	i = 0;
	while (i < push_swap->stack_a_size)
	{
		j = 0;
		while (j < push_swap->stack_a_size)
		{
			if (push_swap->stack_a[i] == n_sorted[j])
			{
				push_swap->stack_a[i] = j;
				break ;
			}
			j++;
		}
		i++;
	}
	free(n_sorted);
}
