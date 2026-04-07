/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 18:24:54 by rpetit            #+#    #+#             */
/*   Updated: 2025/11/13 10:38:07 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && *((const unsigned char *)str + i) != (unsigned char)c)
		i++;
	if (i != n && *((const unsigned char *)str + i) == (unsigned char)c)
		return ((void *)((const unsigned char *)str + i));
	return (0);
}
