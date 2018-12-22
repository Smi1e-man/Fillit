/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyakoven <yyakoven@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 13:56:26 by yyakoven          #+#    #+#             */
/*   Updated: 2018/10/25 14:17:16 by yyakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
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
		}
		i++;
	}
	if (c == '\0')
	{
		str = (char *)s + i;
	}
	return (str);
}
