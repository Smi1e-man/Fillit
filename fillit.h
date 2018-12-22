/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seshevch <seshevch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 13:45:12 by yyakoven          #+#    #+#             */
/*   Updated: 2018/11/29 15:28:48 by seshevch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FILLIT_H
# define __FILLIT_H

# include "libft.h"
# include <fcntl.h>

typedef struct		s_ttrmn
{
	int				xy[4][2];
	char			letter;
	int				dots;
	int				h;
	int				i1;
	int				k1;
	struct s_ttrmn	*next;
}					t_ttrmn;

int					g_d;
int					g_t;
/*
** list.c
*/
t_ttrmn				*find_elem(t_ttrmn **lst, char letter);
t_ttrmn				*add_elem(t_ttrmn **last, char letter);
void				lst_del(t_ttrmn **lst);
int					add_to_block(t_ttrmn *elem, char *line, int linenum);
/*
** validate.c
*/
char				validate_file(t_ttrmn **lst, int fd, char letter,
					int counter);
int					error(t_ttrmn **lst, int code);
int					validate_ttrmn(int y1, int y2, int x1, int x2);
int					validate_block(t_ttrmn *node);
int					ft_dimensions(char letter);
/*
** algorithm.c
*/
int					ft_alpha(char **str, int i, int k, t_ttrmn *el);
int					ft_super_alpha(char **str, int i, int k, t_ttrmn *lst);
void				ft_erase(t_ttrmn *lst, char **str);

#endif
