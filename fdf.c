/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llejeune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 16:03:20 by llejeune          #+#    #+#             */
/*   Updated: 2019/01/23 15:51:20 by llejeune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fdf.h"

/*t_list	*ft_new_node(t_list *new_node)
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
	t_list	*keep;

	keep = (*alst);
	if (keep != NULL && new_node != NULL)
	{
		while (keep->next != NULL)
			keep = keep->next;
		keep->next = new_node;
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
	t_list	**lst_point;

	*lst_point = NULL;
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
			ft_add_node(lst_point, new_node);
			i++;
		}
		c++;
	}
}*/

void	ft_fill_pixel(my_m *m, int x, int y)
{
	int		pixel;

	pixel = 4 * (x + (800 * y));
	m->str[pixel] = 0;
	m->str[pixel + 1] = 0;
	m->str[pixel + 2] = 0xff;
	m->str[pixel + 3] = 0;
}

/*void	ft_fill_image(t_list **alst)
{
	while ((*alst) != NULL)
	{
		ft_fill_pixel(m, (*alst)->point.x, (*alst)->point.y);
		(*alst) = (*alst)->next;
	}
}*/

int		main(int ac, char **av)
{
	my_m	m;
//	int		fd;
//	t_list	**lst_point;

	(void)av;
	ac = 2;
//	fd = (av[1], O_RDONLY);
	m.mlx_ptr = mlx_init();
	m.win_ptr = mlx_new_window(m.mlx_ptr, 800, 600, "FdF");
	m.img_ptr = mlx_new_image(m.mlx_ptr, 800, 600);
	m.str = mlx_get_data_addr(m.img_ptr, &(m.bpp), &(m.s_l), &(m.endian));
//	ft_fill_imge(lst_point);
	ft_fill_pixel(&m, 400, 300);
	mlx_put_image_to_window(m.mlx_ptr, m.win_ptr, m.img_ptr, 0, 0);
	mlx_loop(m.mlx_ptr);
	return (0);
}
