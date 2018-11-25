/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seshevch <seshevch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 13:45:12 by yyakoven          #+#    #+#             */
/*   Updated: 2018/11/25 15:07:19 by seshevch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FILLIT_H
# define __FILLIT_H

# define LETTER 'A'
# include "gnl/get_next_line.h"
# include "gnl/libft/includes/libft.h"
# include <fcntl.h>
# include <stdio.h>

typedef struct		s_ttrmn
{
	int				xy[4][2];
	char			letter;
	int				dots;
	int				h;
	struct s_ttrmn	*next;
}					t_ttrmn;

void				add_elem(t_ttrmn **last, char letter);
t_ttrmn				*find_elem(t_ttrmn **lst, char letter);
int					add_to_block(t_ttrmn *elem, char *line, int linenum);
void				lst_del(t_ttrmn **lst);
int     			ft_super_alpha(char **str, int i, int k, t_ttrmn *lst);

#endif
