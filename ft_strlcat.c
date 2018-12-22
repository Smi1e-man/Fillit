/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyakoven <yyakoven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 15:15:32 by yyakoven          #+#    #+#             */
/*   Updated: 2018/10/31 10:38:11 by yyakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t destlen;
	size_t srclen;

	destlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (destlen < dstsize)
	{
		ft_strncat(dst, src, dstsize - destlen - 1);
	}
	else
	{
		destlen = dstsize;
	}
	return (destlen + srclen);
}
