/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llejeune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 16:03:20 by llejeune          #+#    #+#             */
/*   Updated: 2019/01/23 14:16:37 by llejeune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fdf.h"

t_list	*ft_new_node(t_list *new_node)
{
	if (!(new_node = (t_list *)malloc(sizeof(t_list))))
		return (0);
	new_node->point.x = 0;
	new_node->point.y = 0;
	new_node->point.z = 0;
	new_node->next = NULL;
	return (new_node);
}

void	ft_add_node(t_list **alst, t_list *new_node)
{
	if ((*alst) != NULL && new_node != NULL)
	{
		while ((*alst)->next != NULL)
			(*alst) = (*alst)->next;
		(*alst)->next = new_node;
	}
	else if ((*alst) == NULL)
	{
		(*alst) = new_node;
	}
}

void	ft_map(int *fd)
{
	int		i;
	int		c;
	char	**line;
	char	**tmp;
	t_list	*new_node;

	if (fd < 0)
		return ;
	c = 0;
	while (get_next_line(*fd, line) > 0)
	{
		tmp = ft_strsplit(line, ' ');
		i = 0;
		while (*tmp[i] != 0)
		{
			new_node = ft_new_node(new_node);
			new_node->point.x = i;
			new_node->point.y = c;
			new_node->point.z = ((int)*tmp)[i] - 48;
			i++;
		}
		c++;
	}
}

void	ft_fill_pixel(my_m *m)
{
	int		pixel;

	m->x = 400;
	m->y = 300;
	pixel = 4 * (m->x + (800 * m->y));
	m->str[pixel] = 0;
	m->str[pixel + 1] = 0;
	m->str[pixel + 2] = 0xff;
	m->str[pixel + 3] = 0;
}

int		main(int ac, char **av)
{
	my_m	m;
	int		fd;

	ac = 2;
	fd = (av[1], O_RDONLY);
	m.mlx_ptr = mlx_init();
	m.win_ptr = mlx_new_window(m.mlx_ptr, 800, 600, "FdF");
	m.img_ptr = mlx_new_image(m.mlx_ptr, 800, 600);
	m.str = mlx_get_data_addr(m.img_ptr, &(m.bpp), &(m.s_l), &(m.endian));
	ft_fill_pixel(&m);
	mlx_put_image_to_window(m.mlx_ptr, m.win_ptr, m.img_ptr, 0, 0);
	mlx_loop(m.mlx_ptr);
	return (0);
}
