/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seshevch <seshevch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 18:22:46 by yyakoven          #+#    #+#             */
/*   Updated: 2018/11/28 15:05:14 by seshevch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void			add_el(t_fd **last, int fd)
{
	t_fd		*new;

	new = (t_fd *)malloc(sizeof(t_fd));
	if (new)
	{
		new->buf = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1));
		if (new->buf)
		{
			new->buf[0] = '\0';
			new->fd = fd;
			new->ind = 0;
			new->bytesread = 0;
			new->next = NULL;
			if (*last)
				(*last)->next = new;
			else
				*last = new;
		}
		else
			free(new);
	}
}

static t_fd			*find_el(t_fd **start, int fd)
{
	t_fd		*el;

	if (!*start)
	{
		add_el(start, fd);
	}
	el = *start;
	while (el->next)
	{
		if (el->fd == fd)
		{
			break ;
		}
		el = el->next;
	}
	if (el->fd != fd)
	{
		add_el(&el, fd);
		el = el->next;
	}
	return (el);
}

static void			fill_buf(t_fd *el)
{
	el->bytesread = read(el->fd, el->buf, BUFF_SIZE);
	el->buf[el->bytesread] = '\0';
	el->ind = 0;
}

static void			process(char **line, t_fd *el)
{
	char		*n;
	char		*temp;
	char		*temp2;

	(el->ind >= el->bytesread) ? fill_buf(el) : 0;
	while (!(n = ft_strchr(el->buf + el->ind, '\n')) && el->buf[el->ind])
	{
		(!*line) ? (*line) = ft_strnew(0) : 0;
		temp = ft_strjoin(*line, el->buf + el->ind);
		free(*line);
		*line = temp;
		fill_buf(el);
	}
	if (n)
	{
		(!*line) ? (*line) = ft_strnew(0) : 0;
		temp2 = ft_strsub(el->buf, el->ind, (n - (el->buf + el->ind)));
		temp = ft_strjoin(*line, temp2);
		free(temp2);
		free(*line);
		*line = temp;
		el->ind = n - el->buf + 1;
	}
}

int					get_next_line(const int fd, char **line)
{
	static t_fd		*list;
	t_fd			*el;

	el = NULL;
	if (fd >= 0 && fd < 4096 && (read(fd, 0, 0) >= 0))
	{
		el = find_el(&list, fd);
	}
	if (el)
	{
		if (line)
			*line = NULL;
		process(line, el);
		if (*line)
			return (1);
		else
		{
			return (0);
		}
	}
	return (-1);
}
