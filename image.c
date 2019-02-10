/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llejeune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 15:01:10 by llejeune          #+#    #+#             */
/*   Updated: 2019/02/10 18:39:28 by llejeune         ###   ########.fr       */
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
	if (z < 0)
		ft_nb_color(m, 229, 9, 22);
	else if (z >= 0 && z <= (i / 7))
		ft_nb_color(m, 51, 51, 255);
	else if (z > (i / 7) && z <= 2 * (i / 7))
		ft_nb_color(m, 51, 144, 255);
	else if (z > 2 * (i / 7) && z <= 3 * (i / 7))
		ft_nb_color(m, 56, 225, 255);
	else if (z > 3 * (i / 7) && z <= 4 * (i / 7))
		ft_nb_color(m, 56, 255, 93);
	else if (z > 4 * (i / 7) && z <= 5 * (i / 7))
		ft_nb_color(m, 255, 186, 56);
	else if (z > 5 * (i / 7) && z <= 6 * (i / 7))
		ft_nb_color(m, 255, 56, 156);
	else if (z > 6 * (i / 7) && z <= i)
		ft_nb_color(m, 255, 56, 246);
}

void	ft_init_bress(t_my_m *m, t_v3 **alst, t_v3 **next)
{
	m->x = (*alst)->point.x + m->offx;
	m->y = (*alst)->point.y + m->offy;
	m->x1 = (*next)->point.x + m->offx;
	m->y1 = (*next)->point.y + m->offy;
	m->dx = m->x1 - m->x;
	m->dy = m->y1 - m->y;
	m->sx = (m->dx >= 0) ? 1 : -1;
	m->sy = (m->dy >= 0) ? 1 : -1;
	m->dx = abs(2 * m->dx);
	m->dy = abs(2 * m->dy);
	m->e = (m->dx > m->dy) ? m->dx / 2 : m->dy / 2;
}

void	ft_bress_x(t_my_m *m, int z)
{
	ft_fill_pixel(m, m->x, m->y, z);
	m->e = m->e - m->dy;
	if (m->e < 0)
	{
		m->y += m->sy;
		m->e = m->e + m->dx;
	}
	m->x += m->sx;
}

void	ft_bress_y(t_my_m *m, int z)
{
	ft_fill_pixel(m, m->x, m->y, z);
	m->e = m->e - m->dx;
	if (m->e < 0)
	{
		m->x += m->sx;
		m->e = m->e + m->dy;
	}
	m->y += m->sy;
}

void	ft_segment(t_my_m *m, t_v3 **alst, t_v3 **next, int z)
{
	ft_init_bress(m, alst, next);
	if (m->dx > m->dy)
	{
		while (m->x < m->x1 && m->sx > 0)
			ft_bress_x(m, z);
		while (m->x > m->x1 && m->sx < 0)
			ft_bress_x(m, z);
	}
	else
	{
		while (m->y < m->y1 && m->sy > 0)
			ft_bress_y(m, z);
		while (m->y > m->y1 && m->sy < 0)
			ft_bress_y(m, z);
	}
}

void	ft_always(t_my_m *m)
{
	int		i;

	i = 0;
	while (i < (m->l * m->h * 4))
		m->str[i++] = 0;
	ft_fill_image(m);
	if (!(mlx_put_image_to_window(m->mlx_ptr, m->win_ptr, m->img_ptr, 0, 0)))
		ft_free(m);
}

void	ft_fill_image(t_my_m *m)
{
	t_v3	*keep;
	t_v3	*seek;

	keep = m->lst_point;
	while (keep->next != NULL)
	{
		seek = keep->next;
		while (seek != NULL)
		{
			if ((seek->origin.x == keep->origin.x &&
						seek->origin.y == (keep->origin.y + 1)) ||
					(seek->origin.y == keep->origin.y && seek == keep->next))
			{
				ft_segment(m, &keep, &seek, keep->zed);
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
	(key == PLUS) ? ft_zoom(&m->lst_point, m, 2) : 0;
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
	(key == P) ? ft_perspective(m) : 0;
	(key == ESC) ? ft_free(m) : 0;
	ft_always(m);
	return (1);
}
