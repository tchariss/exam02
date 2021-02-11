/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_inter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchariss <tchariss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 23:38:48 by viktoriashe       #+#    #+#             */
/*   Updated: 2021/02/10 23:12:50 by tchariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int search(char *s, char c, int len)
{
    int i;
    i = 0;

    while(i < len)
    {
        if(s[i] == c)
            return 0;
        i++;
    }
    return 1;
}

void ft_inter(char *s1, char *s2)
{
    int i;
    int j;

    i = 0;
    while(s1[i])
    {
        if((search(s1, s1[i], i)) == 1)
        {
            j = 0;
            while(s2[j])
            {
                if(s1[i] == s2[j])
                {
                    write(1, &s1[i], 1);
                    break;
                }
                j++;
            }
        }
        i++;
    }
}

int main()
{
    char *s1;
    char *s2;

    s1 = "ddf6viewg164f";
    s2 = "gtwthgdwthdwfteewhrtag6h4ffdhsd" ;
    // argc = 3;
    // argv = "df6vewg4thras" "ddf6vewg64fgtwthgdwthdwfteewhrtag6h4ffdhsd";
    // if (argc == 3)
    ft_inter(s1, s2);
    write(1, "\n", 1);
    return (0);
}

// int main(int argc, char **argv)
// {
//     if(argc == 3)
//         ft_inter(argv[1], argv[2]);
//     write(1, "\n", 1);
//     return 0;
// }