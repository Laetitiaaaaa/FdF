/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llejeune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 15:05:02 by llejeune          #+#    #+#             */
/*   Updated: 2019/01/25 20:40:45 by llejeune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_zoom(t_v3 **lst_point, my_m *m, float i)
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
	ft_always(m);
}

mat		ft_mult_3_3(mat *mat, mat *mat1)
{
	mat		new;

	new[0][0] = mat->tab[0][0] * mat1->tab[0][0] + mat->tab[0][1] * mat1->tab[1][0] + mat->tab[0][2] * mat1->tab[2][0];
	new[0][1] = mat->tab[0][0] * mat1->tab[0][1] + mat->tab[0][1] * mat1->tab[1][1] + mat->tab[0][2] * mat1->tab[1][2];
	new[0][2] = mat->tab[0][0] * mat1->tab[0][2] + mat->tab[0][1] * mat1->tab[1][2] + mat->tab[0][2] * mat1->tab[2][2];
	new[1][0] = mat->tab[1][0] * mat1->tab[0][0] + mat->tab[1][1] * mat1->tab[1][0] + mat->tab[1][2] * mat1->tab[2][0];
	new[1][1] = mat->tab[1][0] * mat1->tab[0][1] + mat->tab[1][1] * mat1->tab[1][1] + mat->tab[1][2] * mat1->tab[2][0];
	new[1][2] = mat->tab[1][0] * mat1->tab[0][2] + mat->tab[1][1] * mat1->tab[1][2] + mat->tab[1][2] * mat1->tab[2][2];
	new[2][0] = mat->tab[2][0] * mat1->tab[0][0] + mat->tab[2][1] * mat1->tab[1][0] + mat->tab[2][2] * mat1->tab[2][0];
	new[2][1] = mat->tab[2][0] * mat1->tab[0][1] + mat->tab[2][1] * mat1->tab[1][1] + mat->tab[2][2] * mat1->tab[2][0];
	new[2][2] = mat->tab[2][0] * mat1->tab[0][2] + mat->tab[2][1] * mat1->tab[1][2] + mat->tab[2][2] * mat1->tab[2][2];
	return (new);
}

void	ft_mult_1_3(t_v3 **alst, mat *mat)
{
	(*alst)->save.x = (*alst)->point.x;
	(*alst)->save.y = (*alst)->point.y;
	(*alst)->save.z = (*alst)->point.z;
	(*alst)->point.x = mat->tab[0][0] * (*alst)->save.x + mat->tab[0][1] * (*alst)->save.y + mat->tab[0][2] * (*alst)->save.z;
	(*alst)->point.y = mat->tab[1][0] * (*alst)->save.x + mat->tab[1][1] * (*alst)->save.y + mat->tab[1][2] * (*alst)->save.z;
	(*alst)->point.z = mat->tab[2][0] * (*alst)->save.x + mat->tab[2][1] * (*alst)->save.y + mat->tab[2][2] * (*alst)->save.z;
}
