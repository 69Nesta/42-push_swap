/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 09:15:45 by rpetit            #+#    #+#             */
/*   Updated: 2025/11/13 10:46:50 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n
		&& *((unsigned char *) s1 + i) == *((unsigned char *) s2 + i))
		i++;
	if (i < n)
		return ((int)(*((unsigned char *) s1 + i)
			- *((unsigned char *) s2 + i)));
	return (0);
}
