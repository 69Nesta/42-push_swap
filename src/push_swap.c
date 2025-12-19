/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 09:28:19 by rpetit            #+#    #+#             */
/*   Updated: 2025/12/18 15:20:21 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_push_swap	push_swap;

	ft_format_input(ac - 1, av + 1, &push_swap);
	push_swap.stack_a_size = push_swap.stack_size;
	push_swap.stack_b_size = 0;
	push_swap.bench.disorder = ft_disorder(&push_swap);
	ft_strategy_selector(&push_swap);
	ft_print_bench(&push_swap);
	ft_free_push_swap(&push_swap);
	return (0);
}
