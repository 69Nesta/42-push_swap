/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 17:10:20 by rpetit            #+#    #+#             */
/*   Updated: 2025/12/17 14:01:28 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format(const char *format, va_list *ap, int fd);
static int	ft_type_selector(t_args *arg, va_list *ap);

int	ft_fprintf(int fd, const char *format, ...)
{
	va_list	ap;
	int		printed_char_count;

	if (!format)
		return (-1);
	va_start(ap, format);
	printed_char_count = ft_format(format, &ap, fd);
	va_end(ap);
	return (printed_char_count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		printed_char_count;

	if (!format)
		return (-1);
	va_start(ap, format);
	printed_char_count = ft_format(format, &ap, 1);
	va_end(ap);
	return (printed_char_count);
}

static int	ft_format(const char *format, va_list *ap, int fd)
{
	int		i;
	int		i_start;
	int		total_printed;
	t_args	arg;

	i = 0;
	total_printed = 0;
	while (format[i] && total_printed >= 0)
	{
		i_start = i;
		while (format[i] && format[i] != '%')
			i++;
		if (i > i_start && format[i_start])
			ft_swrite(&total_printed, ft_write_n(format + i_start,
					i - i_start, fd));
		if (format[i] == '%' && format[i + 1] && total_printed >= 0)
		{
			arg = ft_format_arg(format + ++i);
			arg.fd = fd;
			ft_swrite(&total_printed, ft_type_selector(&arg, ap));
			i += arg.arg_len;
		}
	}
	return (total_printed);
}

static int	ft_type_selector(t_args *arg, va_list *ap)
{
	if (ft_istype_c(arg))
		return (ft_type_c((char)va_arg(*ap, int), arg));
	else if (ft_istype_s(arg))
		return (ft_type_s(va_arg(*ap, char *), arg));
	else if (ft_istype_p(arg))
		return (ft_type_p(va_arg(*ap, unsigned long), arg));
	else if (ft_istype_i(arg))
		return (ft_type_i(va_arg(*ap, int), arg));
	else if (ft_istype_u(arg))
		return (ft_type_u(va_arg(*ap, unsigned int), arg));
	else if (ft_istype_x(arg))
		return (ft_type_x(va_arg(*ap, unsigned int), arg));
	else if (ft_istype_xx(arg))
		return (ft_type_xx(va_arg(*ap, unsigned int), arg));
	else if (ft_istype_mod(arg))
		return (ft_type_mod(arg));
	else if (ft_istype_f(arg))
		return (ft_type_f(va_arg(*ap, double), arg));
	return (0);
}
