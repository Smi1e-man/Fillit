/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seshevch <seshevch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 14:10:49 by yyakoven          #+#    #+#             */
/*   Updated: 2018/11/25 15:03:39 by seshevch         ###   ########.fr       */
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
			if (elem->h < 4)
			{
				elem->xy[elem->h][0] = linenum;
				elem->xy[elem->h][1] = i;
			}
			elem->h++;
		}
		else if (line[i] == '.')
			elem->dots++;
		i++;
	}
	return (i);
}
