/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 15:12:40 by cfiliber          #+#    #+#             */
/*   Updated: 2021/05/16 15:12:49 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_int_padding(int *n_ch, int padding, char to_pr)
{
	while (padding--)
		put_char(to_pr, n_ch);
}

void	print_int_sign(t_flg *flg, int *n_ch)
{
	if (flg->int_sign)
		put_char('-', n_ch);
}

void	set_int_sign(t_flg *flg, int n)
{
	flg->int_sign = n < 0;
}

void	print_int(t_flg *flg, int n, int *n_ch)
{
	int		n_len;
	int		padding;
	int		zero_p;

	set_int_sign(flg, n);
	n_len = nbr_len(n);
	if (n < 0)
		n *= -1;
	zero_p = flg->precision - n_len;
	if (zero_p < 0)
		zero_p = 0;
	padding = flg->width - n_len - zero_p
		-(flg->int_sign);
	if (padding < 0)
		padding = 0;
	if (n == 0 && flg->only_dot == 1)
		padding = flg->width;
	print_int_2(flg, padding, n_ch);
	print_int_padding(n_ch, zero_p, '0');
	if (!(n == 0 && flg->only_dot == 1))
		put_nbr(n, n_ch);
	if (flg->minus)
		print_int_padding(n_ch, padding, ' ');
}

void	print_int_2(t_flg *flg, int padding, int *n_ch)
{
	if (!flg->minus)
	{
		if (!(flg->precision == -1 && flg->zero))
			print_int_padding(n_ch, padding, ' ');
		print_int_sign(flg, n_ch);
		if (flg->precision == -1 && flg->zero)
			print_int_padding(n_ch, padding, '0');
	}
	else
		print_int_sign(flg, n_ch);
}
