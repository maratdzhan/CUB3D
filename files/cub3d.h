/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iunity <iunity@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 15:00:09 by iunity            #+#    #+#             */
/*   Updated: 2020/10/29 03:05:40 by iunity           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../mlxopengl/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
# include <fcntl.h>
# include <stdio.h>

# define NONE 0xFF000000
# define BLACK 0x00000000

# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2
# define LEFT 123
# define RIGHT 124

# define SPEED 15
# define TURN 0.15

typedef struct	s_mlx
{
	void			*ptr;
}				t_mlx;

typedef struct	s_win
{
	void			*ptr;
	int				x;
	int				y;
}				t_win;

typedef struct	s_img
{
	void			*ptr;
	unsigned int	*adr;
}				t_img;

typedef struct	s_err
{
	int				n;
	int				m;
	int				p;
}				t_err;

typedef struct	s_map
{
	char			**tab;
	int				x;
	int				x_max;
	int				y;
	int				spr;
}				t_map;

typedef struct	s_tex
{
	unsigned int	*n;
	unsigned int	*s;
	unsigned int	*e;
	unsigned int	*w;
	unsigned int	*sprite;
	unsigned int	c;
	unsigned int	f;
}				t_tex;

typedef struct	s_pos
{
	double			x;
	double			y;
}				t_pos;

typedef struct	s_dir
{
	double			x;
	double			y;
	double			angle;
}				t_dir;

typedef struct	s_ray
{
	double			x;
	double			y;
	int				i;
	double			v;
	double			w;
}				t_ray;

typedef struct	s_hit
{
	double			x;
	double			y;
	double			dist;
}				t_hit;

typedef struct	s_core
{
	t_mlx			mlx;
	t_win			win;
	t_img			img;
	t_err			err;
	t_map			map;
	t_tex			tex;
	t_pos			pos;
	t_dir			dir;
	t_ray			ray;
	t_hit			hit;
	t_hit			*spr;
	t_hit			*stk;
}				t_core;

void			ft_init(char *cub, int bmp);
void			ft_declare(t_core s, char *cub, int bmp);
int				ft_cubed(t_core s, char *cub, int bmp);
void			ft_draw(t_core *s);

int				ft_parse(t_core *s, char *cub);
int				get_next_line(int fd, char **line);
int				ft_line(t_core *s, char *line);

int				ft_map(t_core *s, char *line, int *i);
char			*ft_smap(t_core *s, char *line, int *i);
int				ft_smaplen(t_core *s, char *line);
int				ft_texture(t_core *s, unsigned int **adr, char *line, int *i);
int				ft_xpm(t_core *s, unsigned int **adr, char *file);

int				ft_slist(t_core *s);
void			ft_pos(t_core *s);
int				ft_colors(unsigned int *color, char *line, int *i);
int				ft_res(t_core *s, char *line, int *i);

int				ft_parcheck(t_core *s);
int				ft_mapcheck(t_core *s);
int				ft_savecheck(char *arg, char *save);
int				ft_namecheck(char *arg, char *ext);

int     		ft_map_wall_check(char **map, int maplen, int max);
char			*ft_map_addspace(char *str, int len, int max);
int				ft_map_leveling(char **map, int maplen, int max);
void			ft_rebuild_map(t_core *s);

int				ft_key(int key, void *arg);
void			ft_rotate(t_core *s, double c);
void			ft_strafe(t_core *s, double c);
void			ft_move(t_core *s, double c);
int				ft_close(t_core *s, int win);

void			ft_screen(t_core *s);
void			ft_ray(t_core *s);
void			ft_dir(t_core *s);
void			ft_ver(t_core *s);
void			ft_hor(t_core *s);

void			ft_stock(t_core *s);
int				ft_size(t_core *s);
void			ft_column(t_core *s, int start);
unsigned int	ft_pixel(t_core *s, double i);

void			ft_sprite(t_core *s);
void			ft_sorder(t_core *s);
void			ft_slocate(t_core *s, double dirx, double diry, double dist);
void			ft_sdraw(t_core *s, int loc, double dist);
unsigned int	ft_spixel(t_core *s, int index, unsigned int col);

int				ft_bitmap(t_core *s);
void			ft_bdraw(t_core *s);
void			ft_bfile(t_core *s, int fd);
void			ft_binfo(t_core *s, int fd);
void			ft_bdata(t_core *s, int fd);

char			*error(char *stock);
int				newline_check(char *stock, int read_size);
char			*buf_join(char *stock, char *buf);
char			*stock_trim(char *stock);
char			*get_line(char *stock);

int				ft_atoi(char *line, int *i);
char			*ft_strchr(const char *str, int arg);
int				ft_skipspaces(char *line, int *i);
char			*ft_strcpy(char *dst, const char *src);
size_t			ft_strlen(const char *str);

int				ft_strerror(int err);
void	print_map(t_core *s);

#endif
