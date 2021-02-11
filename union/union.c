/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchariss <tchariss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 19:48:10 by tchariss          #+#    #+#             */
/*   Updated: 2021/02/10 16:28:16 by tchariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int search(char *str, char c, int len)
{
    int count;
    
    count = 0;
    while (count < len)
    {
        if (str[count] == c) // есть ли в записанной строке символ, проверяем каждый и шагаем если нет 
            return (0); //  если sym = sym , вернем 0 (ничего)
        count++; //  проверяем каждый и шагаем если нет 
    }
    return (1);
}

void ft_union(char *str1, char *str2)
{
    int i;
    int len;
    
    i = 0;

    while (str1[i]) // идем по 1 строке
    {
        if ((search(str1, str1[i], i)) == 1) // если нашелся символ непохожие
            write(1, &str1[i], 1); //печатаем
        i++; //иначе просто шагаем (потому что уже был похожий символ)
    }
    len = i; // len = длине первой строки / идем с конца первой
    i = 0;
    while (str2[i]) // идем по 2 строке
    { //   но с конца первой 
        if ((search(str2, str2[i], i)) == 1) // // если нашли символ одинаковый, в строке 2 из строки 2 - выходим
        { // если во второй строке есть неодинаковый символ смотрим в первой
            if ((search(str1, str2[i], len)) == 1) // если нашли символ непохожий
                write(1, &str2[i], 1); // если не было такого символа в строке ->печатаем
        } // выходим так как символ уже такой был 
        i++; // шагаем по строке // потому 
    }
}

// int main(int argc, char **argv)
// {
//     if (argc == 3)
//         ft_union(argv[1], argv[2]);
//     write(1, "\n", 1);
//     return (0);
// }


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