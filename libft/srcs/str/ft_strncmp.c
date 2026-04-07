/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 18:19:30 by rpetit            #+#    #+#             */
/*   Updated: 2025/11/13 09:16:17 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t length)
{
	size_t	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && i < length)
		i++;
	if (i < length)
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}
