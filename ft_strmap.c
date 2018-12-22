/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyakoven <yyakoven@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 18:22:47 by yyakoven          #+#    #+#             */
/*   Updated: 2018/10/27 18:43:44 by yyakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
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
				ptr[i] = f(s[i]);
				i++;
			}
			ptr[i] = '\0';
		}
	}
	return (ptr);
}
