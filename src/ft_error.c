/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirard <lgirard@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 11:12:15 by rpetit            #+#    #+#             */
/*   Updated: 2025/12/19 14:27:19 by lgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error_double(char **tokens, int i, t_push_swap *push_swap)
{
	while (tokens[i])
		free(tokens[i++]);
	free(tokens);
	ft_free_push_swap(push_swap);
	ft_fprintf(STDERR_FILENO, "Error\n");
	exit(1);
}

void	ft_error_input(char **tokens)
{
	ft_free_split(tokens);
	ft_fprintf(STDERR_FILENO, "Error\n");
	exit(1);
}

void	ft_error_malloc(t_push_swap *push_swap)
{
	ft_free_push_swap(push_swap);
	ft_fprintf(STDERR_FILENO, "Error\n");
	exit(1);
}
