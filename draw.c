/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazelda <sazelda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 16:57:28 by sazelda           #+#    #+#             */
/*   Updated: 2022/01/11 12:15:45 by sazelda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

void	ft_3d(float *x, float *y, int z, t_fdf *data)
{
	*x = (*x - *y) * cos(data->angle);
	*y = (*x + *y) * sin(data->angle) - z;
}

void	ft_make_shift(float *x, float *y, float *x1, float *y1, t_fdf *data)
{
	*x += data->shift_x;
	*y += data->shift_y;
	*x1 += data->shift_x;
	*y1 += data->shift_y;
}

void	ft_make_zoom(float *x, float *y, float *x1, float *y1, t_fdf *data)
{
	*x *= data->zoom;
	*y *= data->zoom;
	*x1 *= data->zoom;
	*y1 *= data->zoom;
}

static void	ft_bresenham(float x, float y, float x1, float y1, t_fdf *data)
{
	float	x_step;
	float	y_step;
	int		max;
	int		z;
	int		z1;

	data->color = data->matrix[(int)y][(int)x]->color;
	z = data->matrix[(int)y][(int)x]->z * 10;
	z1 = data->matrix[(int)y1][(int)x1]->z * 10;
	ft_make_zoom(&x, &y, &x1, &y1, data);
	ft_3d(&x, &y, z, data);
	ft_3d(&x1, &y1, z1, data);
	ft_make_shift(&x, &y, &x1, &y1, data);
	x_step = x1 - x;
	y_step = y1 - y;
	max = ft_max(ft_mod(x_step), ft_mod(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(x - x1) || (int)(y - y1))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, data->color);
		x += x_step;
		y += y_step;
	}
}

void	draw(t_fdf *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			if (j < data->width - 1)
				ft_bresenham(j, i, j + 1, i, data);
			if (i < data->height - 1)
				ft_bresenham(j, i, j, i + 1, data);
			j++;
		}
		i++;
	}
}
