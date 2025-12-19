/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 11:12:15 by rpetit            #+#    #+#             */
/*   Updated: 2025/12/19 11:12:28 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error_double(char **tokens, int i, t_push_swap *push_swap)
{
	while (tokens[i])
		free(tokens[i++]);
	free(tokens);
	free(push_swap->stack_a);
	free(push_swap->stack_b);
	ft_fprintf(STDERR_FILENO, "Error\n");
	exit(1);
}

void	ft_error_input(char **tokens)
{
	ft_free_split(tokens);
	ft_fprintf(STDERR_FILENO, "Error\n");
	exit(1);
}