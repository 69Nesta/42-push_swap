/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 09:23:50 by rpetit            #+#    #+#             */
/*   Updated: 2025/11/12 11:14:54 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_itoa_zero(void);
static size_t	ft_get_malloc_size(long n);
static void		ft_itoa_logic(char *result, long n, size_t size);

char	*ft_itoa(int n)
{
	char	*result;
	size_t	size;

	if (n == 0)
		return (ft_itoa_zero());
	size = ft_get_malloc_size(n);
	result = malloc(sizeof(char) * (size + 1));
	if (!result)
		return (NULL);
	ft_itoa_logic(result, n, size);
	return (result);
}

static char	*ft_itoa_zero(void)
{
	char	*result;

	result = malloc(sizeof(char) * 2);
	if (!result)
		return (0);
	result[0] = '0';
	result[1] = '\0';
	return (result);
}

static size_t	ft_get_malloc_size(long n)
{
	size_t	size;

	size = 0;
	while (n != 0)
	{
		if (n < 0)
			n *= -1;
		else
			n /= 10;
		size++;
	}
	return (size);
}

static void	ft_itoa_logic(char *result, long n, size_t size)
{
	size_t	i;

	i = 1;
	if (n < 0)
	{
		result[0] = '-';
		n *= -1;
	}
	while (n != 0)
	{
		result[size - i++] = n % 10 + '0';
		n /= 10;
	}
	result[size] = '\0';
}
