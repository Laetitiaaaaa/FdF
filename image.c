/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llejeune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 15:01:10 by llejeune          #+#    #+#             */
/*   Updated: 2019/02/06 16:10:16 by llejeune         ###   ########.fr       */
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
	int		a;
	int		i;

	i = ft_zmax(m);
	m->lst_point->c.alpha = 0;
	a = (i != 0) ? (z * 360 / i) : 0;
	if (a >= 0 && a <= 120)
		ft_nb_color(m, 0, (a * 255 / 120), (255 - (a * 255 / 120)));
	else if (a > 120 && a <= 240)
		ft_nb_color(m, ((a - 120) * 255 / 120),
				(255 - ((a - 120) * 255 / 120)), 0);
	else if (a > 240 && a <= 360)
		ft_nb_color(m, 0, (255 - ((a - 240) * 255 / 120)),
				((a - 240) * 255 / 120));
}

/*void	ft_segment(t_my_m *m, int x1, int y1, int x2, int y2, int z)
  {
  int		dx;
  int		dy;
  int		sx;
  int		sy;
  float	slope;
  float	pitch;

  dx = x2 - x1;
  sx = (dx < 0) ? -1 : 1;
  dy = y2 - y1;
  sy = (dy < 0) ? -1 : 1;

  if (abs(dy) < abs(dx))
  {
  slope = (dx > 0) ? (dy / dx) : 0;
  pitch = y1 - slope * x1;
  while (x1 != x2)
  {
  ft_fill_pixel(m, x1, (slope * x1 + pitch), z);
  x1 += sx;
  }
  }
  else
  {
  slope = (dy < 0) ? (dx / dy) : 0;
  pitch = x1 - slope * y1;
  while (y1 != y2)
  {
  ft_fill_pixel(m, x1, (slope * y1 + pitch), z);
  y1 += sy;
  }
  }
  }*/

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
	dx = 2 * dx;
	dy = 2 * dy;
	while (x < x1)
	{
		if (dx > dy)
		{
			e = dx / 2;
			ft_fill_pixel(m, x, y, z);
			e = e + dy;
			if (e < 0)
			{
				y += sy;
				e = e + dx;
			}
			else
				x += sx;
		}
		else
		{
			e = dy / 2;
			ft_fill_pixel(m, x, y, z);
			e = e + dx;
			if (e < 0)
			{
				x += sx;
				e = e + dx;
			}
			y += sy;
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
		while (seek->next != NULL)
		{
			if (seek->point.x == keep->point.x)
			{
				printf("keepx = %f\n", keep->point.x);
				printf("seekx = %f\n", seek->point.x);
				printf("keepy = %f\n", keep->point.y);
				printf("seeky = %f\n", keep->point.y);
				printf("\n");
				ft_segment(m, keep->point.x + m->offx, keep->point.y + m->offy, seek->point.x + m->offx, seek->point.y + m->offy, keep->zed);
			}
			seek = seek->next;
		}
		ft_segment(m, keep->point.x + m->offx, keep->point.y + m->offy, keep->next->point.x + m->offx, keep->next->point.y + m->offy, keep->zed);
//		ft_fill_pixel(m, keep->point.x + m->offx,
//			keep->point.y + m->offy, keep->zed);
		keep = keep->next;
	}
//	ft_fill_pixel(m, keep->point.x + m->offx,
//			keep->point.y + m->offy, keep->zed);
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
