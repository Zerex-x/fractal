/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojrhaide <ojrhaide@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 13:09:45 by ojrhaide          #+#    #+#             */
/*   Updated: 2025/04/06 07:28:05 by ojrhaide         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void calculate_julia(t_fractal *f)
{
    int		i;
    double	tmp;

    // Check for NULL pointer
    if (!f)
        return;

    // Avoid division by zero
    if (f->zoom == 0.0)
        return;

    f->name = "julia";
    f->zx = f->x / f->zoom + f->offset_x;
    f->zy = -f->y / f->zoom - f->offset_y;
    i = 0;

    while (i < f->max_iterations && hypot(f->zx, f->zy) < 2.0)
    {
        tmp = f->zx;
        f->zx = (f->zx * f->zx) - (f->zy * f->zy) + f->cx;
        f->zy = 2.0 * tmp * f->zy + f->cy;
        i++;
    }
    if (i == f->max_iterations)
        put_color_to_pixel(f, f->x, f->y, 0x000000); // Black for points in the set
    else
    {
        unsigned int color = f->color * i;
        put_color_to_pixel(f, f->x, f->y, color);
    }
}