/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 18:13:09 by rpetit            #+#    #+#             */
/*   Updated: 2025/11/05 18:18:46 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	while (i > 0 && str[i] != (char)c)
		i--;
	if (str[i] == (char)c)
		return (((char *)(str + i)));
	return (0);
}
