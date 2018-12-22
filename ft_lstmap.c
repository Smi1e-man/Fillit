/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seshevch <seshevch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 15:56:49 by yyakoven          #+#    #+#             */
/*   Updated: 2018/11/29 16:41:36 by seshevch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*el;
	t_list	*new_list;

	el = NULL;
	new_list = NULL;
	while (lst)
	{
		if (!el)
		{
			el = malloc(sizeof(t_list));
			el = f(lst);
			new_list = el;
		}
		else
		{
			el->next = malloc(sizeof(t_list));
			el->next = f(lst);
			el = el->next;
		}
		lst = lst->next;
	}
	return (new_list);
}
