/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyakoven <yyakoven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 14:09:49 by yyakoven          #+#    #+#             */
/*   Updated: 2018/11/22 18:41:34 by yyakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		add_elem(t_ttrmn **last, char letter)
{
	t_ttrmn		*new;

	new = (t_ttrmn *)malloc(sizeof(t_ttrmn));
	if (new)
	{
		new->letter = letter;
		new->squares = 0;
		new->dots = 0;
		new->next = NULL;
		if (*last)
			(*last)->next = new;
		else
			*last = new;
	}
}

t_ttrmn		*find_elem(t_ttrmn **list, char letter)
{
	t_ttrmn		*elem;

	if (!*list)
	{
		add_elem(list, letter);
	}
	elem = *list;
	while (elem->next)
	{
		if (elem->letter == letter)
			break ;
		elem = elem->next;
	}
	if (elem->letter != letter)
	{
		add_elem(&elem, letter);
		elem = elem->next;
	}
	return (elem);
}

void		lst_del(t_ttrmn **list)
{
	t_ttrmn 	*ptr;

	ptr = *list;
	while(ptr)
	{
		ptr = ptr->next;
		free(*list);
		*list = ptr;
	}
}
