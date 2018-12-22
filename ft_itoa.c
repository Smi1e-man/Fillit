/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyakoven <yyakoven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 10:38:08 by yyakoven          #+#    #+#             */
/*   Updated: 2018/10/29 13:30:01 by yyakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(unsigned int n)
{
	int				l;

	l = 1;
	while (n > 9)
	{
		n = n / 10;
		l++;
	}
	return (l);
}

static void	ft_neg(int *n, unsigned int *num, int *neg)
{
	if (*n < 0)
	{
		*neg = 1;
		*num = -(*n);
	}
}

char		*ft_itoa(int n)
{
	int				neg;
	unsigned int	l;
	unsigned int	num;
	char			*str;

	num = n;
	neg = 0;
	ft_neg(&n, &num, &neg);
	l = ft_len(num) + neg;
	str = ft_strnew(l);
	if (str)
	{
		l = l - 1;
		if (neg)
			str[0] = '-';
		if (num == 0)
			str[0] = '0';
		while (num > 0)
		{
			str[l] = (num % 10) + '0';
			num = num / 10;
			l--;
		}
	}
	return (str);
}
