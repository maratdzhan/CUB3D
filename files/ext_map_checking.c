/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ext_map_checking.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iunity <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 03:03:43 by iunity            #+#    #+#             */
/*   Updated: 2020/10/29 03:04:21 by iunity           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int     ft_map_wall_check(char **map, int maplen, int max)
{
	int				i;
	int				j;

	i = -1;
	while (++i < maplen)
	{
		j = -1;
		while (++j < max)
		{
		 	if ((i == 0 || i == maplen - 1) && !ft_strchr(" 1", map[i][j]))
		 		return (-21);
		 	else if ((j == 0 || j == max - 1) && !ft_strchr(" 1", map[i][j]))
		 		return (-22);
		 	else if (!ft_strchr(" 1", map[i][j]))
			{
		 		if (map[i - 1][j - 1] == ' ' || map[i - 1][j] == ' '
		 				|| map[i - 1][j + 1] == ' ' || map[i][j - 1] == ' '
		 				|| map[i][j + 1] == ' ' || map[i + 1][j - 1] == ' '
		 				|| map[i + 1][j] == ' ' || map[i + 1][j + 1] == ' ')
					return (-23);
			}
		}
	}
    return (0);
}


char     *ft_map_addspace(char *str, int len, int max)
{
	char			*new;
	int				i;

	if (!(new = (char *)malloc(sizeof(char) * (max + 1))))
		return (NULL);
	ft_strcpy(new, str);
	i = len;
	while (i < max)
	{
		new[i] = ' ';
		i++;
	}
	new[i] = '\0';
	return (new);
}

int        ft_map_leveling(char **map, int maplen, int max)
{
	int				i;
	int				len;
	char			*tmp;

	i = 0;
	while (i < maplen)
	{
		len = ft_strlen(map[i]);
		if (len < max)
		{
			tmp = ft_map_addspace(map[i], len, max);
            if (tmp == NULL)
                return (-1);
			free(map[i]);
			map[i] = tmp;
		}
		i++;
	}
    return (0);
}

int		ft_fifo(char *str, int first)
{
	int 	pos;
	int		i;

	pos = 0;
	i = 0;
	while(pos < (int)ft_strlen(str))
	{
		if (str[pos] == '0' && first)
			return (pos - 1);
		else if (str[pos] == '0' && !first)
			i = pos;
		pos++;
	}
	return (i);
}

void	ft_rebuild_map(t_core *s)
{
	int		out;
	int		in;
	int		i;
	int		j;

	i = 0;
	while (i < s->map.y)
	{
		j = 0;
		in = ft_fifo(s->map.tab[i], 1);
		out = ft_fifo(s->map.tab[i], 0);
		while (j < s->map.x_max)
		{
			if ((j < in || j >= out))
				if (s->map.tab[i][j] == ' ')
					s->map.tab[i][j] = '1';
			j++;
		}
		i++;
	}
}

void	print_map(t_core* core)
{
	int i;
	int j;

	i = 0;
	printf("%d && %d\n", core->map.x_max, core->map.y);
	while (i < core->map.y)
	{
		j = 0;
		printf(">>");
		while (j < core->map.x_max)
		{
			printf("%c",core->map.tab[i][j]);
			j++;
		}
		printf("<<\n");
		i++;
	}
}
