/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seshevch <seshevch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 11:59:04 by yyakoven          #+#    #+#             */
/*   Updated: 2018/11/29 16:57:48 by seshevch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	unsigned char	*ptr;
	int				f;
	int				total;

	ptr = (unsigned char *)str;
	f = 1;
	total = 0;
	while ((*ptr >= 9 && *ptr <= 13) || *ptr == ' ')
		ptr++;
	if (*ptr == '+' || *ptr == '-')
	{
		if (*ptr == '-')
			f = -1;
		ptr++;
	}
	while (*ptr >= 48 && *ptr <= 57)
	{
		total = total * 10 + (*ptr - '0');
		ptr++;
	}
	return (total * f);
}
