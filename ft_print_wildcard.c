/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_wildcard.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 16:16:47 by cfiliber          #+#    #+#             */
/*   Updated: 2021/05/16 16:16:50 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_wildcard(t_flg *flg, int *n_ch)
{
	if (flg->width)
	{
		if (flg->zero)
			print_char_padding('%', flg, '0', n_ch);
		else
			print_char_padding('%', flg, ' ', n_ch);
	}
	else
		put_char('%', n_ch);
}
