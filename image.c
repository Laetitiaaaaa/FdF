/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llejeune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 15:01:10 by llejeune          #+#    #+#             */
/*   Updated: 2019/01/25 19:25:01 by llejeune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_fill_pixel(my_m *m, float x, float y)
{
	int		pixel;

	pixel = 4 * (x + (800 * y));
	((unsigned char*)m->str)[pixel] = 255;
	((unsigned char*)m->str)[pixel + 1] = 0;
	((unsigned char*)m->str)[pixel + 2] = 255;
	((unsigned char*)m->str)[pixel + 3] = 0;
}

void	ft_always(my_m *m)
{
	mlx_clear_window(m->mlx_ptr, m->win_ptr);
	ft_fill_image(&m->lst_point, m);
	mlx_put_image_to_window(m->mlx_ptr, m->win_ptr, m->img_ptr, 400, 300);
}

void	ft_fill_image(t_v3 **alst, my_m *m)
{
	t_v3	*keep;

	keep = (*alst);
	if (keep != NULL)
	{
		while (keep != NULL)
		{
			ft_fill_pixel(m, keep->point.x, keep->point.y);
			keep = keep->next;
		}
	}
}

int		ft_key(int key, my_m *m)
{
	if (key == F_H)
		ft_zoom(&m->lst_point, m, 2);
	if (key == F_B)
		ft_zoom(&m->lst_point, m, 0.5);
	if (key == ESC)
		exit(0);
	return (1);
}

