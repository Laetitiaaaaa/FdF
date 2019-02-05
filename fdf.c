/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llejeune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 16:03:20 by llejeune          #+#    #+#             */
/*   Updated: 2019/02/05 17:11:31 by llejeune         ###   ########.fr       */
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
		if ((line[i] > 32 && line[i] < 48) || (line[i] > 57 && line[i] < 127))
			exit(0);
		i++;
	}
}

void	ft_map(int *fd, t_my_m *m)
{
	char	*line;
	char	**tmp;
	t_v3	*new_node;

	m->c = 0;
	while (get_next_line(*fd, &line) > 0)
	{
		ft_check_map(line);
		tmp = ft_strsplit(line, ' ');
		m->i = 0;
		while (tmp[m->i] != 0)
		{
			new_node = ft_new_node(new_node);
			new_node->point.x = m->i * 10;
			new_node->point.y = m->c * 10;
			new_node->point.z = ft_atoi(tmp[m->i]) * 10;
			new_node->zed = ft_atoi(tmp[m->i]);
			ft_add_node(&m->lst_point, new_node);
			free(tmp[m->i]);
			m->i++;
		}
		free(tmp);
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
		return (1);
	return (0);
}

int		ft_init_mlx(t_my_m *m)
{
	m->l = M_L;
	m->h = M_H;
	if (m->l < 0 || m->h < 0)
		return (0);
	m->offx = 0;
	m->offy = 0;
	m->lst_point = NULL;
	m->mlx_ptr = mlx_init();
	m->win_ptr = mlx_new_window(m->mlx_ptr, m->l, m->h, "FdF");
	m->img_ptr = mlx_new_image(m->mlx_ptr, m->l, m->h);
	m->str = mlx_get_data_addr(m->img_ptr, &(m->bpp), &(m->s_l), &(m->endian));
	return (1);
}

int		main(int ac, char **av)
{
	t_my_m	m;

	ac = 2;
	ft_open(av[1], &m);
	printf("O\n");
	ft_init_mlx(&m);
	printf("A\n");
	ft_map(&m.fd, &m);
	printf("B\n");
	ft_always(&m);
	printf("C\n");
	mlx_hook(m.win_ptr, 2, 0, ft_key, &m);
	printf("D\n");
	mlx_loop(m.mlx_ptr);
	printf("E\n");
	return (0);
}
