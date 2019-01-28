/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llejeune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 15:05:02 by llejeune          #+#    #+#             */
/*   Updated: 2019/01/28 16:04:21 by llejeune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_zoom(t_v3 **lst_point, my_m *m, float i)
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
	while (keep != NULL && keep->point.x < m->l && keep->point.y < m->h)
	{
		ft_mult_1_3(&keep, &m->mat);
		keep = keep->next;
	}
	ft_always(m);
}

//void		ft_rotation()

void		ft_translation(my_m *m, float x, float y, float z)
{
	t_v3	*keep;

	keep = m->lst_point;
	if (keep != NULL)
	{
		while (keep != NULL)
		{
			keep->point.x = keep->point.x + x;
			keep->point.y = keep->point.y + y;
			keep->point.z = keep->point.z + z;
			keep = keep->next;
		}
		ft_always(m);
	}
}

matrice		ft_mult_3_3(matrice *mat, matrice *mat1)
{
	matrice		new;

	new.tab[0][0] = mat->tab[0][0] * mat1->tab[0][0] + mat->tab[0][1] * mat1->tab[1][0] + mat->tab[0][2] * mat1->tab[2][0];
	new.tab[0][1] = mat->tab[0][0] * mat1->tab[0][1] + mat->tab[0][1] * mat1->tab[1][1] + mat->tab[0][2] * mat1->tab[1][2];
	new.tab[0][2] = mat->tab[0][0] * mat1->tab[0][2] + mat->tab[0][1] * mat1->tab[1][2] + mat->tab[0][2] * mat1->tab[2][2];
	new.tab[1][0] = mat->tab[1][0] * mat1->tab[0][0] + mat->tab[1][1] * mat1->tab[1][0] + mat->tab[1][2] * mat1->tab[2][0];
	new.tab[1][1] = mat->tab[1][0] * mat1->tab[0][1] + mat->tab[1][1] * mat1->tab[1][1] + mat->tab[1][2] * mat1->tab[2][0];
	new.tab[1][2] = mat->tab[1][0] * mat1->tab[0][2] + mat->tab[1][1] * mat1->tab[1][2] + mat->tab[1][2] * mat1->tab[2][2];
	new.tab[2][0] = mat->tab[2][0] * mat1->tab[0][0] + mat->tab[2][1] * mat1->tab[1][0] + mat->tab[2][2] * mat1->tab[2][0];
	new.tab[2][1] = mat->tab[2][0] * mat1->tab[0][1] + mat->tab[2][1] * mat1->tab[1][1] + mat->tab[2][2] * mat1->tab[2][0];
	new.tab[2][2] = mat->tab[2][0] * mat1->tab[0][2] + mat->tab[2][1] * mat1->tab[1][2] + mat->tab[2][2] * mat1->tab[2][2];
	return (new);
}

void	ft_mult_1_3(t_v3 **alst, matrice *mat)
{
	(*alst)->save.x = (*alst)->point.x;
	(*alst)->save.y = (*alst)->point.y;
	(*alst)->save.z = (*alst)->point.z;
	(*alst)->point.x = mat->tab[0][0] * (*alst)->save.x + mat->tab[0][1] * (*alst)->save.y + mat->tab[0][2] * (*alst)->save.z;
	(*alst)->point.y = mat->tab[1][0] * (*alst)->save.x + mat->tab[1][1] * (*alst)->save.y + mat->tab[1][2] * (*alst)->save.z;
	(*alst)->point.z = mat->tab[2][0] * (*alst)->save.x + mat->tab[2][1] * (*alst)->save.y + mat->tab[2][2] * (*alst)->save.z;
}
