/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 12:41:01 by rpetit            #+#    #+#             */
/*   Updated: 2025/11/07 09:28:21 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_isdigit(int c);
static int	ft_isalpha(int c);

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}

static int	ft_isdigit(int c)
{
	return ((c >= '0' && c <= '9'));
}

static int	ft_isalpha(int c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}
