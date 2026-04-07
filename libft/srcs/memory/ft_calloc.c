/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 10:58:52 by rpetit            #+#    #+#             */
/*   Updated: 2025/11/06 14:21:39 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	size_t	i;
	void	*ptr;

	i = 0;
	if ((long)nitems * (long)size < 0 || ((long)nitems < 0 && (long)size < 0))
		return (NULL);
	ptr = malloc(nitems * size);
	if (ptr == NULL)
		return (NULL);
	while (i < nitems * size)
	{
		((char *)ptr)[i] = 0;
		i++;
	}
	return ((void *)ptr);
}
