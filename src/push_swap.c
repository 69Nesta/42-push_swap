/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirard <lgirard@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 09:28:19 by rpetit            #+#    #+#             */
/*   Updated: 2025/12/18 10:01:02 by lgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_push_swap	push_swap;

	push_swap.stack_a = ft_calloc(sizeof(int), (ac - 1));
	push_swap.stack_b = ft_calloc(sizeof(int), (ac - 1));
	ft_format_input(ac - 1, av + 1, &push_swap);
	ft_print_stacks(&push_swap);
	push_swap.bench.disorder = ft_disorder(&push_swap);

	ft_strategy_selector(&push_swap);

	// ft_printf("\n----------\n\n");
	//ft_print_stacks(&push_swap);
	ft_print_bench(&push_swap);
	ft_free_push_swap(&push_swap);
	//__builtin_printf("\n\n%.2f\n\n", disorder);
}
