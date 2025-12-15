/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strategy_selector.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 17:22:54 by rpetit            #+#    #+#             */
/*   Updated: 2025/12/15 17:31:06 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_strategy_selector(t_push_swap *push_swap)
{
	const float	disorder = ft_disorder(push_swap);

	if (push_swap->strategy == ADAPTIVE)
	{
		if (disorder < 0.2)
			ft_strategy_simple(push_swap);
		else if (disorder >= 0.2 && disorder < 0.5)
			ft_strategy_medium(push_swap);
		else if (disorder >= 0.5)
			ft_strategy_medium(push_swap);
	}
	else if (push_swap->strategy == SIMPLE)
		ft_strategy_simple(push_swap);
	else if (push_swap->strategy == MEDIUM)
		ft_strategy_medium(push_swap);
	else if (push_swap->strategy == COMPLEX)
		ft_strategy_medium(push_swap);
	//else
	//	error();		
}
