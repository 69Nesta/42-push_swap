/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirard <lgirard@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 11:18:37 by lgirard           #+#    #+#             */
/*   Updated: 2025/12/15 07:43:16 by lgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

# include "push_swap.h"

typedef enum e_mode
{
	STACK_A,
	STACK_B,
	BOTH
}	t_mode;

/*
	s
*/

void	ft_s(int *stack);
void	ft_operation_s(t_push_swap *push_swap, t_mode mode);

/*
	p
*/

void	ft_add_top(int *stack, int value, int *stack_size);
void	ft_operation_p(t_push_swap *push_swap, t_mode mode);
void	ft_p(t_push_swap *push_swap, t_mode mode, int *src, int *dest);

/*
	r
*/

void	ft_r(int *stack, int stack_size);
void	ft_operation_r(t_push_swap *push_swap, t_mode mode);

/*
	rr
*/

void	ft_rr(int *stack, int stack_size);
void	ft_operation_rr(t_push_swap *push_swap, t_mode mode);

#endif
