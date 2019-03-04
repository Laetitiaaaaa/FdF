/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llejeune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 13:08:57 by llejeune          #+#    #+#             */
/*   Updated: 2019/03/04 18:53:29 by llejeune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
void	ft_always(t_my_m *m)
{
	int		i;

	i = 0;
	while (i < (m->l * m->h * 4))
		m->str[i++] = 0;
	ft_fill_image(m);
	if (!(mlx_put_image_to_window(m->mlx_ptr, m->win_ptr, m->img_ptr, 0, 0)))
		ft_free(m);
}

int		main(int ac, char **av)
{
	t_my_m	m;

	if (ac != 2)
	{
		ft_putstr("usage: ./fdf source_file\n");
		exit(0);
	}
	else
	{
		if (ft_open(av[1], &m) == 1 || ft_init_mlx(&m) == 1)
		{
			ft_putstr("Wrong file.\n");
			exit(0);
		}
		ft_map(&m.fd, &m);
		ft_always(&m);
		if (!(mlx_hook(m.win_ptr, 2, 0, ft_key, &m)))
			ft_free(&m);
		if (!(mlx_loop(m.mlx_ptr)))
			ft_free(&m);
	}
	return (0);
}
