/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_len.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirard <lgirard@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 11:28:42 by lgirard           #+#    #+#             */
/*   Updated: 2025/12/14 12:00:53 by lgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stack_len(t_push_swap *push_swap, t_mode mode)
{
	if (mode == STACK_A)
		return (push_swap->stack_a_size);
	if (mode == STACK_B)
		return (push_swap->stack_b_size);
	return (push_swap->stack_size);
}
