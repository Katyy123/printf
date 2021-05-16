/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 16:17:51 by cfiliber          #+#    #+#             */
/*   Updated: 2021/05/16 16:17:55 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_char_padding(int c, t_flg *flg, char to_pr, int *n_ch)
{
	if (--(flg->width) < 0)
		flg->width = 0;
	if (flg->minus)
		put_char(c, n_ch);
	while ((flg->width)--)
	{
		put_char(to_pr, n_ch);
	}
	if (!flg->minus)
		put_char(c, n_ch);
}

void	print_char(t_flg *flg, int c, int *n_ch)
{
	if (flg->zero || flg->precision != -1)
		*n_ch = -1;
	if (flg->width)
		print_char_padding(c, flg, ' ', n_ch);
	else
		put_char(c, n_ch);
}
