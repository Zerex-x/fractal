/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_and_keys.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojrhaide <ojrhaide@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 13:09:59 by ojrhaide          #+#    #+#             */
/*   Updated: 2025/04/12 05:40:17 by ojrhaide         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom(t_fractal *fractal, int zoom)
{
	double	zoom_factor;
	double	center_x;
	double	center_y;

	if (!fractal || fractal->zoom <= 0)
		return ;
	zoom_factor = 1.2;
	center_x = (600 / 2) / fractal->zoom + fractal->off_x;
	center_y = (600 / 2) / fractal->zoom + fractal->off_y;
	if (zoom == 1)
		fractal->zoom *= zoom_factor;
	else if (zoom == -1)
		fractal->zoom /= zoom_factor;
	fractal->off_x = center_x - (600 / 2) / fractal->zoom;
	fractal->off_y = center_y - (600 / 2) / fractal->zoom;
}

int	key_hook(int key_code, t_fractal *fractal)
{
	if (!fractal)
		return (0);
	if (key_code == 53)
		exit(0);
	return (0);
}

int	mouse_hook(int mouse_code, int x, int y, t_fractal *fractal)
{
	(void)x;
	(void)y;
	if (!fractal)
		return (0);
	if (mouse_code == 4)
		zoom(fractal, 1);
	else if (mouse_code == 5)
		zoom(fractal, -1);
	if (fractal->name)
		draw_fractal(fractal, fractal->name);
	return (0);
}
