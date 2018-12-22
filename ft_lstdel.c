/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyakoven <yyakoven@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 18:26:15 by yyakoven          #+#    #+#             */
/*   Updated: 2018/10/30 14:54:41 by yyakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*ptr1;
	t_list	*ptr2;

	ptr1 = *alst;
	ptr2 = *alst;
	if (*alst)
	{
		while (ptr1)
		{
			ptr2 = ptr1->next;
			del(ptr1->content, ptr1->content_size);
			free(ptr1);
			ptr1 = ptr2;
		}
		*alst = NULL;
	}
}
