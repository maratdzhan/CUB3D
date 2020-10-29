/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iunity <iunity@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 18:04:34 by iunity            #+#    #+#             */
/*   Updated: 2020/10/29 03:07:43 by iunity           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

unsigned int	ft_spixel(t_core *s, int index, unsigned int col)
{
	int	t;
	int	r;
	int	g;
	int	b;

	if (col >= NONE)
		return (s->img.adr[index]);
	else if (col < 256 * 256 * 256)
		return (col);
	t = col / (256 * 256 * 256);
	r = (col / (256 * 256) % 256) * (1 - (double)t / 256.);
	g = (col / 256 % 256) * (1 - (double)t / 256.);
	b = (col % 256) * (1 - (double)t / 256);
	r += (s->img.adr[index] / (256 * 256) % 256) * ((double)t / 256.);
	g += (s->img.adr[index] / 256 % 256) * ((double)t / 256.);
	b += (s->img.adr[index] % 256) * ((double)t / 256.);
	return (r * 256 * 256 + g * 256 + b);
}

void			ft_sdraw(t_core *s, int loc, double dist)
{
	unsigned int	col;
	double			size;
	int				index;
	int				i;
	int				j;

	i = 0;
	j = 0;
	size = s->win.y / dist / 2;
	loc = loc - size / 2;
	while (i < size)
	{
		while ((loc + i >= 0 && loc + i < s->win.x) &&
				(j < size && s->stk[loc + i].dist > dist))
		{
			col = 64 * floor(64 * (double)j / size) + (double)i / size * 64;
			col = s->tex.sprite[col];
			index = loc + i + (s->win.y / 2 + j) * s->win.x;
			if (index < s->win.x * s->win.y)
				s->img.adr[index] = ft_spixel(s, index, col);
			j++;
		}
		i++;
		j = 0;
	}
}

void			ft_slocate(t_core *s, double dirx, double diry, double dist)
{
	double	angle;

	dirx = (dirx - s->pos.x) / dist;
	diry = (diry - s->pos.y) / dist;
	if (diry <= 0)
		angle = acos(dirx) * 180 / M_PI;
	else
		angle = 360 - acos(dirx) * 180 / M_PI;
	angle = s->dir.angle - angle + 33;
	if (angle >= 180)
		angle -= 360;
	else if (angle <= -180)
		angle += 360;
	ft_sdraw(s, angle * s->win.x / 66, dist);
}

void			ft_sorder(t_core *s)
{
	t_hit	tmp;
	int		i;
	int		j;

	i = 0;
	while (i < s->map.spr - 1)
	{
		j = i + 1;
		while (j < s->map.spr)
		{
			if (s->spr[i].dist < s->spr[j].dist)
			{
				tmp = s->spr[i];
				s->spr[i] = s->spr[j];
				s->spr[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

void			ft_sprite(t_core *s)
{
	int		i;
	double	dist;

	dist = hypot(s->dir.x, s->dir.y);
	if (s->dir.y <= 0)
		s->dir.angle = acos(s->dir.x / dist) * 180 / M_PI;
	else
		s->dir.angle = 360 - acos(s->dir.x / dist) * 180 / M_PI;
	i = 0;
	while (i < s->map.spr)
	{
		s->spr[i].dist = hypot(s->spr[i].x - s->pos.x, s->spr[i].y - s->pos.y);
		i++;
	}
	ft_sorder(s);
	i = 0;
	while (i < s->map.spr)
	{
		ft_slocate(s, s->spr[i].x, s->spr[i].y, s->spr[i].dist);
		i++;
	}
	free(s->stk);
}
