/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 17:30:14 by rpetit            #+#    #+#             */
/*   Updated: 2025/12/16 17:11:38 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "types.h"
# include "libft.h"
# include "operations.h"
# include "utils.h"

void	ft_print_stacks(t_push_swap *push_swap);
void	ft_format_input(int size, char **input, t_push_swap *push_swap);
float	ft_disorder(t_push_swap *push_swap);
void	ft_free_push_swap(t_push_swap *push_swap);

void	ft_strategy_selector(t_push_swap *push_swap);
void	ft_strategy_simple(t_push_swap *push_swap);
void	ft_strategy_medium(t_push_swap *push_swap);
void	ft_strategy_complex(t_push_swap *push_swap);

void	ft_print_bench(t_push_swap *push_swap);
void	ft_reset_bench(t_push_swap *push_swap);

#endif
