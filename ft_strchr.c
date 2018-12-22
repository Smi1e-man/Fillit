/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyakoven <yyakoven@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 12:31:42 by yyakoven          #+#    #+#             */
/*   Updated: 2018/10/25 14:10:37 by yyakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	int		i;

	str = NULL;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			str = (char *)s + i;
			return (str);
		}
		i++;
	}
	if (c == '\0')
	{
		str = (char *)s + i;
	}
	return (str);
}
