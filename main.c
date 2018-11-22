/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyakoven <yyakoven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 12:33:46 by yyakoven          #+#    #+#             */
/*   Updated: 2018/11/22 19:06:24 by yyakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		sub_sub_validate(int y1, int y2, int x1, int x2)
{
	if (x1 == x2)
	{
		return (y1 - y2 == 1 || y1 - y2 == -1);
	}
	else if (y1 == y2)
	{
		return (x1 - x2 == 1 || x1 - x2 == -1);
	}
	else
		return (0);
}

int			sub_validate(t_ttrmn *node)
{
	int		i;
	int		j;
	int		total;

	i = 0;
	total = 0;
	if (node->squares != 4)
		return (0);
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			total += sub_sub_validate(node->s[i][0], node->s[j][0], node->s[i][1], node->s[j][1]);
			j++;
		}
		i++;
	}
	//printf("%d\n", total);
	return (total <= 8 && total >= 6);
}

//int			validate(t_ttrmn *list, *line)

int			main(void)
{
	int					fd;
	char				*line;
	t_ttrmn				*list;
	t_ttrmn				*elem;
	char				letter;
	int					counter;

	line = NULL;
	counter = 0;
	fd = open("ttrmn", O_RDONLY);
	letter = 'A';
	//list = (t_ttrmn *)malloc(sizeof(t_ttrmn));
	elem = find_elem(&list, letter);
	while (get_next_line(fd, &line) == 1)
	{
		if (counter >= 0 && counter <= 3)
		{
			if (add_to_block(elem, line, counter) != 4)
			{
				write(2, "error\n", 6);
				lst_del(&list);
				return (1);
			}
			counter++;
		}
		else
		{
			if (*line || sub_validate(elem) == 0)
			{
				write(2, "error\n", 6);
				lst_del(&list);
				return (1);
			}
			counter = 0;
			letter++;
			elem = find_elem(&list, letter);
		}
	}
	printf("blocks: %d\n", letter - 'A');
	printf("%c, %c, %c, %c\n", list->letter, list->next->letter, list->next->next->letter,
	list->next->next->next->letter);
	printf("%d\n", sub_validate(list->next));
	//printf("%d", list->next->squares);
	return (0);
}
