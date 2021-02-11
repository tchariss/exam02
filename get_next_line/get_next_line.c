/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchariss <tchariss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 11:10:15 by tchariss          #+#    #+#             */
/*   Updated: 2021/02/10 12:44:23 by tchariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h> // malloc
#include <unistd.h> // read
#include <stdio.h> // printf
#include <fcntl.h>

size_t		ft_strlen(const char *s)
{
	size_t	a;

	a = 0;
	// if (s == NULL)
	// 	return (0);
	while (s[a] != '\0')
	{
		a++;
	}
	return (a);
}

char *ft_strjoin (char *s, char c) // склеиваем строку символовом, потому что знаем , что буфер 1
{ // char -c == *str, buf = 2 => "d\0"
    char *s1;
    int i;
    
    i = 0;
    // if (s == NULL)
    //     return (0);
    s1 = (char *)malloc((ft_strlen(s) + 2) * sizeof(char));
    while (s[i])
    {
        s1[i] = s[i];
        i++;
    }
    s1[i] = c;
    i++;
    s1[i] = '\0';
    return (s1);
}

int get_next_line(char **line)
{
    char str[2]; // под 'символ' и '\0' "| e | \0 |" -> 2
    char *memory;
    int i;
    
    *line = NULL; // чтобы не было мусора
    str[1] = '\0'; 
    
    *line = (char *)malloc(1 * sizeof(char));
    (*line)[0] = '\0'; 
    while ((i = read(0, str, 1)) > 0)
    {
        if (str[0] == '\n') // '\0' на '\n'
            return 1; //-> значит есть что читаьь
        memory = *line;
        *line = ft_strjoin(*line, str[0]);
        free(memory);
        memory = NULL;
    }
    if (i == -1) //  если ничего нет
    {
        free(*line);
        *line = NULL;
        return (-1);
    }
    return (0);
}


char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	int		a;
	int		b;

	a = 0;
	b = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL); // 
	new_str = malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2)) + 1));
	if (new_str == NULL)
		return (NULL);
	while (s1[a] != '\0')
	{
		new_str[a] = s1[a];
		a++;
	}
	while (s2[b] != '\0')
	{
		new_str[a++] = s2[b++];
	}
	new_str[a] = '\0';
	return (new_str);
}
