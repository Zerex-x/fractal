/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_float.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojrhaide <ojrhaide@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 13:09:41 by ojrhaide          #+#    #+#             */
/*   Updated: 2025/04/12 03:49:01 by ojrhaide         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	check_first_char(const char *str, int *i)
{
	while (str[*i] == ' ' || str[*i] == '\t' || str[*i] == '\n'
		|| str[*i] == '\r' || str[*i] == '\v' || str[*i] == '\f')
		(*i)++;
	if (str[*i] == '-' || str[*i] == '+')
		(*i)++;
	if (str[*i] == '.')
		return (0);
	if (!str[*i] || !ft_isdigit(str[*i]))
		return (0);
	return (1);
}

static int	process_digits(const char *str, int *i, int *has_dot,
int *has_digit)
{
	while (str[*i])
	{
		if (str[*i] == '.')
		{
			if (*has_dot || !ft_isdigit(str[*i + 1]))
				return (0);
			*has_dot = 1;
		}
		else if (!ft_isdigit(str[*i]))
			break ;
		else
			*has_digit = 1;
		(*i)++;
	}
	return (1);
}

static void	check_last_char(const char *str, int *i)
{
	while (str[*i] == ' ' || str[*i] == '\t' || str[*i] == '\n'
		|| str[*i] == '\r' || str[*i] == '\v' || str[*i] == '\f')
		(*i)++;
}

int	is_valid_float(const char *str)
{
	int	i;
	int	has_dot;
	int	has_digit;

	i = 0;
	has_dot = 0;
	has_digit = 0;
	if (!check_first_char(str, &i))
		return (0);
	if (!process_digits(str, &i, &has_dot, &has_digit))
		return (0);
	check_last_char(str, &i);
	if (str[i] != '\0')
		return (0);
	return (has_digit);
}
