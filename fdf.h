/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazelda <sazelda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 14:26:48 by sazelda           #+#    #+#             */
/*   Updated: 2022/01/07 16:43:09 by sazelda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "minilibx/mlx.h"

typedef struct s_fdf
{
	int		width;
	int		height;
	int		**matrix;

	void	*mlx_ptr;
	void	*win_ptr;
}	t_fdf;

void	ft_read_file(char *file_name, t_fdf *data);

#endif