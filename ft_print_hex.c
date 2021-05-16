/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 16:17:27 by cfiliber          #+#    #+#             */
/*   Updated: 2021/05/16 16:17:30 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	prt_hx(t_flg *flg, unsigned int n, const char **in, int *n_ch)
{
	int	n_len;
	int	padding;
	int	zero_p;

	n_len = nbr_hx_len((unsigned long) n);
	zero_p = flg->precision - n_len;
	if (zero_p < 0)
		zero_p = 0;
	padding = flg->width - n_len - zero_p;
	if (padding < 0)
		padding = 0;
	if (n == 0 && flg->only_dot == 1)
		padding = flg->width;
	prt_hx_2(flg, padding, n_ch);
	print_int_padding(n_ch, zero_p, '0');
	if (!(n == 0 && flg->only_dot == 1))
		put_nbr_hx((unsigned long) n, **in, n_ch);
	if (n == 0 && !flg->only_dot)
		put_char('0', n_ch);
	if (flg->minus)
		print_int_padding(n_ch, padding, ' ');
}

void	prt_hx_2(t_flg *flg, int padding, int *n_ch)
{
	if (!flg->minus)
	{
		if (!(flg->precision == -1 && flg->zero))
			print_int_padding(n_ch, padding, ' ');
		else
			print_int_padding(n_ch, padding, '0');
	}
}
