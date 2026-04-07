/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 11:16:31 by rpetit            #+#    #+#             */
/*   Updated: 2025/11/13 16:11:48 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*result;

	i = 0;
	if (!s)
		return (NULL);
	result = malloc(sizeof(char) * (ft_strlen(s) + 1));
	while (s[i] && result)
	{
		result[i] = f(i, s[i]);
		i++;
	}
	if (result)
		result[i] = '\0';
	return (result);
}
