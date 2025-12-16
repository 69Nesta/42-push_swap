/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bench.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 14:59:26 by rpetit            #+#    #+#             */
/*   Updated: 2025/12/16 15:05:20 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_bench(t_push_swap *push_swap)
{
	
}

void	ft_reset_bench(t_push_swap *push_swap)
{
	push_swap->bench.sa = 0;
	push_swap->bench.sb = 0;
	push_swap->bench.ss = 0;
	push_swap->bench.pa = 0;
	push_swap->bench.pb = 0;
	push_swap->bench.ra = 0;
	push_swap->bench.rb = 0;
	push_swap->bench.rr = 0;
	push_swap->bench.rra = 0;
	push_swap->bench.rrb = 0;
	push_swap->bench.disorder = 0.0f;
}
