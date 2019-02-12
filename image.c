/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llejeune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 15:01:10 by llejeune          #+#    #+#             */
/*   Updated: 2019/02/12 08:50:29 by llejeune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_fill_pixel(t_my_m *m, int x, int y, int z)
{
	int			pixel;

	ft_color(m, z);
	pixel = 4 * (x + (m->l * y));
	if (x < m->l && x >= 0 && y < m->h && y >= 0 &&
			pixel < (4 * m->l * m->h) && pixel >= 0)
	{
		((unsigned char*)m->str)[pixel] = m->lst_point->c.blue;
		((unsigned char*)m->str)[pixel + 1] = m->lst_point->c.green;
		((unsigned char*)m->str)[pixel + 2] = m->lst_point->c.red;
		((unsigned char*)m->str)[pixel + 3] = m->lst_point->c.alpha;
	}
}

int		ft_zmax(t_my_m *m)
{
	int		zmax;
	t_v3	*keep;

	zmax = 0;
	keep = m->lst_point;
	while (keep != NULL)
	{
		if (keep->zed > zmax)
			zmax = keep->zed;
		keep = keep->next;
	}
	return (zmax);
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

void	ft_fill_image(t_my_m *m)
{
	t_v3	*keep;

	keep = m->lst_point;
	if (keep == NULL)
	{
		ft_putstr("File is empty.\n");
		ft_free(m);
	}
	while (keep->next != NULL)
	{
		m->seek = keep->next;
		while (m->seek != NULL)
		{
			if ((m->seek->origin.x == keep->origin.x && m->seek->origin.y ==
				(keep->origin.y + 1)) || (m->seek->origin.y == keep->origin.y &&
					m->seek == keep->next))
				ft_segment(m, &keep, &m->seek, keep->zed);
			m->seek = m->seek->next;
		}
		keep = keep->next;
	}
	ft_fill_pixel(m, keep->point.x + m->offx,
			keep->point.y + m->offy, keep->zed);
}
