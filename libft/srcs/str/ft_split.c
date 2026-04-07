/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 08:55:59 by rpetit            #+#    #+#             */
/*   Updated: 2025/11/13 16:10:57 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_malloc_array(const char *str, char c, char ***array);
static size_t	ft_malloc_token(const char *str, char c, char **array);
static char		**ft_free_on_fail(char **array, size_t i);

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	i_str;
	char	**array;
	size_t	array_size;

	i = 0;
	i_str = 0;
	if (!s)
		return (NULL);
	array_size = ft_malloc_array(s, c, &array);
	while (i < array_size && array)
	{
		i_str += ft_malloc_token(s + i_str, c, array + i);
		if (!array[i])
			return (ft_free_on_fail(array, i));
		i++;
	}
	if (array)
		array[i] = NULL;
	return (array);
}

static size_t	ft_malloc_array(const char *str, char c, char ***array)
{
	size_t	i;
	size_t	last_index;
	size_t	count;

	i = 0;
	last_index = -1;
	count = 0;
	while (str[i])
	{
		while (str[i] == c && str[i])
			i++;
		last_index = i;
		while (str[i] != c && str[i])
			i++;
		if (last_index != i)
			count++;
	}
	*array = malloc(sizeof(char *) * (count + 1));
	return (count);
}

static size_t	ft_malloc_token(const char *str, char c, char **array)
{
	size_t	i;
	size_t	last_index;

	i = 0;
	while (str[i] == c && str[i])
		i++;
	last_index = i;
	while (str[i] != c && str[i])
		i++;
	if (last_index != i)
	{
		*array = malloc(sizeof(char) * (i - last_index + 1));
		i = last_index;
		while (str[i] != c && str[i] && *array)
		{
			(*array)[i - last_index] = str[i];
			i++;
		}
		if (*array)
			(*array)[i - last_index] = '\0';
	}
	return (i);
}

static char	**ft_free_on_fail(char **array, size_t i)
{
	while (i > 0)
	{
		free(array[i]);
		i--;
	}
	free(array[i]);
	free(array);
	return (0);
}
