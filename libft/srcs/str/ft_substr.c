/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 14:41:26 by rpetit            #+#    #+#             */
/*   Updated: 2025/11/13 16:08:17 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	l;

	i = 0;
	while (s && s[i])
		i++;
	l = 0;
	if (start < i)
	{
		while (s && s[start + l] && l < len)
			l++;
		sub = malloc(sizeof(char) * (l + 1));
	}
	else
		sub = malloc(sizeof(char));
	i = 0;
	while (i < l && sub)
	{
		sub[i] = s[start + i];
		i++;
	}
	if (sub)
		sub[i] = '\0';
	return (sub);
}
