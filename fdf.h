/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llejeune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 17:47:55 by llejeune          #+#    #+#             */
/*   Updated: 2019/01/25 20:40:54 by llejeune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define ESC 53
# define F_H 126
# define F_B 125
# define F_G 123
# define F_D 124

# include <mlx.h>
# include "libft/libft.h"
# include <stdio.h>

typedef struct		s_point
{
	float			x;
	float			y;
	float			z;
}					t_point;

/*typedef struct		s_color
{
	unsigned char	blue;
	unsigned char	green;
	unsigned char	red;
	unsigned char	alpha;
}					t_color;
*/
typedef struct		s_liste
{
	t_point			point;
	t_point			save;
//	t_color			c;
	struct s_liste	*next;
}					t_v3;

typedef struct		m
{
	int				tab[3][3];
}					mat;

typedef struct		s
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	int				bpp;
	int				s_l;
	int				endian;
	char			*str;
	int				i;
	int				c;
	t_v3			*lst_point;
	mat				mat;
	mat				mat1;
}					my_m;

t_v3				*ft_new_node(t_v3 *new_node);
void				ft_add_node(t_v3 **alst, t_v3 *new_node);
void				ft_map(int *fd, my_m *m);
void				ft_fill_pixel(my_m *m, float x, float y);
void				ft_fill_image(t_v3 **alst, my_m *m);
int					ft_key(int key, my_m *m);
void				ft_zoom(t_v3 **lst_point, my_m *m, float i);
void				ft_always(my_m *m);
void				ft_mult_1_3(t_v3 **alst, mat *mat);
mat					ft_mult_3_3(mat *mat, mat *mat1);

#endif
