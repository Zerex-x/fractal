/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojrhaide <ojrhaide@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 13:09:37 by ojrhaide          #+#    #+#             */
/*   Updated: 2025/04/12 05:35:05 by ojrhaide         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_fractal(t_fractal *fractal)
{
	if (!fractal)
	{
		write(2, "Error: Fractal structure is NULL.\n", 35);
		exit(1);
	}
	fractal->x = 0;
	fractal->y = 0;
	fractal->color = 0x00060E;
	fractal->zoom = 200.0;
	fractal->off_x = -1.70;
	fractal->off_y = -1.40;
	fractal->max_iterations = 50;
	fractal->cx = 0.0;
	fractal->cy = 0.0;
}

static void	init_mlx_fail_cleanup(void)
{
	write(2, "Error: MiniLibX initialization failed.\n", 40);
	exit(1);
}

void	init_mlx(t_fractal *fractal)
{
	if (!fractal)
	{
		write(2, "Error: Fractal structure is NULL.\n", 35);
		exit(1);
	}
	fractal->mlx = mlx_init();
	if (!fractal->mlx)
		init_mlx_fail_cleanup();
	fractal->window = mlx_new_window(fractal->mlx, 600, 600, "Fract-ol");
	if (!fractal->window)
		init_mlx_fail_cleanup();
	fractal->image = mlx_new_image(fractal->mlx, 600, 600);
	if (!fractal->image)
		init_mlx_fail_cleanup();
	fractal->pointer_to_image = mlx_get_data_addr(fractal->image,
			&fractal->bits_per_pixel, &fractal->size_line, &fractal->endian);
	if (!fractal->pointer_to_image)
		init_mlx_fail_cleanup();
}
