/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazelda <sazelda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 16:57:28 by sazelda           #+#    #+#             */
/*   Updated: 2022/01/11 16:06:49 by sazelda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

void	ft_3d(float *x, float *y, int z, t_fdf *data)
{
	*x = (*x - *y) * cos(data->angle);
	*y = (*x + *y) * sin(data->angle) - z;
}

void	ft_make_shift(float *a[4], t_fdf *data)
{
	(*a)[0] += data->shift_x;
	(*a)[1] += data->shift_y;
	(*a)[2] += data->shift_x;
	(*a)[3] += data->shift_y;
}

void	ft_make_zoom(float *a[4], t_fdf *data)
{
	(*a)[0] *= data->zoom;
	(*a)[1] *= data->zoom;
	(*a)[2] *= data->zoom;
	(*a)[3] *= data->zoom;
}

void	ft_bresenham(float a[4], t_fdf *data)
{
	float	x_step;
	float	y_step;
	int		max;
	int		z;
	int		z1;

	data->color = data->matrix[(int)a[1]][(int)a[0]]->color;
	z = data->matrix[(int)a[1]][(int)a[0]]->z * 10;
	z1 = data->matrix[(int)a[3]][(int)a[2]]->z * 10;
	ft_make_zoom(&a, data);
	ft_3d(&(a[0]), &(a[1]), z, data);
	ft_3d(&(a[2]), &(a[3]), z1, data);
	ft_make_shift(&a, data);
	x_step = a[2] - a[0];
	y_step = a[3] - a[1];
	max = ft_max(ft_mod(x_step), ft_mod(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(a[0] - a[2]) || (int)(a[1] - a[3]))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, a[0], a[1], data->color);
		a[0] += x_step;
		a[1] += y_step;
	}
}

void	draw(t_fdf *data)
{
	int		i;
	int		j;
	float	a[4];

	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			ft_full_a(a, i, j, data);
			j++;
		}
		i++;
	}
}
