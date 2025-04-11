/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojrhaide <ojrhaide@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 13:09:55 by ojrhaide          #+#    #+#             */
/*   Updated: 2025/03/30 09:25:01 by ojrhaide         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	calculate_mandelbrot(t_fractal *f)
{
	int		i;
	double	old_zx;

	f->name = "mandelbrot";
	f->zx = 0.0;	
	f->zy = 0.0;
	f->cx = (f->x / f->zoom) + f->offset_x;
	f->cy = (f->y / f->zoom) + f->offset_y;
	i = 0;
	while (i < f->max_iterations && hypot(f->zx, f->zy) < 2.0)
	{
		old_zx = f->zx;
		f->zx = (f->zx * f->zx) -(f->zy * f->zy) + f->cx;
		f->zy = 2.0 * old_zx * f->zy + f->cy;
		i++;
	}
	if (i == f->max_iterations)
		put_color_to_pixel(f, f->x, f->y, 0x000000);
	else
		put_color_to_pixel(f, f->x, f->y, f->color * i);
}
