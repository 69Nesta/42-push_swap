/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_disorder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 14:20:27 by rpetit            #+#    #+#             */
/*   Updated: 2025/12/15 15:53:34 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float	ft_disorder(t_push_swap *push_swap)
{
	int	i;
	int	j;
	int	mistakes;
	int	total_pairs;

	i = 0;
	j = 0;
	mistakes = 0;
	total_pairs = 0;
	while (i < push_swap->stack_a_size)
	{
		j = i + 1;
		while (j < push_swap->stack_a_size)
		{
			total_pairs++;
			if (push_swap->stack_a[i] > push_swap->stack_a[j])
				mistakes++;
			j++;
		}
		i++;
	}
	return ((float)mistakes / (float)total_pairs);
}
