/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iunity <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 21:25:26 by iunity            #+#    #+#             */
/*   Updated: 2020/09/21 21:27:36 by iunity           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../mlx/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
# include <fcntl.h>
# include <stdio.h>

# define ESC 53
# define W 13
# define A 0
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124

# define SPEED 15
# define TURN 0.05

typedef struct	s_mlx
{
	void			*ptr;
}				t_mlx;

#endif

void			init(char *carg, int param);
void			create_environment(char *carg, int param);
void			build_environment(char *carg, int param);

char			*error(char *line);
char			*join_line(char *line, char *buf);
char			*trim_line(char *line);
char			*get_line(char *line);
int				check_err_line(char *line, int buf_size);
int				get_next_line(int fd, char *line);

# endif
