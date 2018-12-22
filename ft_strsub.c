/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyakoven <yyakoven@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 19:50:43 by yyakoven          #+#    #+#             */
/*   Updated: 2018/10/27 20:11:04 by yyakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*ptr;

	ptr = NULL;
	ptr = ft_strnew(len);
	if (ptr && s)
	{
		ft_strncpy(ptr, (char *)s + start, len);
	}
	return (ptr);
}
