/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iunity <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 15:55:25 by iunity            #+#    #+#             */
/*   Updated: 2020/09/26 15:55:33 by iunity           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int     ft_is_save(char *arg)
{
    int i;
    char *ss;
    
    i = 0;
    ss = "--save";
    if (arg != NULL)
        while (arg[i] == ss[i])
        {
            if (!arg[i] && !ss[i])
                return (1);
        }
        return (0);
}

int     get_next_line(int fd, char **line)
{
    int     res;
    char    buf[4096];
    static char *stack;

    if (line == NULL || fd < 0)
        return (-3);    
    *line = NULL;
    res = 1;
    while (!(check_newline(stack, res)))
    {
        if ((res = read(fd, buf, 4095)) == -1)
            return (-3);
        buf[res] = '\0';
        if ((stack = join_line(stack, buf)) == NULL)
            return (-3);
    }
    if ((*line = get_line(stack)) == NULL)
        return (-3);
    if (res == 0)
        free(stack);
    if ((stack = trim_line(stack)) == NULL)
        return (-3);
    return (1);
}

int     parse_config(char *filename)
{
    int     res;
    int     fd;
    char    *base;

    res = 1;
    fd = open(filename, O_RDONLY);
    if (fd == -1)
        return (ft_errors(1, "error till opening parameters file"));
    while (res)
    {
        res = get_next_line(fd, &base);
    }
    close(fd);
    if (res == -1 || res == -3)
        return (ft_errors(2,"errors till reading [gnl] parameters file"));
    return (0);
    
}