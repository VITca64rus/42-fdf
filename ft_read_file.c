/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazelda <sazelda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 16:42:53 by sazelda           #+#    #+#             */
/*   Updated: 2022/01/10 18:55:48 by sazelda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "fdf.h"

static int	ft_get_height(char *file_name)
{
	char	*line;
	int		fd;
	int		height;

	fd = open(file_name, O_RDONLY, 0);
	if (fd < 0)
		return (-1);
	line = get_next_line(fd);
	height = 0;
	while (line)
	{
		free(line);
		line = NULL;
		height++;
		line = get_next_line(fd);
	}
	close(fd);
	return (height);
}

static int	ft_get_width(char *file_name)
{
	char	*line;
	int		fd;
	int		width;
	char	**numbers;

	fd = open(file_name, O_RDONLY, 0);
	if (fd < 0)
		return (-1);
	line = get_next_line(fd);
	close(fd);
	numbers = ft_split(line, ' ');
	free(line);
	width = 0;
	while (numbers[width])
	{
		free(numbers[width]);
		width++;
	}
	free(numbers);
	return (width);
}

int	ft_get_int(char *a)
{
	char	*base;
	int		i;
	int		j;
	int		res;
	int		step;

	res = 0;
	step = ft_strlen(a) - 2;
	printf("step - %d\na - %s\n", step, a);
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
		res = res + (j * pow(16, step));
		step--;
		i++;
	}
	return (res);
}

static void	ft_create_matrix(char *file_name, t_fdf *data)
{
	int		fd;
	char	*line;
	char	**numbers;
	char	**num_col;
	int		i;
	int		j;

	data->matrix = (t_z_color ***)malloc(sizeof(t_z_color **) * data->height);
	//data->color_matrix = (char ***)malloc(sizeof(char **) * data->height);
	fd = open(file_name, O_RDONLY, 0);
	if (fd < 0)
		return ;
	i = 0;
	while (i < data->height)
	{
		line = get_next_line(fd);
		numbers = ft_split(line, ' ');
		data->matrix[i] = (t_z_color **)malloc(sizeof(t_z_color *) * data->width);
		//data->color_matrix[i] = (char **)malloc(sizeof(char *) * data->width);
		j = 0;
		while (j < data->width)
		{
			num_col = ft_split(numbers[j], ',');
			data->matrix[i][j] = (t_z_color *)malloc(sizeof(t_z_color));
			data->matrix[i][j]->z = ft_atoi(num_col[0]);
			if (num_col[1] != NULL)
			{
				//data->matrix[i][j]->color = (char *)malloc(ft_strlen(num_col[1]) + 1);
				data->matrix[i][j]->color = ft_get_int(num_col[1]);
				printf("%s - %d\n", num_col[1], data->matrix[i][j]->color);
			}
			else
				data->matrix[i][j]->color = 0;
			free(numbers[j]);
			j++;
		}
		free(line);
		line = NULL;
		free(numbers);
		i++;
	}
	close(fd);
}

void	ft_read_file(char *file_name, t_fdf *data)
{
	data->height = ft_get_height(file_name);
	data->width = ft_get_width(file_name);
	ft_create_matrix(file_name, data);

	// int i = 0;
	// int j;
	// while (i < data->height)
	// {
	// 	j = 0;
	// 	while (j < data ->width)
	// 	{
	// 		printf("%12s", data->color_matrix[i][j]);
	// 		j++;
	// 	}
	// 	printf("\n");
	// 	i++;
	// }
}
