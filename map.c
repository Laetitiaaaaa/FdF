/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llejeune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 13:10:46 by llejeune          #+#    #+#             */
/*   Updated: 2019/03/04 17:38:09 by llejeune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_open(char *av, t_my_m *m)
{
	m->fd = open(av, O_RDONLY);
	if (m->fd < 0)
		return (1);
	return (0);
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

int		ft_check_map(char *line)
{
	int		i;

	i = 0;
	while (line[i] != 0)
	{
		if ((line[i] > 45 && line[i] < 48) || line[i] == 44 || (line[i] > 32
					&& line[i] < 43) || (line[i] > 57 && line[i] <= 127)
				|| (line[i] >= 0 && line[i] < 32))
		{
			free(line);
			ft_putstr("Invalid character.\n");
			return (1);
		}
		i++;
	}
	return (0);
}

void	ft_init_map(t_v3 **alst, t_my_m *m)
{
	(*alst)->point.x = m->i;
	(*alst)->point.y = m->c;
	(*alst)->point.z = ft_atoi(m->tmp[m->i]);
	(*alst)->zed = ft_atoi(m->tmp[m->i]);
	(*alst)->origin = (*alst)->point;
}

void	ft_map(int *fd, t_my_m *m)
{
	char	*line;
	t_v3	*new_node;

	m->c = 0;
	while (get_next_line(*fd, &line) > 0)
	{
		if (!(m->tmp = ft_strsplit(line, ' ')) || ft_check_map(line) == 1)
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
}
