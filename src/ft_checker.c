/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirard <lgirard@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 11:06:09 by lgirard           #+#    #+#             */
/*   Updated: 2025/12/17 11:22:06 by lgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_do_instruction(t_push_swap *push_swap, char *instruction)
{
	if (instruction == "sa")
		ft_operation_s(push_swap, STACK_A);
	else if (instruction == "sb")
		ft_operation_s(push_swap, STACK_B);
	else if (instruction == "ss")
		ft_operation_s(push_swap, BOTH);
	else if (instruction == "ra")
		ft_operation_r(push_swap, STACK_A);
	else if (instruction == "rb")
		ft_operation_r(push_swap, STACK_B);
	else if (instruction == "rr")
		ft_operation_r(push_swap, BOTH);
	else if (instruction == "rra")
		ft_operation_rr(push_swap, STACK_A);
	else if (instruction == "rrb")
		ft_operation_rr(push_swap, STACK_B);
	else if (instruction == "rrr")
		ft_operation_r(push_swap, BOTH);
	else if (instruction == "pa")
		ft_operation_p(push_swap, STACK_A);
	else if (instruction == "pb")
		ft_operation_p(push_swap, STACK_B);
	else
		return (1);
	return (0);
}

int main(int ac, char **av)
{
	t_push_swap	push_swap;
	float		disorder;
	char		*line;

	push_swap.stack_a = ft_calloc(sizeof(int), (ac - 1));
	push_swap.stack_b = ft_calloc(sizeof(int), (ac - 1));
	ft_format_input(ac - 1, av + 1, &push_swap);
	line = get_next_line(0);
	while (line != '\n')
	{
		if (ft_do_instruction(&push_swap ,line))
		{
			free(line);
			ft_printf("Error");
			return (1);
		}
		free(line);
		line = get_next_line(0);
	}
	if (ft_disorder(&push_swap) == (float)0)
		ft_printf("OK");
	else
		ft_printf("KO");
	free(line);
	return (0);
}
