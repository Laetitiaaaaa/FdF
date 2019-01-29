/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llejeune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 15:01:10 by llejeune          #+#    #+#             */
/*   Updated: 2019/01/29 09:18:20 by llejeune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_fill_pixel(my_m *m, float x, float y)
{
	int			pixel;

	pixel = 4 * (x + (m->l * y));
	((unsigned char*)m->str)[pixel] = m->lst_point->c.blue;
	((unsigned char*)m->str)[pixel + 1] = m->lst_point->c.green;
	((unsigned char*)m->str)[pixel + 2] = m->lst_point->c.red;
	((unsigned char*)m->str)[pixel + 3] = m->lst_point->c.alpha;
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
	t_v3 *keep;

	keep = m->lst_point;
	/*while (keep != NULL)
	{
		keep->c.alpha = 255;
		keep = keep->next;
	}*/
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
			ft_fill_pixel(m, keep->point.x, keep->point.y);
			keep = keep->next;
		}
	}
}

int		ft_key(int key, my_m *m)
{
	if (key == P)
		ft_zoom(&m->lst_point, m, 2);
	if (key == M)
		ft_zoom(&m->lst_point, m, 0.5);
	if (key == F_H)
		ft_translation(m, 0, -10, 0);
	if (key == F_B)
		ft_translation(m, 0, 10, 0);
	if (key == F_G)
		ft_translation(m, -10, 0, 0);
	if (key == F_D)
		ft_translation(m, 10, 0, 0);
	if (key == TWO)
		ft_rotation_x(0.01, m);
	if (key == ESC)
		exit(0);
	return (1);
}

