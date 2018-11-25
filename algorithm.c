/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seshevch <seshevch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 18:58:33 by seshevch          #+#    #+#             */
/*   Updated: 2018/11/25 15:09:59 by seshevch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl/libft/includes/libft.h"
#include "stdio.h"
#include "fillit.h"

/*
** draws tetrimino if possible 
*/
int     ft_alpha(char **str, int i, int k, t_ttrmn *el)
{

    int     f = el->xy[0][0];
    int     s = el->xy[0][1];

    if (el->h == 3)
    {
        if (str[i + el->xy[el->h][0] - f][k + el->xy[el->h][1] - s] == '.')
        {
            str[i + el->xy[el->h][0] - f][k + el->xy[el->h][1] - s] = 'A';
            return (1);
        }
        else
            return (0);
    }
    else if (str[i + el->xy[el->h][0] - f][k + el->xy[el->h][1] - s] != '.')
        return (0);
    else 
    {
        el->h++;
        if (ft_alpha(str, i, k, el) == 1)
        {
            str[i + el->xy[el->h][0] - f][k + el->xy[el->h][1] - s] = 'A';
            return (1);
        }
        else
            return (0);
    }
    return (0);
}
/*
** draws all tetriminos if possible
*/
int     ft_super_alpha(char **str, int i, int k, t_ttrmn *lst)
{
    //int     coor1[9] = {0,0,0,1,1,0,2,0,42};
    //int     i1;
    //int     k1;
    //int     p;
    int         t;

    t = 0;
    lst->h = 0;
    while(!(i == 4 && k == 4) && ((t = ft_alpha(str, i , k, lst)) == 0))
    {
        if (str[i][k + 1] == '\0')
        {
            i++;
            k = 0;
        }
        else
            k++;
    }
    //printf("%s\n%s\n%s\n%s\n", str[0], str[1], str[2], str[3]);
    if (t == 1 && lst->next)
    {
        if (ft_super_alpha(str, 0, 0, lst->next) == 1)
            return (1);
    }
    /*if (ft_alpha(str, i, k, 0) == 1)
    {
        i1 = i; //координаты в листы сохранить, чтоб возвращаться на 2 шага назад
        k1 = k;
        a += 1;
        if (ft_super_alpha(str, i, k, a) == 1)
            return (1);
        else
        {
            p = 0;
            while (coor[p] != 42)
            {
                str[i1 + coor[p]][k1 + coor[p + 1]] = '.';
                p += 2;
            }
            k1 = k1 + 1;
            if (str[i1][k1] == '\0')
            {
                i1++;
                k1 = 0;
            }
            a = a - 1;
            if (ft_super_alpha(str, i1, k1, a) == 1)
                return (1);
            else
                return (0);
        }
    }
    else
    {
        return (0);
    }*/
    return (0);
}

/*int     main(void)
{
    char    **str;
    int     coor[2][9] = {{0,0,0,1,1,0,2,0,42}, {0,0,0,1,0,2,-1,2,42}};
    int     i = 0;
    //char    *pnt;


    
    str[4] = NULL;
    while (i < 4)
    {
        //pnt = ft_strnew(5);
        str[i] = ft_memset(ft_strnew(4), '.', 4);
        //free(pnt);
        printf("%s\n", str[i]);
        i++;
    }
    i = 0;
    write(1, "*\n", 2);
    //str[0][0] = '#';
    //str[0][2] = '#';
    printf("%d\n", ft_super_alpha(str, 0, 0, lst));
    while (i < 4)
    {
        printf("%s\n", str[i]);
        i++;
    }
    return (0);
}*/