/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 08:02:57 by rpetit            #+#    #+#             */
/*   Updated: 2025/11/14 08:33:54 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*current;
	t_list	*new_lst;
	t_list	*new_elem;
	void	*new_content;

	current = lst;
	new_lst = NULL;
	if (!del || !lst)
		return (NULL);
	while (current)
	{
		new_content = f(current->content);
		new_elem = ft_lstnew(new_content);
		if (!new_elem)
		{
			if (new_content)
				del(new_content);
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		else
			ft_lstadd_back(&new_lst, new_elem);
		current = current->next;
	}
	return (new_lst);
}
