/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 17:09:06 by rpetit            #+#    #+#             */
/*   Updated: 2025/12/19 11:46:49 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "libft.h"

int		ft_printf(const char *format, ...);
int		ft_fprintf(int fd, const char *format, ...);
int		ft_write_n(const char *s, int n, int fd);

typedef char	t_bool;

typedef struct s_type
{
	int	format;
	int	printed;
}	t_type;

typedef struct s_atol
{
	long	value;
	int		len;
}	t_atol;

typedef struct s_args
{
	char	type;
	int		length;
	int		width;
	int		precision;
	t_bool	has_precision;
	// flags
	t_bool	left_align;
	t_bool	zero_pad;
	t_bool	show_sign;
	t_bool	space_sign;
	t_bool	alternate_form;

	int		arg_len;
	int		fd;
}	t_args;

typedef struct s_printf_values
{
	int				neg;
	int				precision;
	int				printed_len;
	double			absn;
	double			pow10;
	double			rounded;
	unsigned long	frac_part;
	long long		int_part;
}	t_printf_values;

// others
t_atol	ft_atol_pf(const char *nptr);
int		ft_putnbr_r(unsigned int n, const t_args *arg);
int		ft_putnbr_len(unsigned int n, const t_args *arg);
int		ft_putnbr_base_r(unsigned long n, const char *base, int base_len,
			const t_args *arg);
int		ft_putnbr_base_len(unsigned long n, int base_len);

// utils
// int	ft_strlen(const char *str);
int		ft_putchar(char c);
int		ft_putstr(const char *str);
int		ft_putchar_arg(char c, const t_args *arg);
int		ft_ischarset(char c, char *set);
// int	ft_is_num(const char c);
void	ft_swrite(int *count, int write_value);

/* format args */
t_args	ft_format_arg(const char *token);
int		ft_right_align(const t_args *arg, const char fill, int w, int is_null);
int		ft_left_align(const t_args *arg, const char fill, int printed_w);
int		ft_middle_zero(const t_args *arg, const char fill, int printed_w);

/* printf types */
int		ft_type_i(int n, const t_args *arg);
int		ft_istype_i(const t_args *arg);

int		ft_type_c(char c, const t_args *arg);
int		ft_istype_c(const t_args *arg);

int		ft_type_s(const char *string, const t_args *arg);
int		ft_istype_s(const t_args *arg);

int		ft_type_p(unsigned long pointer, const t_args *arg);
int		ft_istype_p(const t_args *arg);

int		ft_type_u(unsigned int n, const t_args *arg);
int		ft_istype_u(const t_args *arg);

int		ft_type_x(unsigned int hex, const t_args *arg);
int		ft_istype_x(const t_args *arg);

int		ft_type_xx(unsigned int hex, const t_args *arg);
int		ft_istype_xx(const t_args *arg);

int		ft_type_mod(const t_args *arg);
int		ft_istype_mod(const t_args *arg);

int		ft_type_f(double n, const t_args *arg);
int		ft_istype_f(const t_args *arg);

#endif