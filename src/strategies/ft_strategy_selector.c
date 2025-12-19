/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strategy_selector.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 17:22:54 by rpetit            #+#    #+#             */
/*   Updated: 2025/12/17 15:42:43 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_strategy_selector_adaptive(t_push_swap *push_swap);

void	ft_strategy_selector(t_push_swap *push_swap)
{

	if (push_swap->strategy == ADAPTIVE)
		ft_strategy_selector_adaptive(push_swap);
	else if (push_swap->strategy == SIMPLE)
		ft_strategy_simple(push_swap);
	else if (push_swap->strategy == MEDIUM)
	{
		push_swap->bench.final_strategy = MEDIUM;
		ft_strategy_medium(push_swap);
	}
	else if (push_swap->strategy == COMPLEX)
	{
		push_swap->bench.final_strategy = COMPLEX;
		ft_strategy_complex(push_swap);
	}
}

static void	ft_strategy_selector_adaptive(t_push_swap *push_swap)
{
	const float	disorder = ft_disorder(push_swap);

	if (disorder < 0.2)
		ft_strategy_simple(push_swap);
	else if (disorder >= 0.2 && disorder < 0.5)
	{
		push_swap->bench.final_strategy = MEDIUM;
		ft_strategy_medium(push_swap);
	}
	else if (disorder >= 0.5)
	{
		push_swap->bench.final_strategy = COMPLEX;
		ft_strategy_complex(push_swap);
	}
}
