/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazelda <sazelda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 14:14:44 by sazelda           #+#    #+#             */
/*   Updated: 2022/01/07 16:42:40 by sazelda          ###   ########.fr       */
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
	ft_free_data_struct(data);
	return (0);
}
