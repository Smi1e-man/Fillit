/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyakoven <yyakoven@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 13:07:07 by yyakoven          #+#    #+#             */
/*   Updated: 2018/10/29 13:18:22 by yyakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_printnum_fd(unsigned int n, int fd)
{
	if (n <= 9)
	{
		ft_putchar_fd((n + '0'), fd);
	}
	else
	{
		ft_printnum_fd((n / 10), fd);
		ft_putchar_fd(((n % 10) + '0'), fd);
	}
}

void		ft_putnbr_fd(int n, int fd)
{
	unsigned int	num;

	if (fd != -1)
	{
		if (n < 0)
		{
			num = -n;
			ft_putchar_fd('-', fd);
		}
		else
		{
			num = n;
		}
		ft_printnum_fd(num, fd);
	}
}
