/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 18:24:33 by cfiliber          #+#    #+#             */
/*   Updated: 2021/11/11 16:18:51 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_arg(const char **in, t_flg flg, va_list ap, int *n_ch)
{
	if (**in == 'c')
		print_char(&flg, va_arg(ap, int), n_ch);
	else if (**in == 's')
		print_str(&flg, va_arg(ap, char *), n_ch);
	else if (**in == 'p')
		print_ptr(&flg, va_arg(ap, void *), n_ch);
	else if (**in == 'd' || **in == 'i')
		print_int(&flg, va_arg(ap, int), n_ch);
	else if (**in == 'u')
		print_unsigned(&flg, va_arg(ap, unsigned int), n_ch);
	else if (**in == 'x' || **in == 'X')
		prt_hx(&flg, va_arg(ap, unsigned int), in, n_ch);
	else if (**in == '%')
		print_wildcard(&flg, n_ch);
	else
		*n_ch = -1;
	(*in)++;
}

void	init_flg(t_flg *flg)
{
	flg->zero = 0;
	flg->minus = 0;
	flg->int_sign = 0;
	flg->width = 0;
	flg->precision = -1;
	flg->only_dot = 0;
}

void	set_flg(const char **in, t_flg *flg, va_list ap)
{
	init_flg(flg);
	while (**in == '0' || **in == '-' )
	{
		if (**in == '0')
			set_zero(flg);
		if (**in == '-')
			set_minus(flg);
		(*in)++;
	}
	if (**in == '*' || (**in > '0' && **in <= '9'))
		set_width(in, flg, ap);
	if (**in == '.')
		set_precision(in, flg, ap);
}

void	print_in(const char **in, va_list ap, int *n_ch)
{
	t_flg	flg;

	while (**in)
	{
		if (**in == '%')
		{
			(*in)++;
			set_flg(in, &flg, ap);
			print_arg(in, flg, ap, n_ch);
			if (*n_ch == -1)
				return ;
		}
		else
			put_str((char **)in, n_ch);
	}
}

int	ft_printf(const char *in, ...)
{
	va_list	ap;
	int		n_ch;

	if (!in)
		return (-1);
	n_ch = 0;
	va_start(ap, in);
	print_in(&in, ap, &n_ch);
	va_end(ap);
	return (n_ch);
}

int main(void)//il main non c'era
{
	printf("Number of bytes printed (d) : %d\n", ft_printf("test d : %d %d %d. Ok.\n", 23, +2147483647, -2147483648));
    printf("Number of bytes printed (x): %d\n", ft_printf("test x : %x %x %x.\n", 35467, -2147483648, +2147483647));
    printf("Number of bytes printed (s): %d\n", ft_printf("test s : %s\n", "Hello World"));
	printf("Number of bytes printed (s): %d\n", ft_printf(""));
	printf("Number of bytes printed (s): %d\n", ft_printf("%"));
	return (0);
}