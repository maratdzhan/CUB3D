/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iunity <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 16:16:45 by iunity            #+#    #+#             */
/*   Updated: 2020/09/26 16:16:48 by iunity           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void        ft_log_var(char *value)
{
    write(1,"---> {",6);
    write(1, value, ft_strlen(value));
    write(1, "}", 1);
}

/*
    vtype:
    0 - text;
    1 - variable;
    2 - call function;
    3 - start function;
    4 - local condition;
*/
void        ft_log(char *value, int vtype)
{
    if (vtype == 1)
        ft_log_var(value);
    else
        write(1, value, ft_strlen(value));
    write(1, "\n", 1);
}

/*
    1 - errors on opening configuration file
    2 - errors on reading files
*/

int         ft_errors(int eType, char *value)
{
    if (eType) 
        write(1, value, ft_strlen(value));
    if (eType)
        return (-1);
    return (0);
}
