/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyakoven <yyakoven@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 18:44:09 by yyakoven          #+#    #+#             */
/*   Updated: 2018/10/29 10:44:09 by yyakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = NULL;
	if (s)
	{
		ptr = ft_strnew(ft_strlen(s));
		if (ptr)
		{
			while (s[i])
			{
				ptr[i] = f(i, s[i]);
				i++;
			}
			ptr[i] = '\0';
		}
	}
	return (ptr);
}
