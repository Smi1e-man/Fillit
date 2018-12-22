/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyakoven <yyakoven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 14:50:24 by yyakoven          #+#    #+#             */
/*   Updated: 2018/10/31 08:16:15 by yyakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *item;

	item = (t_list *)malloc(sizeof(t_list));
	if (item)
	{
		item->next = NULL;
		if (!content)
		{
			item->content_size = 0;
			item->content = NULL;
		}
		else
		{
			item->content_size = content_size;
			item->content = malloc(content_size);
			item->content = ft_memcpy(item->content, content, content_size);
		}
	}
	return (item);
}
