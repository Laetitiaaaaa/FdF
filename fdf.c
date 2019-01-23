/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llejeune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 16:03:20 by llejeune          #+#    #+#             */
/*   Updated: 2019/01/23 20:16:35 by llejeune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fdf.h"
#include <stdio.h>

t_v3	*ft_new_node(t_v3 *new_node)
{
	printf("c\n");
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

	printf("b\n");
	keep = (*alst);
	printf("ahhhhh\n");
	if (keep != NULL && new_node != NULL)
	{
		printf("non\n");
		while (keep->next != NULL)
			keep = keep->next;
		keep->next = new_node;
	}
	if ((*alst) == NULL)
	{
		printf("arg\n");
		(*alst) = new_node;
	}
	printf("bla\n");
}

void	ft_map(int *fd, t_v3 **lst_point, my_m *m)
{
	char	*line;
	char	**tmp;
	t_v3	*new_node;

	printf("d\n");
	if (!(line = (char *)malloc(sizeof(char) * 100)))
		return ;
	if (fd < 0)
		return ;
	printf("d\n");
	m->c = 0;
	while (get_next_line(*fd, &line) > 0)
	{
		tmp = ft_strsplit(line, ' ');
		m->i = 0;
		while (*tmp[m->i] != 0)
		{
			new_node = ft_new_node(new_node);
			new_node->point.x = m->i;
			new_node->point.y = m->c;
			new_node->point.z = ft_atoi(tmp[m->i]);
			ft_add_node(lst_point, new_node);
			m->i++;
		}
		m->c++;
	}
}

void	ft_fill_pixel(my_m *m, int x, int y)
{
	int		pixel;

	pixel = 4 * (x + (800 * y));
	m->str[pixel] = 0;
	m->str[pixel + 1] = 0;
	m->str[pixel + 2] = 0xff;
	m->str[pixel + 3] = 0;
}

void	ft_fill_image(t_v3 **alst, my_m *m)
{
	while ((*alst) != NULL)
	{
		printf("a\n");
		ft_fill_pixel(m, (*alst)->point.x, (*alst)->point.y);
		(*alst) = (*alst)->next;
	}
}

int		main(int ac, char **av)
{
	my_m	m;
	int		fd;
	t_v3	**lst_point;

	(void)av;
	ac = 2;
	lst_point = NULL;
	printf("A\n");
	fd = open(av[1], O_RDONLY);
	printf("B\n");
	m.mlx_ptr = mlx_init();
	printf("C\n");
	m.win_ptr = mlx_new_window(m.mlx_ptr, 800, 600, "FdF");
	printf("D\n");
	m.img_ptr = mlx_new_image(m.mlx_ptr, 800, 600);
	printf("E\n");
	m.str = mlx_get_data_addr(m.img_ptr, &(m.bpp), &(m.s_l), &(m.endian));
	printf("F\n");
	ft_map(&fd, lst_point, &m);
	printf("F\n");
	ft_fill_image(lst_point, &m);
	printf("G\n");
//	ft_fill_pixel(&m, 400, 300);
	mlx_put_image_to_window(m.mlx_ptr, m.win_ptr, m.img_ptr, 0, 0);
	printf("H\n");
	mlx_loop(m.mlx_ptr);
	printf("I\n");
	return (0);
}
