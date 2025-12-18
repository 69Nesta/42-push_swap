/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_input.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirard <lgirard@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 15:23:55 by rpetit            #+#    #+#             */
/*   Updated: 2025/12/17 12:54:14 by lgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_format_input(int size, char **input, t_push_swap *push_swap)
{
	int	i;
	int	i_stack;

	i = 0;
	i_stack = 0;
	while (i < size)
	{
		if (ft_strncmp(input[i], "--simple", 9) == 0)
			push_swap->strategy = SIMPLE;
		else if (ft_strncmp(input[i], "--medium", 9) == 0)
			push_swap->strategy = MEDIUM;
		else if (ft_strncmp(input[i], "--complex", 10) == 0)
			push_swap->strategy = COMPLEX;
		else if (ft_strncmp(input[i], "--adaptive", 11) == 0)
			push_swap->strategy = ADAPTIVE;
		else if (ft_strncmp(input[i], "--bench", 8) == 0)
			push_swap->bench_mode = 1;
		else if (ft_valid_number(input[i]))	
		{
			push_swap->stack_a[i_stack] = ft_atoi(input[i]);
			i_stack++;
		}
		i++;
	}
	push_swap->stack_size = i_stack;
	push_swap->stack_a_size = i_stack;
	push_swap->stack_b_size = 0;
}
