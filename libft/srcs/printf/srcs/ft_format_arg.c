/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 12:35:27 by rpetit            #+#    #+#             */
/*   Updated: 2025/12/16 15:30:12 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_init_arg(t_args *args);
static void	ft_fill_arg(const char *token, int *i, t_args *arg);

t_args	ft_format_arg(const char *token)
{
	t_args	arg;
	int		i;

	i = 0;
	ft_init_arg(&arg);
	while (token[i] && (ft_ischarset(token[i], "-0+. #")
			|| ft_isdigit(token[i])))
	{
		if (token[i] == '.')
			arg.has_precision = 1;
		ft_fill_arg(token, &i, &arg);
		i++;
	}
	if (ft_ischarset(token[i], "cspdiuxX%f"))
		arg.type = token[i++];
	arg.arg_len = i;
	return (arg);
}

static void	ft_init_arg(t_args *args)
{
	args->type = 0;
	args->length = 0;
	args->width = 0;
	args->precision = 0;
	args->left_align = 0;
	args->zero_pad = 0;
	args->show_sign = 0;
	args->space_sign = 0;
	args->alternate_form = 0;
	args->has_precision = 0;
}

static void	ft_fill_arg(const char *token, int *i, t_args *arg)
{
	t_atol	atol;

	if (token[*i] == '-')
		arg->left_align = 1;
	else if (token[*i] == '0')
		arg->zero_pad = 1;
	else if (token[*i] == '+')
		arg->show_sign = 1;
	else if (token[*i] == '#')
		arg->alternate_form = 1;
	else if (token[*i] == '.' && ft_isdigit(token[*i + 1]))
	{
		atol = ft_atol_pf(token + *i + 1);
		arg->precision = atol.value;
		*i += atol.len;
	}
	else if (token[*i] == ' ')
		arg->space_sign = 1;
	else if (ft_isdigit(token[*i]) && token[*i] != '0')
	{
		atol = ft_atol_pf(token + *i);
		arg->width = atol.value;
		*i += atol.len - (atol.len > 0);
	}
}
