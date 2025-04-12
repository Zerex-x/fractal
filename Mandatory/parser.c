/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojrhaide <ojrhaide@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 21:16:35 by ojrhaide          #+#    #+#             */
/*   Updated: 2025/04/12 21:16:37 by ojrhaide         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	validate_julia_args(int argc, char **argv)
{
	double	cx;
	double	cy;

	if (argc != 4)
	{
		write(2, "\nError: Julia requires two float parameters ", 44);
		write(2, "(cx, cy).\n", 11);
		exit(1);
	}
	cx = ft_atof(argv[2]);
	cy = ft_atof(argv[3]);
	if (cx < -2 || cx > 2 || cy < -2 || cy > 2)
	{
		write(2, "Error: Julia constants must be between -2 and 2.\n", 50);
		exit(1);
	}
	if (!is_valid_float(argv[2]) || !is_valid_float(argv[3]))
	{
		write(2, "\nError: Julia parameters must be ", 34);
		write(2, "valid float numbers.\n", 22);
		exit(1);
	}
}

void	check_args(int argc, char **argv)
{
	if (argc == 1 || (ft_strcmp(argv[1], "mandelbrot") == 0 && argc > 2))
	{
		write(2, "Usage: ./fractol [mandelbrot] || [julia <cx> <cy>]\n", 52);
		write(2, "\nAvailable fractals: [mandelbrot] && [julia]\n", 46);
		exit(1);
	}
	if (ft_strcmp(argv[1], "mandelbrot") != 0
		&& ft_strcmp(argv[1], "julia") != 0)
	{
		write(2, "\nError: Invalid fractal type.\n", 31);
		write(2, "Usage: ./fractol [mandelbrot] || [julia <cx> <cy>]\n", 52);
		exit(1);
	}
	if (ft_strcmp(argv[1], "julia") == 0)
		validate_julia_args(argc, argv);
}