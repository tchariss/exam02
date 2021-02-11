/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_union.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchariss <tchariss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 23:48:13 by viktoriashe       #+#    #+#             */
/*   Updated: 2021/02/10 23:06:11 by tchariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int search(char *str, char c, int len)
{
    int i;

    i = 0;
    while(i < len)
    {
        if(str[i] == c)
            return 0;
        i++;
    }
    return 1;
}

void ft_union(char *s1, char *s2)
{
    int i;
    int len;

    i = 0;
    while(s1[i])
    {
        if((search(s1, s1[i], i)) == 1)
            write(1, &s1[i], 1);
        i++;
    }
    len = i;
    i = 0;
    while(s2[i])
    {
        if((search(s2, s2[i], i)) == 1)
        {
            if((search(s1, s2[i], len)) == 1)
            {
                write(1, &s2[i], 1);
            }        
        }
        i++;
    }
}

int main()
{
    char *s1;
    char *s2;

    s1 = "zpadinton";
    s2 = "paqefwtdjetyiytjneytjoeyjnejeyj" ;
    // argc = 3;
    // argv = "df6vewg4thras" "ddf6vewg64fgtwthgdwthdwfteewhrtag6h4ffdhsd";
    // if (argc == 3)
    ft_union(s1, s2);
    write(1, "\n", 1);
    return (0);
}