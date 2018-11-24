/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyakoven <yyakoven@sudent.unit.ua>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 14:10:49 by yyakoven          #+#    #+#             */
/*   Updated: 2018/11/24 16:38:50 by yyakoven         ###   ########.fr       */
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
			elem->s[elem->hashes][0] = linenum;
			elem->s[elem->hashes][1] = i;
			elem->hashes++;
		}
		else if (line[i] == '.')
			elem->dots++;
		i++;
	}
	return (i);
}
