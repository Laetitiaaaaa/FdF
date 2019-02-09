/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llejeune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 16:03:20 by llejeune          #+#    #+#             */
/*   Updated: 2019/02/09 09:35:05 by llejeune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

void	ft_check_map(char *line)
{
	int		i;

	i = 0;
	while (line[i] != 0)
	{
		if ((line[i] > 46 && line[i] < 48) || line[i] == 44 || (line[i] > 32 &&
					line[i] < 43) || (line[i] > 57 && line[i] < 127))
			exit(0);
		i++;
	}
}

void	ft_init_map(t_v3 **alst, t_my_m *m)
{
	(*alst)->point.x = m->i;
	(*alst)->point.y = m->c;
	(*alst)->point.z = (ft_atoi(m->tmp[m->i]) >= 0) ? ft_atoi(m->tmp[m->i])
		: -(ft_atoi(m->tmp[m->i]));
	(*alst)->zed = (ft_atoi(m->tmp[m->i]) >= 0) ? ft_atoi(m->tmp[m->i])
		: -(ft_atoi(m->tmp[m->i]));
	(*alst)->origin = (*alst)->point;
}

void	ft_map(int *fd, t_my_m *m)
{
	char	*line;
	t_v3	*new_node;

	m->c = 0;
	while (get_next_line(*fd, &line) > 0)
	{
		ft_check_map(line);
		if (!(m->tmp = ft_strsplit(line, ' ')))
			ft_free(m);
		m->i = 0;
		while (m->tmp[m->i] != 0)
		{
			if (!(new_node = ft_new_node(new_node)))
				ft_free(m);
			ft_init_map(&new_node, m);
			ft_add_node(&m->lst_point, new_node);
			free(m->tmp[m->i]);
			m->i++;
		}
		free(m->tmp);
		m->c++;
		free(line);
	}
	free(line);
}

void	ft_free(t_my_m *m)
{
	t_v3 *keep;

	while (m->lst_point != NULL)
	{
		keep = m->lst_point;
		m->lst_point = m->lst_point->next;
		free(keep);
	}
	close(m->fd);
	exit(0);
}

int		ft_open(char *av, t_my_m *m)
{
	m->fd = open(av, O_RDONLY);
	if (m->fd > 0)
		return (0);
	return (1);
}

int		ft_init_mlx(t_my_m *m)
{
	m->l = M_L;
	m->h = M_H;
	if (m->l < 0 || m->h < 0)
		return (1);
	m->offx = 0;
	m->offy = 0;
	m->lst_point = NULL;
	if (!(m->mlx_ptr = mlx_init()))
		return (1);
	if (!(m->win_ptr = mlx_new_window(m->mlx_ptr, m->l, m->h, "FdF")))
		return (1);
	if (!(m->img_ptr = mlx_new_image(m->mlx_ptr, m->l, m->h)))
		return (1);
	if (!(m->str = mlx_get_data_addr(m->img_ptr, &(m->bpp),
					&(m->s_l), &(m->endian))))
		return (1);
	return (0);
}

int		main(int ac, char **av)
{
	t_my_m	m;

	ac = 2;
	if (ft_open(av[1], &m) == 1 || ft_init_mlx(&m) == 1)
	{
		ft_putstr("error\n");
		exit(0);
	}
	printf("A\n");
	ft_map(&m.fd, &m);
	printf("B\n");
	ft_always(&m);
	printf("C\n");
	if (!(mlx_hook(m.win_ptr, 2, 0, ft_key, &m)))
		ft_free(&m);
	printf("D\n");
	ft_get_leaks("fdf", "end of everything");
	if (!(mlx_loop(m.mlx_ptr)))
		ft_free(&m);
	printf("E\n");
	return (0);
}
