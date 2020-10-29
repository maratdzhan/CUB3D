/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iunity <iunity@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 17:16:06 by iunity            #+#    #+#             */
/*   Updated: 2020/10/29 22:46:05 by iunity           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_savecheck(char *arg, char *save)
{
	int	i;

	i = 0;
	while (arg[i] == save[i])
	{
		if (arg[i] == '\0' && save[i] == '\0')
			return (1);
		i++;
	}
	return (0);
}

int		ft_namecheck(char *arg, char *ext)
{
	int	i;

	i = 0;
	while (arg[i] != '\0')
		i++;
	if ((i > 4 && arg[i - 1] == ext[2] && arg[i - 2] == ext[1])
		&& (arg[i - 3] == ext[0] && arg[i - 4] == '.'))
		return (1);
	return (0);
}

int		ft_mapcheck(t_core *s)
{
	int		res;

	res = 0;
	res = ft_map_leveling(s->map.tab, s->map.y, s->map.x_max);
	if (res < 0)
		return (ft_strerror(res));
	else
	{
		res = ft_map_wall_check(s->map.tab, s->map.y, s->map.x_max);
		if (res < 0)
			return (ft_strerror(res));
	}
	ft_rebuild_map(s);
	return (0);
}

int		ft_parcheck(t_core *s)
{
	if (s->win.x <= 0 || s->win.y <= 0)
		return (ft_strerror(-14));
	else if ((s->tex.n == NULL || s->tex.s == NULL || s->tex.e == NULL)
			|| (s->tex.w == NULL || s->tex.sprite == NULL))
		return (ft_strerror(-15));
	else if (s->tex.c == NONE || s->tex.f == NONE)
		return (ft_strerror(-16));
	else if (s->err.p == 0)
		return (ft_strerror(-17));
	else if (s->err.p > 1)
		return (ft_strerror(-18));
	else if (ft_mapcheck(s) == -1)
		return (ft_strerror(-19));
	return (1);
}
