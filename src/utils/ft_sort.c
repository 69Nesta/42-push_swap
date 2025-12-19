/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirard <lgirard@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 13:15:11 by lgirard           #+#    #+#             */
/*   Updated: 2025/12/19 13:17:12 by lgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort(int *tab, int size, int start);
static void	ft_sort_int_tab(int *tab, int size);
int			*ft_dup_and_sort(t_push_swap *push_swap, int *stack);

\
static void	sort(int *tab, int size, int start)
{
	int	i;
	int	temp;

	i = 0;
	while (i < size - start)
	{
		if (tab[start] > tab[size - 1 - i])
		{
			temp = tab[start];
			tab[start] = tab[size - 1 - i];
			tab[size - 1 - i] = temp;
		}
		i++;
	}
}

static void	ft_sort_int_tab(int *tab, int size)
{
	int	count;

	count = 0;
	while (count < size)
	{
		sort(tab, size, count);
		count++;
	}
}

int	*ft_dup_and_sort(t_push_swap *push_swap, int *stack)
{
	int	*sorted_stack;
	int	i;

	sorted_stack = malloc (push_swap->stack_size * sizeof(int));
	if (!sorted_stack)
		return (NULL);
	i = 0;
	while (i < push_swap->stack_size)
	{
		sorted_stack[i] = stack[i];
		i++;
	}
	ft_sort_int_tab(sorted_stack, i);
	return (sorted_stack);
}
