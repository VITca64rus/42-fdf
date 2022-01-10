/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazelda <sazelda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 16:57:28 by sazelda           #+#    #+#             */
/*   Updated: 2022/01/10 16:59:35 by sazelda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

#define MAX(a, b) (a > b ? a : b)
#define MOD(a) (a < 0 ? -a : a)

void ft_3d(float *x, float *y, int z, t_fdf *data)
{
	*x = (*x - *y) * cos(data->angle);
	*y = (*x + *y) * sin(data->angle) - z;
}

int	ft_get_int(char *a)
{
	char	*base;
	int		i;
	int		j;
	int		res;
	int		step;

	if (!a)
		return (0);
	return (0);
	res = 0;
	step = ft_strlen(a) - 1;
	base = "0123456789ABCDEF";
	i = 2;
	while (a[i] != '\0')
	{
		j = 0;
		while (base[j] != '\0')
		{
			if (a[i] == base[j])
				break ;
			j++;
		}
		res += j * pow(16, step);
		step--;
	}
	return (res);
}

static void	ft_bresenham(float x, float y, float x1, float y1, t_fdf *data)
{
	float	x_step;
	float	y_step;
	int		max;
	int		z;
	int		z1;

	data->color = ft_get_int(data->color_matrix[(int)y][(int)x]);
	z = data->matrix[(int)y][(int)x];
	z1 = data->matrix[(int)y1][(int)x1];

	x *= data->zoom;
	y *= data->zoom;
	x1 *= data->zoom;
	y1 *= data->zoom;
	data->color = (z || z1) ? 15207436 : 16777215;
	ft_3d(&x, &y, z, data);
	ft_3d(&x1, &y1, z1, data);

	x += data->shift_x;
	y += data->shift_y;
	x1 += data->shift_x;
	y1 += data->shift_y;

	x_step = x1 - x;
	y_step = y1 - y;
	max = MAX(MOD(x_step), MOD(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(x - x1) || (int)(y - y1))
	{
		//max = ft_get_int(data->color_matrix[(int)y][(int)x]);
		if (max == 0)
		{
			max = 0xffffff;
		}
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
