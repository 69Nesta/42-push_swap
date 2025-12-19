/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 15:55:01 by rpetit            #+#    #+#             */
/*   Updated: 2025/12/17 15:37:45 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

typedef enum e_strategy
{
	SIMPLE,
	MEDIUM,
	COMPLEX,
	ADAPTIVE	
}	t_strategy;

typedef struct s_bench
{
	int			sa;
	int			sb;
	int			ss;
	int			pa;
	int			pb;
	int			ra;
	int			rb;
	int			rr;
	int			rra;
	int			rrb;
	int			rrr;
	float		disorder;
	t_strategy	final_strategy;
}	t_bench;

typedef struct s_push_swap
{
	int			*stack_a;
	int			*stack_b;
	int			stack_size;
	int			stack_a_size;
	int			stack_b_size;
	t_strategy	strategy;
	char		bench_mode;
	t_bench		bench;
}	t_push_swap;

#endif