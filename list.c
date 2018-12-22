/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seshevch <seshevch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 14:09:49 by yyakoven          #+#    #+#             */
/*   Updated: 2018/11/28 17:13:36 by seshevch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_ttrmn		*add_elem(t_ttrmn **lst, char letter)
{
	t_ttrmn		*new;
	t_ttrmn		*ptr;

	ptr = *lst;
	new = (t_ttrmn *)malloc(sizeof(t_ttrmn));
	if (new)
	{
		new->letter = letter;
		new->h = 0;
		new->dots = 0;
		new->i1 = 0;
		new->k1 = 0;
		new->next = NULL;
		if (!*lst)
			(*lst) = new;
		else
		{
			while (ptr->next)
				ptr = ptr->next;
			ptr->next = new;
		}
	}
	return (new);
}

void		lst_del(t_ttrmn **lst)
{
	t_ttrmn		*ptr;

	if (lst)
	{
		ptr = *lst;
		while (ptr)
		{
			ptr = ptr->next;
			free(*lst);
			*lst = ptr;
		}
	}
}

int			add_to_block(t_ttrmn *elem, char *line, int linenum)
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
