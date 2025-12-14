/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 09:28:19 by rpetit            #+#    #+#             */
/*   Updated: 2025/12/14 11:03:38 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_push_swap	push_swap;

	push_swap.stack_a = malloc(sizeof(int) * (ac - 1));
	push_swap.stack_b = malloc(sizeof(int) * (ac - 1));
	ft_format_input(ac, av, &push_swap);
	ft_print_stacks(&push_swap);
	
	// strategy selector

	ft_printf("\n----------\n\n");
	
	ft_print_stacks(&push_swap);

	// free push_swap
}
