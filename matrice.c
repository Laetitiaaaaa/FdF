/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llejeune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 15:05:02 by llejeune          #+#    #+#             */
/*   Updated: 2019/02/10 18:43:15 by llejeune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_zoom(t_v3 **lst_point, t_my_m *m, float i)
{
	t_v3 *keep;

	keep = (*lst_point);
	m->mat.tab[0][0] = i;
	m->mat.tab[0][1] = 0;
	m->mat.tab[0][2] = 0;
	m->mat.tab[1][0] = 0;
	m->mat.tab[1][1] = i;
	m->mat.tab[1][2] = 0;
	m->mat.tab[2][0] = 0;
	m->mat.tab[2][1] = 0;
	m->mat.tab[2][2] = i;
	while (keep != NULL)
	{
		ft_mult_1_3(&keep, &m->mat);
		keep = keep->next;
	}
}

void		ft_rotation_x(float angle, t_my_m *m)
{
	t_v3	*keep;

	keep = m->lst_point;
	m->rot.tab[0][0] = 1;
	m->rot.tab[0][1] = 0;
	m->rot.tab[0][2] = 0;
	m->rot.tab[1][0] = 0;
	m->rot.tab[1][1] = cos(angle * M_PI / 180);
	m->rot.tab[1][2] = -sin(angle * M_PI / 180);
	m->rot.tab[2][0] = 0;
	m->rot.tab[2][1] = sin(angle * M_PI / 180);
	m->rot.tab[2][2] = cos(angle * M_PI / 180);
	while (keep != NULL)
	{
		ft_mult_1_3(&keep, &m->rot);
		keep = keep->next;
	}
}

void		ft_rotation_y(float angle, t_my_m *m)
{
	t_v3	*keep;

	keep = m->lst_point;
	m->rot.tab[0][0] = cos(angle * M_PI / 180);
	m->rot.tab[0][1] = 0;
	m->rot.tab[0][2] = sin(angle * M_PI / 180);
	m->rot.tab[1][0] = 0;
	m->rot.tab[1][1] = 1;
	m->rot.tab[1][2] = 0;
	m->rot.tab[2][0] = -sin(angle * M_PI / 180);
	m->rot.tab[2][1] = 0;
	m->rot.tab[2][2] = cos(angle * M_PI / 180);
	while (keep != NULL)
	{
		ft_mult_1_3(&keep, &m->rot);
		keep = keep->next;
	}
}

void		ft_rotation_z(float angle, t_my_m *m)
{
	t_v3	*keep;

	keep = m->lst_point;
	m->rot.tab[0][0] = cos(angle * M_PI / 180);
	m->rot.tab[0][1] = -sin(angle * M_PI / 180);
	m->rot.tab[0][2] = 0;
	m->rot.tab[1][0] = sin(angle * M_PI / 180);
	m->rot.tab[1][1] = cos(angle * M_PI / 180);
	m->rot.tab[1][2] = 0;
	m->rot.tab[2][0] = 0;
	m->rot.tab[2][1] = 0;
	m->rot.tab[2][2] = 1;
	while (keep != NULL)
	{
		ft_mult_1_3(&keep, &m->rot);
		keep = keep->next;
	}
}

void		ft_perspective(t_my_m *m)
{
	t_v3	*keep;

	keep = m->lst_point;
	while (keep != NULL)
	{
		keep->point.x = (keep->point.z != 0) ? (keep->point.x / keep->point.z)
			: keep->point.x;
		keep->point.y = (keep->point.z != 0) ? (keep->point.y / keep->point.z)
			: keep->point.y;
		keep = keep->next;
	}
}

void		ft_mult_1_3(t_v3 **alst, t_matrice *mat)
{
	(*alst)->save.x = (*alst)->point.x;
	(*alst)->save.y = (*alst)->point.y;
	(*alst)->save.z = (*alst)->point.z;
	(*alst)->point.x = mat->tab[0][0] * (*alst)->save.x + mat->tab[0][1] *
		(*alst)->save.y + mat->tab[0][2] * (*alst)->save.z;
	(*alst)->point.y = mat->tab[1][0] * (*alst)->save.x + mat->tab[1][1] *
		(*alst)->save.y + mat->tab[1][2] * (*alst)->save.z;
	(*alst)->point.z = mat->tab[2][0] * (*alst)->save.x + mat->tab[2][1] *
		(*alst)->save.y + mat->tab[2][2] * (*alst)->save.z;
}
