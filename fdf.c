/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llejeune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 16:03:20 by llejeune          #+#    #+#             */
/*   Updated: 2019/01/22 18:58:30 by llejeune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fdf.h"

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

int		main()
{
	my_m	m;

	m.mlx_ptr = mlx_init();
	m.win_ptr = mlx_new_window(m.mlx_ptr, 800, 600, "FdF");
	m.img_ptr = mlx_new_image(m.mlx_ptr, 800, 600);
	m.str = mlx_get_data_addr(m.img_ptr, &(m.bpp), &(m.s_l), &(m.endian));
	ft_fill_pixel(&m);
	mlx_put_image_to_window(m.mlx_ptr, m.win_ptr, m.img_ptr, 0, 0);
	mlx_loop(m.mlx_ptr);
	return (0);
}
