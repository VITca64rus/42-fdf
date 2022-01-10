/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazelda <sazelda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 14:14:44 by sazelda           #+#    #+#             */
/*   Updated: 2022/01/10 15:12:28 by sazelda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_free_data_struct(t_fdf *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->height)
	{
		free(data->matrix[i]);
		i++;
	}
	free(data->matrix);
	free(data);
}

int	deal_key(int key, t_fdf *data)
{
	int i;

	if (key == 126)
		data->shift_y -= 10;
	if (key == 125)
		data->shift_y += 10;
	if (key == 123)
		data->shift_x -= 10;
	if (key == 124)
		data->shift_x += 10;
	if (key == 24) // +
		data->zoom += 5;
	if (key == 27) // -
		data->zoom -= 5;
	if (key == 15) // r
		data->angle += 0.1;
	if (key == 17) // t
		data->angle -= 0.1;
	if (key == 53)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		i = 0;
		while (i < data->height)
		{
			free(data->matrix[i]);
			i++;
		}
		free(data->matrix);
		free(data);
		exit (0);
	}
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw(data);
	return (0);
}

int	main(int argc, char **argv)
{
	char	*file_name;
	t_fdf	*data;

	if (argc == 2)
	{
		file_name = argv[1];
		data = (t_fdf *)malloc(sizeof(t_fdf));
		ft_read_file(file_name, data);
	}
	data->zoom = 20;
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1000, 1000, "FDF");
	data->angle = 0.8;
	draw(data);
	mlx_key_hook(data->win_ptr, deal_key, data);
	mlx_loop(data->mlx_ptr);
	ft_free_data_struct(data);
	return (0);
}
