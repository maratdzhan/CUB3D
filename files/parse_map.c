/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iunity <iunity@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 21:41:46 by iunity            #+#    #+#             */
/*   Updated: 2020/10/29 22:46:59 by iunity           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_xpm(t_core *s, unsigned int **adr, char *file)
{
	int		fd;
	void	*img;
	int		tab[5];

	if (ft_namecheck(file, "xpm") == 0)
		return (-1);
	if ((fd = open(file, O_RDONLY)) == -1)
		return (-1);
	close(fd);
	img = mlx_xpm_file_to_image(s->mlx.ptr, file, &tab[0], &tab[1]);
	if (img == NULL || tab[0] != 64 || tab[1] != 64)
		return (-1);
	*adr = (unsigned int *)mlx_get_data_addr(img, &tab[2], &tab[3], &tab[4]);
	free(img);
	return (0);
}

int		ft_texture(t_core *s, unsigned int **adr, char *line, int *i)
{
	char	*file;
	int		j;

	if (s->map.parse_st)
		return (-10);
	if (*adr != NULL)
		return (-7);
	(*i) += 2;
	ft_skipspaces(line, i);
	j = *i;
	while (line[*i] != ' ' && line[*i] != '\0')
		(*i)++;
	if (!(file = malloc(sizeof(char) * (*i - j + 1))))
		return (-8);
	*i = j;
	j = 0;
	while (line[*i] != ' ' && line[*i] != '\0')
		file[j++] = line[(*i)++];
	file[j] = '\0';
	j = ft_xpm(s, adr, file);
	free(file);
	return (j == -1 ? -9 : 0);
}

int		ft_smaplen(t_core *s, char *line)
{
	int	count;

	count = 0;
	while (line[count] != '\0')
	{
		if (ft_strchr("NEWS 012", line[count]))
			count++;
		else
			return (-1);
	}
	if (!count)
		return (-1);
	if (count > s->map.x_max)
		s->map.x_max = count;
	return (s->map.x_max);
}

char	*ft_smap(t_core *s, char *line, int *i)
{
	char	*slab;
	int		j;

	if (!(slab = malloc(sizeof(char) * (ft_smaplen(s, line) + 1))))
		return (NULL);
	j = 0;
	(*i) = 0;
	while (line[*i] != '\0')
	{
		if (ft_strchr("NEWS 012", line[*i]))
		{
			if (line[*i] == '2')
				s->map.spr++;
			slab[j++] = line[*i];
		}
		else
		{
			free(slab);
			return (NULL);
		}
		(*i)++;
	}
	slab[j] = '\0';
	return (slab);
}

int		ft_map(t_core *s, char *line, int *i)
{
	char	**tmp;
	int		j;

	if (s->map.parse_st == 2)
		return (-24);
	s->map.parse_st = 1;
	if (!(tmp = malloc(sizeof(char *) * (s->map.y + 2))))
		return (-11);
	j = -1;
	while (++j < s->map.y)
		tmp[j] = s->map.tab[j];
	if ((tmp[s->map.y] = ft_smap(s, line, i)) == NULL)
	{
		free(tmp);
		return (-12);
	}
	tmp[s->map.y + 1] = NULL;
	if (s->map.y > 0)
		free(s->map.tab);
	s->map.tab = tmp;
	s->map.y++;
	if ((s->map.x = ft_smaplen(s, line)) == -1)
		return (-13);
	return (0);
}
