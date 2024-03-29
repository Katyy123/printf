/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 16:35:10 by cfiliber          #+#    #+#             */
/*   Updated: 2021/05/16 16:35:14 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_str_txt(t_flg *flg, char *str, int *n_ch)
{
	int		str_len;

	str_len = ft_strlen(str);
	if (flg->precision > -1 && flg->precision < str_len)
		str_len = flg->precision;
	while (str_len--)
		put_str(&str, n_ch);
}

void	print_str_padding(char *str, t_flg *flg, char to_pr, int *n_ch)
{
	int		str_len;

	str_len = ft_strlen(str);
	if (flg->precision > -1 && flg->precision < str_len)
		flg->width -= flg->precision;
	else
		flg->width -= str_len;
	if (flg->width < 0)
		flg->width = 0;
	if (flg->minus)
		print_str_txt(flg, str, n_ch);
	while ((flg->width)--)
		put_char(to_pr, n_ch);
	if (!flg->minus)
		print_str_txt(flg, str, n_ch);
}

void	print_str(t_flg *flg, char *str, int *n_ch)
{
	if (!str)
		str = "(null)";
	if (flg->width)
	{
		if (flg->zero)
			print_str_padding(str, flg, '0', n_ch);
		else
			print_str_padding(str, flg, ' ', n_ch);
	}
	else
		print_str_txt(flg, str, n_ch);
}
