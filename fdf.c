/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llejeune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 16:03:20 by llejeune          #+#    #+#             */
/*   Updated: 2019/01/28 16:04:53 by llejeune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_map(int *fd, my_m *m)
{
	char	*line;
	char	**tmp;
	t_v3	*new_node;

	if (!(line = (char *)malloc(sizeof(char) * (m->l + 1))))
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

int		main(int ac, char **av)
{
	my_m	m;
	int		fd;

	ac = 2;
	m.l = 800;
	m.h = 600;
	m.lst_point = NULL;
	fd = open(av[1], O_RDONLY);
	m.mlx_ptr = mlx_init();
	m.win_ptr = mlx_new_window(m.mlx_ptr, m.l, m.h, "FdF");
	m.img_ptr = mlx_new_image(m.mlx_ptr, m.l, m.h);
	printf("A\n");
	m.str = mlx_get_data_addr(m.img_ptr, &(m.bpp), &(m.s_l), &(m.endian));
	printf("B\n");
	ft_map(&fd, &m);
	printf("C\n");
	ft_fill_image(&m.lst_point, &m);
	printf("D\n");
	mlx_put_image_to_window(m.mlx_ptr, m.win_ptr, m.img_ptr, 0, 0);
	printf("E\n");
	mlx_key_hook(m.win_ptr, ft_key, &m);
	printf("F\n");
	mlx_loop(m.mlx_ptr);
	printf("G\n");
	return (0);
}
