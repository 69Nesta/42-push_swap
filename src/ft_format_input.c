/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_input.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirard <lgirard@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 15:23:55 by rpetit            #+#    #+#             */
/*   Updated: 2025/12/18 10:00:59 by lgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_try_apply_option(char *input, t_push_swap *push_swap);
static int	ft_count_numbers_in_arg(char *arg, t_push_swap *push_swap);
static void	ft_fill_from_arg(int *i_stack, char *arg, t_push_swap *push_swap);

void	ft_format_input(int size, char **input, t_push_swap *push_swap)
{
	int		i;
	int		i_stack;
	int		total_nums;

	i = 0;
	i_stack = 0;
	total_nums = 0;
	push_swap->strategy = ADAPTIVE;
	ft_reset_bench(push_swap);
	while (i < size)
	{
		total_nums += ft_count_numbers_in_arg(input[i], push_swap);
		i++;
	}
	push_swap->stack_a = ft_calloc(sizeof(int), (total_nums));
	push_swap->stack_b = ft_calloc(sizeof(int), (total_nums));
	i = 0;
	while (i < size)
	{
		ft_fill_from_arg(&i_stack, input[i], push_swap);
		i++;
	}
	push_swap->stack_size = i_stack;
	push_swap->stack_a_size = i_stack;
	push_swap->stack_b_size = 0;
}

static int	ft_try_apply_option(char *input, t_push_swap *push_swap)
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
	else
		return (0);
	return (1);
}

static int	ft_count_numbers_in_arg(char *arg, t_push_swap *push_swap)
{
	char	**tokens;
	int		count;
	int		i;

	if (ft_try_apply_option(arg, push_swap))
		return (0);
	tokens = ft_split(arg, ' ');
	if (!tokens)
		return (0);
	count = 0;
	i = 0;
	while (tokens[i])
	{
		if (ft_valid_number(tokens[i]))
			count++;
		else if (ft_try_apply_option(arg, push_swap))
			continue ;
		else
			ft_error_input(tokens);
		i++;
	}
	ft_free_split(tokens);
	return (count);
}

static void	ft_fill_from_arg(int *i_stack, char *arg, t_push_swap *push_swap)
{
	char	**tokens;
	int		i;
	int		number;

	if (ft_try_apply_option(arg, push_swap))
		return ;
	tokens = ft_split(arg, ' ');
	if (!tokens)
		return ;
	i = 0;
	while (tokens[i])
	{
		number = ft_atoi(tokens[i]);
		if (ft_valid_number(tokens[i]) && !ft_is_in_stack(push_swap->stack_a, *i_stack, number))
		{
			push_swap->stack_a[*i_stack] = number;
			(*i_stack)++;
		}
		else
			ft_error_double(tokens, i, push_swap);
		free(tokens[i]);
		i++;
	}
	free(tokens);
}
