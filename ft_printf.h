/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 19:09:30 by cfiliber          #+#    #+#             */
/*   Updated: 2021/11/11 13:25:49 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_flg
{
	int	zero;
	int	minus;
	int	int_sign;
	int	width;
	int	precision;
	int	only_dot;
}				t_flg;

int				main(void);//il main non c'era

void			print_arg(const char **in, t_flg flg, va_list ap, int *n_ch);
void			init_flg(t_flg *flg);
void			set_flg(const char **in, t_flg *flg, va_list ap);
void			print_in(const char **in, va_list ap, int *n_ch);
int				ft_printf(const char *in, ...);

void			set_zero(t_flg *flg);
void			set_minus(t_flg *flg);
void			set_width(const char **in, t_flg *flg, va_list ap);
void			set_precision(const char **in, t_flg *flg, va_list ap);
void			set_only_dot(t_flg *flg);

void			print_char_padding(int c, t_flg *flg, char to_pr, int *n_ch);
void			print_char(t_flg *flg, int c, int *n_ch);

void			print_str_padding(char *str, t_flg *flg, char to_pr, int *n_ch);
void			print_str_txt(t_flg *flg, char *str, int *n_ch);
void			print_str(t_flg *flg, char *str, int *n_ch);

void			print_int_padding(int *n_ch, int padding, char to_pr);
void			print_int_sign(t_flg *flg, int *n_ch);
void			set_int_sign(t_flg *flg, int n);
void			print_int(t_flg *flg, int n, int *n_ch);
void			print_int_2(t_flg *flg, int padding, int *n_ch);

void			print_unsigned(t_flg *flg, unsigned int n, int *n_ch);
void			print_unsigned_2(t_flg *flg, int padding, int *n_ch);

void			prt_hx(t_flg *flg, unsigned int n, const char **in, int *n_ch);
void			prt_hx_2(t_flg *flg, int padding, int *n_ch);

void			print_ptr(t_flg *flg, void *ptr, int *n_ch);

void			print_wildcard(t_flg *flg, int *n_ch);

size_t			ft_strlen(const char *s);
int				nbr_len(int n);
unsigned int	nbr_u_len(unsigned int n);
int				nbr_hx_len(unsigned long n);

void			put_char(int c, int *n_ch);
void			put_str(char **str, int *n_ch);
void			put_nbr(int n, int *n_ch);
void			put_nbr_u(unsigned int n, int *n_ch);
void			put_nbr_hx(unsigned long n, const char in, int *n_ch);

#endif
