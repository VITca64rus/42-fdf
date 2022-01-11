/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_help.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazelda <sazelda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 12:16:06 by sazelda           #+#    #+#             */
/*   Updated: 2022/01/11 17:21:19 by sazelda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	ft_max(float a, float b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

float	ft_mod(float a)
{
	if (a < 0)
		return (-1 * a);
	else
		return (a);
}

void	ft_full_a(float a[4], int i, int j, t_fdf *data)
{
	if (j < data->width - 1)
	{
		(a)[0] = j;
		(a)[1] = i;
		(a)[2] = j + 1;
		(a)[3] = i;
		ft_bresenham(a, data);
	}
	if (i < data->height - 1)
	{
		(a)[0] = j;
		(a)[1] = i;
		(a)[2] = j;
		(a)[3] = i + 1;
		ft_bresenham(a, data);
	}
}

void	ft_free_loop(char **num_col, char *number)
{
	free(number);
	free(num_col[0]);
	free(num_col[1]);
	free(num_col);
}

void	ft_free_notloop(char *line, char *number, char **numbers)
{
	free(line);
	free(number);
	free(numbers);
}
