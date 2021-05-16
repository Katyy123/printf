/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 15:48:18 by cfiliber          #+#    #+#             */
/*   Updated: 2021/05/16 15:48:21 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	n;

	n = 0;
	while (*s++)
		n++;
	return (n);
}

int	nbr_len(int n)
{
	int	i;

	if (n == -2147483648)
		return (10);
	if (n < 0)
		n *= -1;
	i = 1;
	while (n > 9)
	{
		n /= 10;
		i++;
	}
	return (i);
}

unsigned int	nbr_u_len(unsigned int n)
{
	unsigned int	i;

	i = 1;
	while (n > 9)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int	nbr_hx_len(unsigned long n)
{
	int	n_len;

	n_len = 1;
	while (n >= 16)
	{
		n /= 16;
		n_len++;
	}
	return (n_len);
}
