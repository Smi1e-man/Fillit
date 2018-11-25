/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algoritm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyakoven <yyakoven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 18:58:33 by seshevch          #+#    #+#             */
/*   Updated: 2018/11/25 12:40:55 by yyakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl/libft/includes/libft.h"
#include "stdio.h"
#include "fillit.h"

/*
** draws tetrimino if possible 
*/
int     ft_alpha(char **str, int i, int k, int p, int *coor)
{
    //int     coor[9] = {0,0,0,1,1,0,2,0,42};

    if (coor[p + 2] == 42)
    {
        if (str[i + coor[p]][k + coor[p + 1]] == '.')
        {
            str[i + coor[p]][k + coor[p + 1]] = 'A';
            return (1);
        }
        else
            return (0);
    }
    else if (str[i + coor[p]][k + coor[p + 1]] != '.')
        return (0);
    else 
    {
        if (ft_alpha(str, i, k, p + 2, coor) == 1)
        {
            str[i + coor[p]][k + coor[p + 1]] = 'A';
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
int     ft_super_alpha(char **str, int i, int k, t_ttrmn *list)
{
    //int     coor1[9] = {0,0,0,1,1,0,2,0,42};
    //int     i1;
    //int     k1;
    //int     p;
    int         t;

    t = 0;
    while(!(i == 4 && k == 4) && ((t = ft_alpha(str, i , k, 0, list->coords)) == 0))
    {
        if (str[i][k + 1] == '\0')
        {
            i++;
            k = 0;
        }
        else
            k++;
    }
    if (t == 1 && a < 1)
    {
        if (ft_super_alpha(str, 0, 0, a + 1, coor) == 1)
            return (0);
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

int 
{

}
int     main(void)
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
    printf("%d\n", ft_super_alpha(str, 0, 0, 0, coor));
    while (i < 4)
    {
        printf("%s\n", str[i]);
        i++;
    }
    return (0);
}