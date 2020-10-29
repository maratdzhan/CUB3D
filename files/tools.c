/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iunity <iunity@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 18:01:54 by iunity            #+#    #+#             */
/*   Updated: 2020/10/29 03:07:50 by iunity           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_strchr(const char *str, int arg)
{
	size_t			i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == arg)
			return ((char *)&(str[i]));
		i++;
	}
	if (arg == '\0')
		return ((char *)&(str[i]));
	return (NULL);
}

size_t				ft_strlen(const char *str)
{
	size_t			size;

	size = 0;
	while (str[size] != '\0')
		size++;
	return (size);
}

int		ft_skipspaces(char *line, int *i) // LTRIM
{
	while ((line[*i] == ' ' || line[*i] == '\t' || line[*i] == '\n')
	|| (line[*i] == '\r' || line[*i] == '\v' || line[*i] == '\f'))
		(*i)++;
	return (1);
}

int		ft_atoi(char *line, int *i)
{
	int	num;

	num = 0;
	ft_skipspaces(line, i);
	while (line[*i] >= '0' && line[*i] <= '9')
	{
		num = num * 10 + (line[*i] - 48);
		(*i)++;
	}
	return (num);
}

char			*ft_strcpy(char *dst, const char *src)
{
	size_t		i;

	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
