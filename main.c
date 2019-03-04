/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llejeune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 13:08:57 by llejeune          #+#    #+#             */
/*   Updated: 2019/03/04 13:17:53 by llejeune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
