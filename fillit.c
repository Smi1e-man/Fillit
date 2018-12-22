/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seshevch <seshevch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 12:33:46 by yyakoven          #+#    #+#             */
/*   Updated: 2018/11/28 17:12:42 by seshevch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_print(char **str)
{
	int		i;

	i = 0;
	while (i < g_d)
	{
		ft_putendl(str[i]);
		i++;
	}
}

char		**ft_mall(int size, char **str)
{
	int		i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			free(str[i]);
			i++;
		}
		str = NULL;
		i = 0;
	}
	str = (char **)malloc(sizeof(char *) * (size + 1));
	str[size] = NULL;
	while (i < size)
	{
		str[i] = ft_memset(ft_strnew(size), '.', size);
		i++;
	}
	return (str);
}

int			main(int argc, char **argv)
{
	int					fd;
	t_ttrmn				*lst;
	char				**str;

	if (argc != 2)
		error(&lst, 2);
	lst = NULL;
	str = NULL;
	add_elem(&lst, 'A');
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error(NULL, 1);
	g_d = ft_dimensions(validate_file(&lst, fd, 'A', 0));
	str = ft_mall(g_d, str);
	while (ft_super_alpha(str, 0, 0, lst) == 0)
	{
		g_d++;
		str = ft_mall(g_d, str);
	}
	ft_print(str);
	close(fd);
	lst_del(&lst);
	return (0);
}
