/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bench.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 14:59:26 by rpetit            #+#    #+#             */
/*   Updated: 2025/12/17 15:36:41 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_bench_total_ops(t_bench b);
static char	*ft_bench_get_strategy_name(t_push_swap *push_swap);

void	ft_print_bench(t_push_swap *push_swap)
{
	if (!push_swap->bench_mode)
		return ;
	ft_fprintf(STDERR_FILENO,
		"[Bench] disorder: %.2f%%\n", push_swap->bench.disorder * 100);
	ft_fprintf(STDERR_FILENO,
		"[Bench] strategy: %s\n", ft_bench_get_strategy_name(push_swap));
	ft_fprintf(STDERR_FILENO,
		"[Bench] total_ops: %d\n", ft_bench_total_ops(push_swap->bench));
	ft_fprintf(STDERR_FILENO,
		"[Bench] ");
	ft_fprintf(STDERR_FILENO,
		"sa : % 4d sb : % 4d ss : % 4d ", push_swap->bench.sa,
		push_swap->bench.sb, push_swap->bench.ss);
	ft_fprintf(STDERR_FILENO,
		" pa : % 4d  pb : % 4d\n", push_swap->bench.pa,
		push_swap->bench.pb);
	ft_fprintf(STDERR_FILENO,
		"[Bench] ");
	ft_fprintf(STDERR_FILENO,
		"ra : % 4d rb : % 4d rr : % 4d ", push_swap->bench.ra,
		push_swap->bench.rb, push_swap->bench.rr);
	ft_fprintf(STDERR_FILENO,
		"rra : % 4d rrb : % 4d rrr : % 4d\n", push_swap->bench.rra,
		push_swap->bench.rrb, push_swap->bench.rrr);
}

static int	ft_bench_total_ops(t_bench b)
{
	return (b.sa + b.sb + b.ss + b.pa + b.pb + b.ra + b.rb + b.rr
		+ b.rra + b.rrb + b.rrr);
}

static char	*ft_bench_get_strategy_name(t_push_swap *push_swap)
{
	if (push_swap->strategy == SIMPLE)
		return ("Simple");
	else if (push_swap->strategy == MEDIUM)
		return ("Medium");
	else if (push_swap->strategy == COMPLEX)
		return ("Complex");
	else if (push_swap->strategy == ADAPTIVE)
	{
		if (push_swap->bench.final_strategy == SIMPLE)
			return ("Adaptive (simple)");
		else if (push_swap->bench.final_strategy == MEDIUM)
			return ("Adaptive (medium)");
		else if (push_swap->bench.final_strategy == COMPLEX)
			return ("Adaptive (complex)");
	}
	return ("unknown");
}

void	ft_reset_bench(t_push_swap *push_swap)
{
	push_swap->bench_mode = 0;
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
	push_swap->bench.rrr = 0;
	push_swap->bench.disorder = 0.0f;
}
