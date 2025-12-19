/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirard <lgirard@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 11:35:29 by lgirard           #+#    #+#             */
/*   Updated: 2025/12/16 16:54:16 by lgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "push_swap.h"

int	ft_sqrt(int nb);
int	ft_min(int a, int b);
int	ft_stack_len(t_push_swap *push_swap, t_mode mode);
int	*ft_dup_and_sort(t_push_swap *push_swap, int *stack);

#endif