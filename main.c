/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyakoven <yyakoven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 12:33:46 by yyakoven          #+#    #+#             */
/*   Updated: 2018/11/25 12:40:17 by yyakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			error(t_ttrmn **list)
{
	write(2, "error\n", 6);
	lst_del(list);
	exit(1);
}

int			validate_ttrmn(int y1, int y2, int x1, int x2)
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

int			validate_block(t_ttrmn *node)
{
	int		i;
	int		j;
	int		total;

	i = 0;
	total = 0;
	if (node->hashes != 4 || node->dots != 12)
		return (0);
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			total += validate_ttrmn(node->coords[i][0], node->coords[j][0],
			node->coords[i][1], node->coords[j][1]);
			j++;
		}
		i++;
	}
	return (total <= 8 && total >= 6);
}

t_ttrmn		*validate_file(t_ttrmn **list, t_ttrmn *elem, int fd)
{
	char				letter;
	int					counter;
	char				*line;

	counter = 0;
	letter = 'A';
	line = NULL;
	while (get_next_line(fd, &line) == 1)
	{
		if (counter >= 0 && counter <= 3)
		{
			add_to_block(elem, line, counter) != 4 ? error(list) : 0;
			counter++;
		}
		else
		{
			(validate_block(elem) == 0) ? error(list) : 0;
			counter = 0;
			letter++;
			elem = find_elem(list, letter);
		}
		free(line);
	}
	return (elem);
}

int			main(void)
{
	int					fd;
	t_ttrmn				*list;
	t_ttrmn				*elem;

	list = NULL;
	elem = find_elem(&list, LETTER);
	fd = open("ttrmn", O_RDONLY);
	if (fd == -1)
	{
		error(NULL);
	}
	elem = validate_file(&list, elem, fd);
	(validate_block(elem) == 0) ? error(&list) : 0;
	// while (list)
	// {
	// 	printf("%c\n", list->letter);
	// 	list = list->next;
	// }
	close(fd);
	lst_del(&list);
	//system("leaks fillit");
	return (0);
}

/*
** printf("%c, %c, %c, %c\n", list->letter, list->next->letter,
** list->next->next->letter,
** list->next->next->next->letter);
** printf("%c\n", list->letter);
** printf("%d", list->next->hashes);
*/
