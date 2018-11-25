/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seshevch <seshevch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 12:33:46 by yyakoven          #+#    #+#             */
/*   Updated: 2018/11/25 15:11:17 by seshevch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			error(t_ttrmn **lst)
{
	write(2, "error\n", 6);
	lst_del(lst);
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

t_ttrmn		*validate_file(t_ttrmn **lst, t_ttrmn *elem, int fd)
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
			add_to_block(elem, line, counter) != 4 ? error(lst) : 0;
			counter++;
		}
		else
		{
			(validate_block(elem) == 0) ? error(lst) : 0;
			counter = 0;
			letter++;
			elem = find_elem(lst, letter);
		}
		free(line);
	}
	return (elem);
}

int			main(void)
{
	int					fd;
	t_ttrmn				*lst;
	t_ttrmn				*elem;
	char				**str;
	int					i;

	lst = NULL;
	str = (char **)malloc(sizeof(char *) * 5);
	str[4] = NULL;
	i = 0;
	elem = find_elem(&lst, LETTER);
	fd = open("ttrmn", O_RDONLY);
	if (fd == -1)
	{
		error(NULL);
	}
	elem = validate_file(&lst, elem, fd);
	(validate_block(elem) == 0) ? error(&lst) : 0;
	while (i < 4)
    {
        str[i] = ft_memset(ft_strnew(4), '.', 4);
        //printf("%s\n", str[i]);
        i++;
    }
    i = 0;
    //write(1, "*\n", 2);
    //str[0][0] = '#';
    //str[0][2] = '#';
    //printf("%d\n", ft_super_alpha(str, 0, 0, lst));
	ft_super_alpha(str, 0, 0, lst);
    while (i < 4)
    {
        printf("%s\n", str[i]);
        i++;
    }
	close(fd);
	lst_del(&lst);
	return (0);
}
