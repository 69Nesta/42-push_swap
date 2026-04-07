/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdouble.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 16:19:42 by rpetit            #+#    #+#             */
/*   Updated: 2025/12/17 15:29:30 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_print_double(char *buf, unsigned long frac_part, int frac_len,
				t_args *arg);

int	ft_putnbr_double(long long int_part, unsigned long frac_part, int frac_len,
		int fd)
{
	int		count;
	char	buf[64];
	int		i;
	t_args	arg;

	count = 0;
	i = 0;
	arg.fd = fd;
	if (int_part == 0)
		count += ft_putchar_arg('0', &arg);
	else
	{
		while (int_part > 0 && i < (int) sizeof(buf) - 1)
		{
			buf[i++] = '0' + (int_part % 10);
			int_part /= 10;
		}
		while (i-- > 0)
			count += ft_putchar_arg(buf[i], &arg);
	}
	count += ft_print_double(buf, frac_part, frac_len, &arg);
	return (count);
}

static int	ft_print_double(char *buf, unsigned long frac_part, int frac_len,
				t_args *arg)
{
	int	j;
	int	count;

	count = 0;
	if (frac_len > 0)
	{
		count += ft_putchar_arg('.', arg);
		j = frac_len - 1;
		buf[frac_len] = '\0';
		while (j >= 0)
		{
			buf[j] = '0' + (frac_part % 10);
			frac_part /= 10;
			j--;
		}
		count += ft_write_n(buf, frac_len, arg->fd);
	}
	return (count);
}
