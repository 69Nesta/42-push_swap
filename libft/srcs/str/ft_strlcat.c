/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 17:18:39 by rpetit            #+#    #+#             */
/*   Updated: 2025/11/13 15:49:57 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dest && dest[i])
		i++;
	if (size > 0)
	{
		while (src[j] && i + j < size - 1)
		{
			dest[j + i] = src[j];
			j++;
		}
		dest[j + i] = '\0';
	}
	while (src && src[j] != '\0')
		j++;
	if (i > size)
		return (size + j);
	return (j + i);
}
