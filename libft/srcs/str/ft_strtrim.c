/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 16:30:23 by rpetit            #+#    #+#             */
/*   Updated: 2025/11/14 08:31:44 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isinset(const char c, const char *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	trim_s;

	trim_s = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[trim_s] && ft_isinset(s1[trim_s], set))
		trim_s++;
	i = trim_s;
	while (s1[i])
		i++;
	if (s1[i] == 0 && i > trim_s && i > 0)
		i--;
	while (i > trim_s && ft_isinset(s1[i], set))
		i--;
	return (ft_substr(s1, trim_s, i - trim_s + 1));
}

static int	ft_isinset(const char c, const char *set)
{
	size_t	i;

	i = 0;
	while (set[i] && set[i] != c)
		i++;
	return (set[i] == c);
}
