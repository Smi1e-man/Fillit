/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyakoven <yyakoven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 10:48:24 by yyakoven          #+#    #+#             */
/*   Updated: 2018/10/31 07:18:31 by yyakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *haystack, const char *needle)
{
	char		*str;
	int			i;
	int			j;

	j = 0;
	str = NULL;
	if (needle[0] == '\0')
		str = (char*)haystack;
	else
	{
		while (haystack[j])
		{
			i = 0;
			while (haystack[j + i] && haystack[j + i] == needle[i])
				i++;
			if (!(needle[i]))
			{
				str = (char *)haystack + j;
				break ;
			}
			j++;
		}
	}
	return (str);
}
