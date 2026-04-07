/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 09:34:15 by rpetit            #+#    #+#             */
/*   Updated: 2025/11/13 16:36:30 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	l_to_find;

	if (!str && !len)
		return (0);
	i = 0;
	l_to_find = 0;
	while (to_find[l_to_find])
		l_to_find++;
	if (l_to_find == 0)
		return ((char *)str);
	while (str[i] && i + (l_to_find - 1) < len)
	{
		j = 0;
		while (i + j < len && str[i + j] == to_find[j]
			&& str[i + j] && to_find[j])
			j++;
		if (to_find[j] == 0 || i == len)
			return ((char *)str + i);
		i++;
	}
	return (0);
}
