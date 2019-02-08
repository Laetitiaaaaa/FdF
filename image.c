/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llejeune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 15:01:10 by llejeune          #+#    #+#             */
/*   Updated: 2019/02/08 18:02:02 by llejeune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_fill_pixel(t_my_m *m, int x, int y, int z)
{
	int			pixel;

	ft_color(m, z);
	pixel = 4 * (x + (m->l * y));
	if (x < m->l && x >= 0 && y < m->h && y >= 0 &&
			pixel < (4 * m->l * m->h) && pixel > 0)
	{
		((unsigned char*)m->str)[pixel] = m->lst_point->c.blue;
		((unsigned char*)m->str)[pixel + 1] = m->lst_point->c.green;
		((unsigned char*)m->str)[pixel + 2] = m->lst_point->c.red;
		((unsigned char*)m->str)[pixel + 3] = m->lst_point->c.alpha;
	}
}

void	ft_nb_color(t_my_m *m, int blue, int green, int red)
{
	m->lst_point->c.blue = blue;
	m->lst_point->c.green = green;
	m->lst_point->c.red = red;
}

void	ft_color(t_my_m *m, int z)
{
	int		i;

	i = ft_zmax(m);
	m->lst_point->c.alpha = 0;
	if (z >= 0 && z <= (i / 7))
		ft_nb_color(m, 51, 51, 255);
	else if (z > (i / 7) && z <= 2 * (i / 7))
		ft_nb_color(m, 51, 144, 255);
	else if (z > 2 * (i / 7) && z <= 3 * (i / 7))
		ft_nb_color(m, 56, 225, 255);
	else if (z > 3 * (i / 7) && z <= 4 * (i / 7))
		ft_nb_color(m, 56, 255, 93);
	else if (z > 4 * (i / 7) && z <=  5 * (i / 7))
		ft_nb_color(m, 255, 186, 56);
	else if (z > 5 * (i / 7) && z <= 6 * (i / 7))
		ft_nb_color(m, 255, 56, 156);
	else if (z > 6 * (i / 7) && z <= i)
		ft_nb_color(m, 255, 56, 246);
}

void	ft_segment(t_my_m *m, int x, int y, int x1, int y1, int z)
{
	int		dx;
	int		dy;
	int		sx;
	int		sy;
	int		e;

	dx = x1 - x;
	dy = y1 - y;
	sx = (dx >= 0) ? 1 : -1;
	sy = (dy >= 0) ? 1 : -1;
	dx = abs(2 * dx);
	dy = abs(2 * dy);
	e = (dx > dy) ? dx / 2 : dy / 2;
	if (dx > dy)
	{
		if (sx > 0)
		{
			while (x < x1)
			{
				ft_fill_pixel(m, x, y, z);
				e = e - dy;
				if (e < 0)
				{
					y += sy;
					e = e + dx;
				}
				x += sx;
			}
		}
		else if (sx < 0)
		{
			while (x > x1)
			{
				ft_fill_pixel(m, x, y, z);
				e = e - dy;
				if (e < 0)
				{
					y += sy;
					e = e + dx;
				}
				x += sx;
			}
		}
	}
	else
	{
		if (sy > 0)
		{
			while (y < y1)
			{
				ft_fill_pixel(m, x, y, z);
				e = e - dx;
				if (e < 0)
				{
					x += sx;
					e = e + dy;
				}
				y += sy;
			}
		}
		else if (sy < 0)
		{
			while (y > y1)
			{
				ft_fill_pixel(m, x, y, z);
				e = e - dx;
				if (e < 0)
				{
					x += sx;
					e = e + dy;
				}
				y += sy;
			}
		}
	}
}

void	ft_always(t_my_m *m)
{
	int		i;

	i = 0;
	while (i < (m->l * m->h * 4))
		m->str[i++] = 0;
	ft_fill_image(&m->lst_point, m);
	mlx_put_image_to_window(m->mlx_ptr, m->win_ptr, m->img_ptr, 0, 0);
}

void	ft_fill_image(t_v3 **alst, t_my_m *m)
{
	t_v3	*keep;
	t_v3	*seek;

	keep = (*alst);
	while (keep->next != NULL)
	{
		seek = keep->next;
		while (seek != NULL)
		{
			if ((seek->origin.x == keep->origin.x && seek->origin.y == (keep->origin.y + 1)) || (seek->origin.y == keep->origin.y && seek == keep->next))
			{
				ft_segment(m, keep->point.x + m->offx, keep->point.y + m->offy, seek->point.x + m->offx, seek->point.y + m->offy, keep->zed);
			}
			seek = seek->next;
		}
		keep = keep->next;
	}
	ft_fill_pixel(m, keep->point.x + m->offx,
		keep->point.y + m->offy, keep->zed);
}

int		ft_key(int key, t_my_m *m)
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
	(key == ONE) ? ft_rotation_z(10, m) : 0;
	(key == THREE) ? ft_rotation_z(-10, m) : 0;
	(key == ESC) ? ft_free(m) : 0;
	ft_always(m);
	return (1);
}
