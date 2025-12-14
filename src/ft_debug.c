/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debug.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 15:07:50 by rpetit            #+#    #+#             */
/*   Updated: 2025/12/14 10:59:06 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_stacks(t_push_swap *push_swap)
{
	int	i;

	i = 0;
	while (i < push_swap->stack_size)
	{
		ft_printf("%3d	%3d\n", push_swap->stack_a[i], push_swap->stack_b[i]);
		i++;	
	}
	ft_printf("___	___\n a 	 b \n");
}
