/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seshevch <seshevch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 14:09:49 by yyakoven          #+#    #+#             */
/*   Updated: 2018/11/25 14:17:11 by seshevch         ###   ########.fr       */
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
		new->h = 0;
		new->dots = 0;
		new->next = NULL;
		if (*last)
			(*last)->next = new;
		else
			*last = new;
	}
}

t_ttrmn		*find_elem(t_ttrmn **lst, char letter)
{
	t_ttrmn		*elem;

	if (!*lst)
	{
		add_elem(lst, letter);
	}
	elem = *lst;
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

void		lst_del(t_ttrmn **lst)
{
	t_ttrmn		*ptr;

	ptr = *lst;
	while (ptr)
	{
		ptr = ptr->next;
		free(*lst);
		*lst = ptr;
	}
	//system ("leaks fillit");
}
