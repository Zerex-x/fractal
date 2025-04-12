#include "fractol.h"

int	draw_fractal(t_fractal *fractal, char *fractal_type)
{
	if (!fractal || !fractal_type)
		return (1);
	if (ft_strcmp(fractal_type, "mandelbrot") == 0)
		draw_mandelbrot(fractal);
	else if (ft_strcmp(fractal_type, "julia") == 0)
		draw_julia(fractal);
	else
	{
		write(2, "\nAvailable fractals: [mandelbrot] && [julia]\n", 46);
		exit_fractal(fractal);
	}
	if (fractal->mlx && fractal->window && fractal->image)
		mlx_put_image_to_window(
			fractal->mlx,
			fractal->window,
			fractal->image,
			0,
			0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_fractal	*fractal;

	check_args(argc, argv);
	fractal = malloc(sizeof(t_fractal));
	if (!fractal)
	{
		write(2, "Error: Memory allocation failed.\n", 34);
		return (1);
	}
	init_fractal(fractal);
	init_mlx(fractal);
	if (ft_strcmp(argv[1], "julia") == 0)
	{
		fractal->cx = ft_atof(argv[2]);
		fractal->cy = ft_atof(argv[3]);
	}
	mlx_key_hook(fractal->window, key_hook, fractal);
	mlx_mouse_hook(fractal->window, mouse_hook, fractal);
	mlx_hook(fractal->window, 17, 0, exit_fractal, fractal);
	draw_fractal(fractal, argv[1]);
	mlx_loop(fractal->mlx);
	return (0);
}