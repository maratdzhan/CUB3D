/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iunity <iunity@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 21:41:51 by iunity            #+#    #+#             */
/*   Updated: 2020/10/29 22:46:53 by iunity           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_res(t_core *s, char *line, int *i)
{
	int		px;
	int		py;

	if (s->win.x != 0 || s->win.y != 0)
		return (-3);
	(*i)++;
	s->win.x = ft_atoi(line, i);
	s->win.y = ft_atoi(line, i);
	mlx_get_screen_size(s->mlx.ptr, &px, &py);
	if (s->win.x > px)
		s->win.x = px;
	if (s->win.y > py)
		s->win.y = py;
	ft_skipspaces(line, i);
	if (s->win.x <= 0 || s->win.y <= 0 || line[*i] != '\0')
		return (-4);
	return (0);
}

int		ft_colors(unsigned int *color, char *line, int *i)
{
	int	r;
	int	g;
	int	b;

	if (*color != NONE)
		return (-5);
	(*i)++;
	r = ft_atoi(line, i);
	(*i)++;
	g = ft_atoi(line, i);
	(*i)++;
	b = ft_atoi(line, i);
	ft_skipspaces(line, i);
	if (line[*i] != '\0' || r > 255 || g > 255 || b > 255)
		return (-6);
	*color = r * 256 * 256 + g * 256 + b;
	return (0);
}

void	ft_pos(t_core *s)
{
	char	c;
	int		i;
	int		j;

	i = -1;
	j = -1;
	while (++i < s->map.y)
	{
		while (++j < (int)ft_strlen(s->map.tab[i]))
		{
			c = s->map.tab[i][j];
			if (c == 'N' || c == 'E' || c == 'S' || c == 'W')
			{
				s->pos.y = (double)i + 0.5;
				s->pos.x = (double)j + 0.5;
				s->dir.x = (c == 'E' || c == 'W') ? 1 : 0;
				s->dir.x *= (c == 'W') ? -1 : 1;
				s->dir.y = (c == 'S' || c == 'N') ? 1 : 0;
				s->dir.y *= (c == 'N') ? -1 : 1;
				s->err.p++;
			}
		}
		j = -1;
	}
}

int		ft_slist(t_core *s)
{
	int		i;
	int		j;
	int		k;

	if (s->spr != NULL)
		free(s->spr);
	if (!(s->spr = malloc(sizeof(t_hit) * s->map.spr)))
		return (-1);
	i = 0;
	j = 0;
	while (j < s->map.y)
	{
		k = 0;
		while (k < s->map.x_max)
		{
			if (s->map.tab[j][k] == '2')
			{
				s->spr[i].y = (double)j + 0.5;
				s->spr[i++].x = (double)k + 0.5;
			}
			k++;
		}
		j++;
	}
	return (1);
}
