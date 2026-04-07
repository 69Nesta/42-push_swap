/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 14:34:09 by rpetit            #+#    #+#             */
/*   Updated: 2025/11/14 12:16:44 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*current;
	t_list	*to_del;

	if (!lst || !del)
		return ;
	current = *lst;
	while (current)
	{
		to_del = current;
		current = to_del->next;
		del(to_del->content);
		free(to_del);
	}
	*lst = NULL;
}
