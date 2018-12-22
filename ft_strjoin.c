/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyakoven <yyakoven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 20:12:49 by yyakoven          #+#    #+#             */
/*   Updated: 2018/10/28 12:39:12 by yyakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;

	ptr = NULL;
	if (s1 && s2)
		ptr = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (ptr)
	{
		ptr = ft_strcpy(ptr, s1);
		ptr = ft_strcat(ptr, s2);
	}
	return (ptr);
}
