/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_block.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyakoven <yyakoven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 14:10:49 by yyakoven          #+#    #+#             */
/*   Updated: 2018/11/22 14:24:37 by yyakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		add_to_block(t_ttrmn *elem, char *line, int linenum)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '#')
		{
			elem->s[elem->squares][0] = linenum;
			elem->s[elem->squares][1] = i;
			elem->squares++;
		}
		else if (line[i] == '.')
			elem->dots++;
		i++;
	}
	return (i);
}
