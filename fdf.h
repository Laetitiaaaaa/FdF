/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llejeune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 17:47:55 by llejeune          #+#    #+#             */
/*   Updated: 2019/02/09 10:07:43 by llejeune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define ESC 53
# define P 69
# define M 78
# define F_H 126
# define F_B 125
# define F_G 123
# define F_D 124
# define TWO 84
# define FIVE 87
# define FOUR 86
# define SIX 88
# define EIGHT 91
# define SEVEN 89
# define EIGHT 91
# define THREE 85
# define NINE 92
# define ONE 83
# define M_L 1200
# define M_H 800

# include <mlx.h>
# include <math.h>
# include "libft/libft.h"
# include <stdio.h>

typedef struct		s_point
{
	double			x;
	double			y;
	double			z;
}					t_point;

typedef struct		s_color
{
	unsigned char	blue;
	unsigned char	green;
	unsigned char	red;
	unsigned char	alpha;
}					t_color;

typedef struct		s_liste
{
	t_point			point;
	t_point			save;
	t_point			origin;
	int				zed;
	t_color			c;
	struct s_liste	*next;
}					t_v3;

typedef struct		s_matrice
{
	float			tab[3][3];
}					t_matrice;

typedef struct		s_general
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	int				bpp;
	int				s_l;
	int				endian;
	char			*str;
	int				h;
	int				l;
	int				i;
	int				c;
	t_v3			*lst_point;
	t_matrice		mat;
	t_matrice		rot;
	int				offx;
	int				offy;
	int				fd;
	char			**tmp;
	int				x;
	int				y;
	int				x1;
	int				y1;
	int				dx;
	int				dy;
	int				sx;
	int				sy;
	int				e;
}					t_my_m;

t_v3				*ft_new_node(t_v3 *new_node);
void				ft_add_node(t_v3 **alst, t_v3 *new_node);
void				ft_map(int *fd, t_my_m *m);
void				ft_fill_pixel(t_my_m *m, int x, int y, int z);
void				ft_fill_image(t_v3 **alst, t_my_m *m);
int					ft_key(int key, t_my_m *m);
void				ft_zoom(t_v3 **lst_point, t_my_m *m, float i);
void				ft_always(t_my_m *m);
void				ft_mult_1_3(t_v3 **alst, t_matrice *mat);
t_matrice			ft_mult_3_3(t_matrice *mat, t_matrice *mat1);
void				ft_color(t_my_m *m, int z);
void				ft_rotation_x(float angle, t_my_m *m);
void				ft_rotation_y(float angle, t_my_m *m);
void				ft_rotation_z(float angle, t_my_m *m);
int					ft_zmax(t_my_m *m);
void				ft_nb_color(t_my_m *m, int blue, int green, int red);
int					ft_open(char *av, t_my_m *m);
int					ft_init_mlx(t_my_m *m);
void				ft_free(t_my_m *m);
void				ft_segment(t_my_m *m, t_v3 **alst, t_v3 **next, int z);

#endif
