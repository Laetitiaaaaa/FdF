/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llejeune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 16:03:20 by llejeune          #+#    #+#             */
/*   Updated: 2019/01/24 19:31:21 by llejeune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fdf.h"
#include <stdio.h>

t_v3	*ft_new_node(t_v3 *new_node)
{
	if (!(new_node = malloc(sizeof(t_v3))))
		return (0);
	new_node->point.x = 0;
	new_node->point.y = 0;
	new_node->point.z = 0;
	new_node->next = NULL;
	return (new_node);
}

void	ft_add_node(t_v3 **alst, t_v3 *new_node)
{
	t_v3	*keep;

	keep = (*alst);
	if (keep != NULL && new_node != NULL)
	{
		while (keep->next != NULL)
			keep = keep->next;
		keep->next = new_node;
	}
	if ((*alst) == NULL)
		(*alst) = new_node;
}

void	ft_map(int *fd, my_m *m)
{
	char	*line;
	char	**tmp;
	t_v3	*new_node;

	if (!(line = (char *)malloc(sizeof(char) * 100)))
		return ;
	if (fd < 0)
		return ;
	m->c = 0;
	while (get_next_line(*fd, &line) > 0)
	{
		tmp = ft_strsplit(line, ' ');
		m->i = 0;
		while (tmp[m->i] != 0)
		{
			new_node = ft_new_node(new_node);
			new_node->point.x = m->i;
			new_node->point.y = m->c;
			new_node->point.z = ft_atoi(tmp[m->i]);
			ft_add_node(&m->lst_point, new_node);
			m->i++;
		}
		m->c++;
	}
}

void	ft_fill_pixel_black(my_m *m, float x, float y)
{
	int		pixel;

	pixel = 4 * (x + (800 * y));
	m->str[pixel] = 0;
	m->str[pixel + 1] = 0;
	m->str[pixel + 2] = 0;
	m->str[pixel + 3] = 0;
}

void	ft_fill_pixel(my_m *m, float x, float y)
{
	int		pixel;

	pixel = 4 * (x + (800 * y));
	m->str[pixel] = 0;
	m->str[pixel + 1] = 255;
	m->str[pixel + 2] = 0;
	m->str[pixel + 3] = 0;
}

void	ft_always(my_m *m)
{
	ft_black_image(&m->lst_point, m);
	ft_fill_image(&m->lst_point, m);
	mlx_put_image_to_window(m->mlx_ptr, m->win_ptr, m->img_ptr, 400, 300);
}

void	ft_black_image(t_v3 **alst, my_m *m)
{
	t_v3	*keep;

	keep = (*alst);
	if (keep != NULL)
	{
		while (keep != NULL)
		{
			printf("bla\n");
			ft_fill_pixel_black(m, keep->save.x, keep->save.y);
			keep = keep->next;
		}
	}
}

void	ft_fill_image(t_v3 **alst, my_m *m)
{
	t_v3	*keep;

	keep = (*alst);
	if (keep != NULL)
	{
		while (keep != NULL)
		{
			printf("bla\n");
			ft_fill_pixel(m, keep->point.x, keep->point.y);
			keep = keep->next;
		}
	}
}

void	ft_zoom(t_v3 **lst_point, my_m *m, float i)
{
	t_v3 *keep;

	keep = (*lst_point);
	while (keep != NULL)
	{
		keep->save.x = keep->point.x;
		keep->save.y = keep->point.y;
		keep->save.z = keep->point.z;
		keep->point.x = keep->point.x * i;
		keep->point.y = keep->point.y * i;
		keep->point.z = keep->point.z * i;
		keep = keep->next;
	}
	ft_always(m);
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

int		main(int ac, char **av)
{
	my_m	m;
	int		fd;

	ac = 2;
	m.lst_point = NULL;
	fd = open(av[1], O_RDONLY);
	m.mlx_ptr = mlx_init();
	m.win_ptr = mlx_new_window(m.mlx_ptr, 800, 600, "FdF");
	m.img_ptr = mlx_new_image(m.mlx_ptr, 800, 600);
	m.str = mlx_get_data_addr(m.img_ptr, &(m.bpp), &(m.s_l), &(m.endian));
	ft_map(&fd, &m);
	ft_fill_image(&m.lst_point, &m);
//	ft_fill_pixel(&m, 400, 300);
	mlx_put_image_to_window(m.mlx_ptr, m.win_ptr, m.img_ptr, 400, 300);
	mlx_key_hook(m.win_ptr, ft_key, &m);
	mlx_loop(m.mlx_ptr);
	return (0);
}
