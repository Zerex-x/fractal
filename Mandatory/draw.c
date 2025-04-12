/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojrhaide <ojrhaide@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 13:09:23 by ojrhaide          #+#    #+#             */
/*   Updated: 2025/04/12 21:15:57 by ojrhaide         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_mandelbrot(t_fractal *fractal)
{
	int			pos_x;
	int			pos_y;

	if (!fractal || !fractal->mlx || !fractal->window || !fractal->image)
		return ;
	pos_x = 0;
	while (pos_x < 600)
	{
		pos_y = 0;
		while (pos_y < 600)
		{	
			fractal->x = pos_x;
			fractal->y = pos_y;
			calculate_mandelbrot(fractal);
			pos_y++;
		}
		pos_x++;
	}
	mlx_put_image_to_window(fractal->mlx, fractal->window,
		fractal->image, 0, 0);
}

void	draw_julia(t_fractal *fractal)
{
	int	x;
	int	y;

	if (!fractal || !fractal->mlx || !fractal->window || !fractal->image)
		return ;
	x = 0;
	while (x < 600)
	{
		y = 0;
		while (y < 600)
		{
			fractal->x = x;
			fractal->y = y;
			calculate_julia(fractal);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(fractal->mlx, fractal->window,
		fractal->image, 0, 0);
}
