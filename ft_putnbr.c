/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyakoven <yyakoven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 12:05:51 by yyakoven          #+#    #+#             */
/*   Updated: 2018/10/31 09:55:58 by yyakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_printnum(unsigned int n)
{
	if (n <= 9)
	{
		ft_putchar(n + '0');
	}
	else
	{
		ft_printnum(n / 10);
		ft_putchar((n % 10) + '0');
	}
}

void			ft_putnbr(int n)
{
	unsigned int num;

	if (n < 0)
	{
		num = -n;
		ft_putchar('-');
	}
	else
	{
		num = n;
	}
	ft_printnum(num);
}
