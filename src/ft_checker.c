/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirard <lgirard@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 11:06:09 by lgirard           #+#    #+#             */
/*   Updated: 2025/12/18 11:08:34 by lgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_do_instruction(t_push_swap *push_swap, char *instruction)
{
	if (!ft_strcmp(instruction, "sa\n"))
		ft_operation_s(push_swap, STACK_A);
	else if (!ft_strcmp(instruction, "sb\n"))
		ft_operation_s(push_swap, STACK_B);
	else if (!ft_strcmp(instruction, "ss\n"))
		ft_operation_s(push_swap, BOTH);
	else if (!ft_strcmp(instruction, "ra\n"))
		ft_operation_r(push_swap, STACK_A);
	else if (!ft_strcmp(instruction, "rb\n"))
		ft_operation_r(push_swap, STACK_B);
	else if (!ft_strcmp(instruction, "rr\n"))
		ft_operation_r(push_swap, BOTH);
	else if (!ft_strcmp(instruction, "rra\n"))
		ft_operation_rr(push_swap, STACK_A);
	else if (!ft_strcmp(instruction, "rrb\n"))
		ft_operation_rr(push_swap, STACK_B);
	else if (!ft_strcmp(instruction, "rrr\n"))
		ft_operation_rr(push_swap, BOTH);
	else if (!ft_strcmp(instruction, "pa\n"))
		ft_operation_p(push_swap, STACK_A);
	else if (!ft_strcmp(instruction, "pb\n"))
		ft_operation_p(push_swap, STACK_B);
	else
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	t_push_swap	push_swap;
	char		*line;

	push_swap.stack_a = ft_calloc(sizeof(int), (ac - 1));
	push_swap.stack_b = ft_calloc(sizeof(int), (ac - 1));
	ft_format_input(ac - 1, av + 1, &push_swap);
	line = get_next_line(0);
	while (line && ft_strcmp(line, "\n"))
	{
		if (ft_do_instruction(&push_swap, line))
		{
			free(line);
			ft_printf("Error");
			return (1);
		}
		free(line);
		line = get_next_line(0);
	}
	if (ft_disorder(&push_swap) == (float)0 && !push_swap.stack_b_size)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free(line);
	ft_free_push_swap(&push_swap);
	return (0);
}
