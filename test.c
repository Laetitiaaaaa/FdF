/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llejeune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 16:29:02 by llejeune          #+#    #+#             */
/*   Updated: 2019/01/21 16:42:01 by llejeune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

int		main()
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "test");
	mlx_pixel_put(mlx_ptr, win_ptr, 250, 250, 0xFF0000);
	mlx_loop(mlx_ptr);
	return (0);
}
