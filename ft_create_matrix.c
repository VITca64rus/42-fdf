/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazelda <sazelda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 17:22:22 by sazelda           #+#    #+#             */
/*   Updated: 2022/01/11 17:23:55 by sazelda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_generate_matrix(t_fdf *data, char **numbers, int i)
{
	char	**num_col;
	int		j;

	j = 0;
	while (j < data->width)
	{
		num_col = ft_split(numbers[j], ',');
		data->matrix[i][j] = (t_z_color *)malloc(sizeof(t_z_color));
		data->matrix[i][j]->z = ft_atoi(num_col[0]);
		if (num_col[1] != NULL)
			data->matrix[i][j]->color = ft_get_int(num_col[1]);
		else
			data->matrix[i][j]->color = 0xffffff;
		ft_free_loop(num_col, numbers[j]);
		j++;
	}
	return (j);
}

void	ft_create_matrix(char *file_name, t_fdf *data)
{
	int		fd;
	char	*line;
	char	**numbers;
	int		i;
	int		j;

	data->matrix = (t_z_color ***)malloc(sizeof(t_z_color **) * data->height);
	fd = open(file_name, O_RDONLY, 0);
	if (fd < 0)
		return ;
	i = 0;
	while (i < data->height)
	{
		line = get_next_line(fd);
		numbers = ft_split(line, ' ');
		data->matrix[i] = (t_z_color **)malloc(sizeof(t_z_color *) \
							* data->width);
		j = 0;
		j = ft_generate_matrix(data, numbers, i);
		ft_free_notloop(line, numbers[j], numbers);
		i++;
	}
	close(fd);
}
