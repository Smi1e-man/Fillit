/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyakoven <yyakoven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 16:22:34 by yyakoven          #+#    #+#             */
/*   Updated: 2018/10/31 09:45:22 by yyakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_words(char const *s, char c)
{
	int		count;
	int		i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
		{
			i++;
		}
		if (s[i] != '\0')
		{
			count++;
		}
		while (s[i] != c && s[i])
		{
			i++;
		}
	}
	return (count);
}

static int		ft_len(const char *s, char c, int *a)
{
	int		i;
	int		l;

	i = 0;
	l = 0;
	while (s[i] && s[i] == c)
	{
		i++;
	}
	while (s[i] && s[i] != c)
	{
		i++;
		l++;
	}
	while (s[i] && s[i] == c)
	{
		i++;
	}
	*a += i;
	return (l);
}

static void		ft_set_count(int *i, int *j)
{
	*i = 0;
	*j = 0;
}

char			**ft_strsplit(char const *s, char c)
{
	char	**words;
	int		i;
	int		j;

	ft_set_count(&i, &j);
	words = NULL;
	if (s)
	{
		if ((words = (char **)malloc(sizeof(char *) * (ft_words(s, c) + 1))))
		{
			while (s[i] && ft_words(s, c) > 0)
			{
				while (s[i] && s[i] == c)
					i++;
				words[j] = ft_strsub(s, i, ft_len(&s[i], c, &i));
				j++;
			}
			words[j] = NULL;
		}
	}
	return (words);
}
