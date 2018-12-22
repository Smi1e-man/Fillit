/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyakoven <yyakoven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 20:28:35 by yyakoven          #+#    #+#             */
/*   Updated: 2018/10/31 10:00:30 by yyakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		j;

	i = 0;
	if (s)
	{
		while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		{
			i++;
		}
		if (s[i] == '\0')
		{
			return (ft_strnew(0));
		}
		j = ft_strlen(s) - 1;
		while ((s[j] == ' ' || s[j] == '\t' || s[j] == '\n') && j)
		{
			j--;
		}
		return (ft_strsub(s, i, j - i + 1));
	}
	return (NULL);
}
