/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojrhaide <ojrhaide@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 13:09:23 by ojrhaide          #+#    #+#             */
/*   Updated: 2025/04/12 03:30:45 by ojrhaide         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	render_mandelbrot(t_pattern *pattern)
{
	int			pos_x;
	int			pos_y;

	if (!pattern || !pattern->engine || !pattern->display || !pattern->canvas)
		return ;
	pos_x = 0;
	while (pos_x < 600)
	{
		pos_y = 0;
		while (pos_y < 600)
		{
			pattern->coord_x = pos_x;
			pattern->coord_y = pos_y;
			compute_mandelbrot(pattern);
			pos_y++;
		}
		pos_x++;
	}
	engine_draw_to_window(pattern->engine, pattern->display,
		pattern->canvas, 0, 0);
}

void	render_julia(t_pattern *pattern)
{
	int	pos_x;
	int	pos_y;

	if (!pattern || !pattern->engine || !pattern->display || !pattern->canvas)
		return ;
	pos_x = 0;
	while (pos_x < 600)
	{
		pos_y = 0;
		while (pos_y < 600)
		{
			pattern->coord_x = pos_x;
			pattern->coord_y = pos_y;
			compute_julia(pattern);
			pos_y++;
		}
		pos_x++;
	}
	engine_draw_to_window(pattern->engine, pattern->display,
		pattern->canvas, 0, 0);
}
