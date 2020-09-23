/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iunity <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 22:37:45 by iunity            #+#    #+#             */
/*   Updated: 2020/09/23 23:29:53 by iunity           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
char    *error(char *line)
{
    free(line);
    return (NULL);
}

int     check_err_line(char *line, int buf_size)
{
    int     i;

    i = 0;
    if (line == NULL)
        return (0);
    if (read_size == 0)
        return (1);
    while(line[i] != '\0')
    {
        if (stock[i] == '\n')
            return (1);
        i++;
    }
    return (0);
}

char    *join_line(char *line, char *buf)
{
    int     i;
    int     j;
    char    *result;

    i = 0;
    j = 0;
    while(line[i] != NULL && line[i] != '\0')
        i++;
    while(buf[j] != '\0')
        j++;
    if (!(new = malloc(sizeof(char) * (i + j + 1))))
        return (error(line));
    i = 0;
    j = 0;
    while (line != NULL && line[i] != '\0')
        result[i++] = buf[j++];
    result[j] = 0;
    if (line != NULL)
        free(line);
    return (result);
}

char    *trim_line(char *line)
{
    int     i;
    int     j;
    char    *result;

    i = 0;
    j = 0;
    while(line[i] != '\n' && line[i] != '\0')
        i++;
    while(line[i++] != '\0')
        j++;
    if (!(result = malloc(sizeof(char) * j + 1)))
        return (error(line));
    i = 0;
    j = 0;
    while(line[i] != '\n' && line[i] != '\0')
        i++;
    if (line[i] != '\0')
        i--;
    while(line[i] !='\0')
        result[j++] = line[i++];
    result[j] = '\0'
    free(line);
    return (result);
}

char    *get_line(char *line)
{
    int     i;
    char    *buf;

    i = 0;
    while(line[i] != '\n' && line[i] != '\0')
        i++;
    if (!(buf = malloc(sizeof(char)) * i + 1))
        return (error(line));
    i = 0;
    while(line[i] != '\n' && line[i] != '\0')
    {
        buf[i] = line[i];
        i++;
    }
    buf[i] = '\0';
    return (buf);
}
