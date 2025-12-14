/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 17:30:14 by rpetit            #+#    #+#             */
/*   Updated: 2025/12/14 11:13:07 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef enum e_strategy
{
	SIMPLE,
	MEDIUM,
	COMPLEX,
	ADAPTIVE	
}	t_strategy;

typedef struct s_push_swap
{
	int			*stack_a;
	int			*stack_b;
	int			stack_size;
	t_strategy	strategy;
}	t_push_swap;

void	ft_print_stacks(t_push_swap *push_swap);
void	ft_format_input(int size, char **input, t_push_swap *push_swap);
void	ft_free_push_swap(t_push_swap *push_swap);

#endif
