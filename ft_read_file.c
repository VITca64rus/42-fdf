/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazelda <sazelda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 16:42:53 by sazelda           #+#    #+#             */
/*   Updated: 2022/01/11 17:22:50 by sazelda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	free(line);
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
	free(numbers[width]);
	free(numbers);
	return (width);
}

int	ft_get_int(char *a)
{
	char	*base;
	int		i;
	int		j;
	int		res;

	res = 0;
	base = "0123456789ABCDEFabcdef";
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
		if (j > 15)
			j -= 6;
		res = res + (j * pow(16, ft_strlen(&a[i]) - 1));
		i++;
	}
	return (res);
}

void	ft_read_file(char *file_name, t_fdf *data)
{
	data->height = ft_get_height(file_name);
	data->width = ft_get_width(file_name);
	if (data->width < 0 || data->height < 0)
		exit (0);
	ft_create_matrix(file_name, data);
}
