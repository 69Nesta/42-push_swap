/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_in_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirard <lgirard@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 11:01:40 by rpetit            #+#    #+#             */
/*   Updated: 2025/12/19 15:04:28 by lgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_in_stack(int *stack, int size, char *nbr)
{
	int	i;
	int	int_nb;

	i = 0;
	int_nb = ft_atoi(nbr);
	while (i < size)
	{
		if (stack[i] == int_nb)
			return (1);
		i++;
	}
	return (0);
}
