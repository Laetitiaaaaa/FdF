/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llejeune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 17:47:55 by llejeune          #+#    #+#             */
/*   Updated: 2019/01/23 14:47:25 by llejeune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include "libft/libft.h"

typedef struct		s_point
{
	int				x;
	int				y;
	int				z;
}					t_point;

typedef struct		s_list
{
	t_point			*point;
	struct s_list	*next;
}					t_list;

typedef struct		s
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	int				bpp;
	int				s_l;
	int				endian;
	char			*str;
}					my_m;

t_list				*ft_new_node(t_list *new_node);
void				ft_add_node(t_list **alst, t_list *new_node);
void				ft_map(int *fd);
void				ft_fill_pixel(my_m *m, int x, int y);
void				ft_fill_image(t_list **alst);

#endif
