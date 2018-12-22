/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyakoven <yyakoven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 11:49:36 by yyakoven          #+#    #+#             */
/*   Updated: 2018/10/31 10:41:04 by yyakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*ptrd;
	char	*ptrs;
	int		i;

	ptrd = dst;
	ptrs = (char *)src;
	i = 0;
	if (ptrd > ptrs)
	{
		while (len--)
		{
			*(ptrd + len) = *(ptrs + len);
		}
	}
	else
	{
		while (i < (int)len)
		{
			ptrd[i] = ptrs[i];
			i++;
		}
	}
	return (dst);
}
