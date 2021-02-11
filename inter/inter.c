/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchariss <tchariss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 19:52:11 by tchariss          #+#    #+#             */
/*   Updated: 2021/02/10 13:32:16 by tchariss         ###   ########.fr       */
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

void ft_inter(char *str1, char *str2)
{
    int i, j;
    
    i = 0;
    while (str1[i]) // идем по 1 строке
    {
        if ((search(str1, str1[i], i)) == 1) //ищем в первой строке похожие символы и сиключаем
        {
            j = 0; // обнуляем счетчик второй строки и ищем снова в ней похожие символы
            while (str2[j]) // если 2 строка существует
            {
                if (str1[i] == str2[j]) // если в 1 строке символ равен найденному символу во 2 строке
                {
                    write(1, &str1[i] ,1); //печатаем
                    break ; // выходим
                }
                j++; // увеличиваем счетчик
            } // выходим если строка закончилась и мы ничего не нашли
        }
        i++; // шагаем по строке первой 1
    }
}

// int main(int argc, char **argv)
// {
//     if (argc == 3)
//         inter(argv[1], argv[2]);
//     write(1, "\n" ,1);
//     return (1);
// }

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