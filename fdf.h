/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llejeune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 17:47:55 by llejeune          #+#    #+#             */
/*   Updated: 2019/01/23 19:27:09 by llejeune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include "libft/libft.h"

typedef struct		s_point
{
	float			x;
	float			y;
	float			z;
}					t_point;

typedef struct		s_liste
{
	t_point			point;
	struct s_liste	*next;
}					t_v3;

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
}					my_m;

t_v3				*ft_new_node(t_v3 *new_node);
void				ft_add_node(t_v3 **alst, t_v3 *new_node);
void				ft_map(int *fd, t_v3 **lst_point, my_m *m);
void				ft_fill_pixel(my_m *m, int x, int y);
void				ft_fill_image(t_v3 **alst, my_m *m);

#endif
