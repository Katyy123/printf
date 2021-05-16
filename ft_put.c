/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 16:09:49 by cfiliber          #+#    #+#             */
/*   Updated: 2021/05/16 16:09:55 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_char(int c, int *n_ch)
{
	write(1, &c, 1);
	(*n_ch)++;
}

void	put_str(char **str, int *n_ch)
{
	write(1, (*str)++, 1);
	(*n_ch)++;
}

void	put_nbr(int n, int *n_ch)
{
	long int		long_n;

	if (n < 0)
		long_n = -(long int)n;
	else
		long_n = n;
	if (long_n > 9)
		put_nbr(long_n / 10, n_ch);
	put_char((long_n % 10) + '0', n_ch);
}

void	put_nbr_u(unsigned int n, int *n_ch)
{
	if (n > 9)
		put_nbr_u(n / 10, n_ch);
	put_char(n % 10 + '0', n_ch);
}

void	put_nbr_hx(unsigned long n, const char in, int *n_ch)
{
	char	n_hx;

	if (n)
	{
		n_hx = "0123456789abcdef" [n % 16];
		if (n_hx >= 'a' && n_hx <= 'f' && in == 'X')
			n_hx -= 32;
		put_nbr_hx((unsigned long) n / 16, in, n_ch);
		put_char(n_hx, n_ch);
	}
}
