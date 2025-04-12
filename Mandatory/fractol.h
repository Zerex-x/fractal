/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojrhaide <ojrhaide@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 13:09:27 by ojrhaide          #+#    #+#             */
/*   Updated: 2025/04/12 03:14:23 by ojrhaide         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATTERN_H
# define PATTERN_H

# include <mlx.h>
# include <math.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_pattern
{
	void	*engine;
	void	*display;
	void	*canvas;
	void	*canvas_pointer;
	int		bpp;
	int		line_size;
	int		byte_order;
	int		coord_x;
	int		coord_y;
	double	real_part;
	double	imaginary_part;
	double	real_const;
	double	imaginary_const;
	int		shade;
	double	shift_x;
	double	shift_y;
	double	scale;
	char	*type_name;
	int		iteration_limit;
}	t_pattern;

int		str_compare(char *str1, char *str2);
void	apply_shade_to_pixel(t_pattern *pattern, int pos_x, int pos_y, int iteration_count);
int		close_pattern(t_pattern *pattern);
void	initialize_pattern(t_pattern *pattern);
void	initialize_engine(t_pattern *pattern);
void	compute_mandelbrot(t_pattern *pattern);
void	compute_julia(t_pattern *pattern);
int		render_pattern(t_pattern *pattern, char *query);
int		handle_key_event(int key_code, t_pattern *pattern);
int		handle_mouse_event(int mouse_code, int pos_x, int pos_y, t_pattern *pattern);
void	render_mandelbrot(t_pattern *pattern);
void	render_julia(t_pattern *pattern);
double	string_to_double(const char *str);
int		is_valid_double(const char *str);
void	apply_shade_to_pixel(t_pattern *pattern, int pos_x, int pos_y, int shade);
int		is_digit(int character);

#endif