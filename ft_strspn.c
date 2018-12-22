/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyakoven <yyakoven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 11:23:26 by yyakoven          #+#    #+#             */
/*   Updated: 2018/10/31 12:16:32 by yyakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strspn(const char *s, const char *charset)
{
	size_t	i;

	i = 0;
	if (s && charset)
	{
		while (s[i])
		{
			if (!(ft_chrstr(s[i], charset)))
			{
				return (i);
			}
			i++;
		}
	}
	return (i);
}
