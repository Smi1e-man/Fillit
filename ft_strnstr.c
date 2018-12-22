/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyakoven <yyakoven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 11:46:22 by yyakoven          #+#    #+#             */
/*   Updated: 2018/10/31 08:32:57 by yyakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hay, const char *needle, size_t len)
{
	char		*str;
	int			i;
	size_t		j;

	j = 0;
	str = NULL;
	i = 0;
	if (needle[0] == '\0')
		str = (char*)hay;
	else
	{
		while (hay[j] && needle[i] && (j + i) < len)
		{
			i = 0;
			while (hay[j + i] && hay[j + i] == needle[i] && (j + i < len))
				i++;
			if (!(needle[i]))
			{
				str = (char *)hay + j;
				break ;
			}
			j++;
		}
	}
	return (str);
}
