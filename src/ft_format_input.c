/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_input.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 15:23:55 by rpetit            #+#    #+#             */
/*   Updated: 2025/12/17 15:37:17 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_selctor_intput(int *i_stack, char *input,
				t_push_swap *push_swap);

void	ft_format_input(int size, char **input, t_push_swap *push_swap)
{
	int	i;
	int	i_stack;

	i = 0;
	i_stack = 0;
	push_swap->strategy = ADAPTIVE;
	ft_reset_bench(push_swap);
	while (i < size)
	{
		ft_selctor_intput(&i_stack, input[i], push_swap);
		i++;
	}
	push_swap->stack_size = i_stack;
	push_swap->stack_a_size = i_stack;
	push_swap->stack_b_size = 0;
}

static void	ft_selctor_intput(int *i_stack, char *input, t_push_swap *push_swap)
{
	if (ft_strncmp(input, "--simple", 9) == 0)
		push_swap->strategy = SIMPLE;
	else if (ft_strncmp(input, "--medium", 9) == 0)
		push_swap->strategy = MEDIUM;
	else if (ft_strncmp(input, "--complex", 10) == 0)
		push_swap->strategy = COMPLEX;
	else if (ft_strncmp(input, "--adaptive", 11) == 0)
		push_swap->strategy = ADAPTIVE;
	else if (ft_strncmp(input, "--bench", 8) == 0)
		push_swap->bench_mode = 1;
	else if (ft_valid_number(input))
	{
		push_swap->stack_a[*i_stack] = ft_atoi(input);
		(*i_stack)++;
	}
}
