/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llejeune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 15:01:10 by llejeune          #+#    #+#             */
/*   Updated: 2019/01/30 17:33:20 by llejeune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_fill_pixel(my_m *m, int x, int y)
{
	int			pixel;

	pixel = 4 * (x + (m->l * y));
	if (x < m->l && x >= 0 && y < m->h && y >= 0 && pixel < (4 * m->l * m->h) && pixel > 0)
	{
		((unsigned char*)m->str)[pixel] = m->lst_point->c.blue;
		((unsigned char*)m->str)[pixel + 1] = m->lst_point->c.green;
		((unsigned char*)m->str)[pixel + 2] = m->lst_point->c.red;
		((unsigned char*)m->str)[pixel + 3] = m->lst_point->c.alpha;
	}
}

void	ft_color(float z, my_m *m)
{
	if (z < 0)
		z = -z;
	if (z >= 0)
	{
		m->lst_point->c.blue = 0;
		m->lst_point->c.green = 255;
		m->lst_point->c.red = 0;
		m->lst_point->c.alpha = 0;
	}
}

void	ft_always(my_m *m)
{
	int		i;

	i = 0;
	while (i < (m->l * m->h * 4))
		m->str[i++] = 0;
	ft_fill_image(&m->lst_point, m);
	mlx_put_image_to_window(m->mlx_ptr, m->win_ptr, m->img_ptr, 0, 0);
}

void	ft_fill_image(t_v3 **alst, my_m *m)
{
	t_v3	*keep;

	keep = (*alst);
	if (keep != NULL)
	{
		while (keep != NULL)
		{
			ft_color(keep->point.z, m);
			ft_fill_pixel(m, keep->point.x + m->offx, keep->point.y + m->offy);
			keep = keep->next;
		}
	}
}

int		ft_key(int key, my_m *m)
{
	(key == P) ? ft_zoom(&m->lst_point, m, 2) : 0;
	(key == M) ? ft_zoom(&m->lst_point, m, 0.5) : 0;
	(key == F_H) ? (m->offy -= 10) : 0;
	(key == F_B) ? (m->offy += 10) : 0;
	(key == F_G) ? (m->offx -= 10) : 0;
	(key == F_D) ? (m->offx += 10) : 0;
	(key == TWO) ? ft_rotation_x(10, m) : 0;
	(key == FIVE) ? ft_rotation_x(-10, m) : 0;
	(key == FOUR) ? ft_rotation_y(10, m) : 0;
	(key == SIX) ? ft_rotation_y(-10, m) : 0;
	(key == SEVEN) ? ft_rotation_z(10, m) : 0;
	(key == EIGHT) ? ft_rotation_z(-10, m) : 0;
	(key == ESC) ? exit(0) : 0;
	ft_always(m);
	return (1);
}

