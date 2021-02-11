/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_gnl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchariss <tchariss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 23:57:59 by viktoriashe       #+#    #+#             */
/*   Updated: 2021/02/10 23:16:43 by tchariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

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
	char str[2];
	char *memory;
	int i;

	*line = NULL;
	str[1] = '\0';
	*line = (char *)malloc(1 * sizeof(char));
	(*line)[0] = '\0';
	while ((i = read(0, str, 1)) > 0)
	{
		if (str[0] == '\n')
			return 1;
		memory = *line;
		*line = ft_strjoin(*line, str[0]);
		free(memory);
		memory = NULL;
	}
	if (i == -1)
	{
		free(*line);
		*line = NULL;
		return (-1);
	}
}