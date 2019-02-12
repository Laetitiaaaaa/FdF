/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llejeune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 13:05:50 by llejeune          #+#    #+#             */
/*   Updated: 2019/02/11 13:07:06 by llejeune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
