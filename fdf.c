/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llejeune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 16:03:20 by llejeune          #+#    #+#             */
/*   Updated: 2019/01/22 17:27:19 by llejeune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

void	ft_fill_pixel(char *str, int x, int y, int color)
{
	
	pixel = 4 * x + 
}

int		main()
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	int		bpp;
	int		s_l;
	int		endian;
	char	*str;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 800, 600, "FdF");
	img_ptr = mlx_new_image(mlx_ptr, 800, 600);
	str = mlx_get_data_addr(img_ptr, &bpp, &s_l, &endian);
	ft_fill_pixel(str, x, y, color);
	mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 0, 0);

	return (0);
}
