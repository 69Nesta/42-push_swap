/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 14:22:31 by rpetit            #+#    #+#             */
/*   Updated: 2025/11/14 11:22:05 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *string)
{
	size_t	i;
	char	*dup;

	i = 0;
	while (string[i] != 0)
		i++;
	dup = malloc(sizeof(char) * (i + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (string[i] != 0)
	{
		dup[i] = string[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
