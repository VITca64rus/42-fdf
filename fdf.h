/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazelda <sazelda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 14:26:48 by sazelda           #+#    #+#             */
/*   Updated: 2022/01/11 17:23:45 by sazelda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "mlx.h"
# include <math.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct s_z_color
{
	int		z;
	int		color;
}	t_z_color;

typedef struct s_fdf
{
	int			width;
	int			height;
	t_z_color	***matrix;
	int			zoom;
	int			color;
	int			shift_x;
	int			shift_y;
	float		angle;
	void		*mlx_ptr;
	void		*win_ptr;
}	t_fdf;

void	ft_read_file(char *file_name, t_fdf *data);
void	draw(t_fdf *data);
int		ft_get_int(char *a);
float	ft_max(float a, float b);
float	ft_mod(float a);
void	ft_full_a(float a[4], int i, int j, t_fdf *data);
void	ft_bresenham(float a[4], t_fdf *data);
void	ft_free_loop(char **num_col, char *number);
void	ft_free_notloop(char *line, char *number, char **numbers);
void	ft_create_matrix(char *file_name, t_fdf *data);

#endif