/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seshevch <seshevch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 18:54:58 by seshevch          #+#    #+#             */
/*   Updated: 2018/11/28 16:49:11 by seshevch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			error(t_ttrmn **lst, int code)
{
	char	*message;

	if (code == 1)
	{
		message = "error";
		lst_del(lst);
	}
	else
	{
		message = "usage: ./fillit source_file";
	}
	ft_putendl(message);
	exit(1);
}

int			ft_dimensions(char letter)
{
	int		i;

	i = 0;
	while (i * i < (letter - 'A' + 1) * 4)
	{
		i++;
	}
	return (i);
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
	if (node->h != 4 || node->dots != 12)
		return (0);
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			total += validate_ttrmn(node->xy[i][0], node->xy[j][0],
			node->xy[i][1], node->xy[j][1]);
			j++;
		}
		i++;
	}
	return (total <= 8 && total >= 6);
}

char		validate_file(t_ttrmn **lst, int fd, char letter, int counter)
{
	char				*line;
	t_ttrmn				*elem;

	line = NULL;
	elem = *lst;
	while (get_next_line(fd, &line) == 1)
	{
		if (counter >= 0 && counter <= 3)
		{
			counter == 0 && *line == '\0' ? error(lst, 1) : 0;
			add_to_block(elem, line, counter) != 4 ? error(lst, 1) : 0;
			counter++;
		}
		else
		{
			(validate_block(elem) == 0) ? error(lst, 1) : 0;
			counter = 0;
			letter++;
			letter > 'Z' ? error(lst, 1) : 0;
			elem = add_elem(lst, letter);
		}
		free(line);
	}
	(validate_block(elem) == 0) ? error(lst, 1) : 0;
	return (elem->letter);
}
