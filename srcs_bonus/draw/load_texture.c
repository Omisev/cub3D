/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:50:20 by raveriss          #+#    #+#             */
/*   Updated: 2024/02/29 23:04:50 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Include/cub3d.h"

void	update_frame(t_data *data)
{
	static int	frame_count = 0;

	if (frame_count++ % ANIMATION_SPEED == 0)
	{
		data->frame = (data->frame + 1) % COUNT_WEST_XPM;
	}
}

void	load_south_textures(t_data *data, int i)
{
	char		*filename;
	static char	*filenames[] = {
		"./textures/south_1.xpm", "./textures/south_2.xpm",
		"./textures/south_3.xpm", "./textures/south_4.xpm",
		"./textures/south_5.xpm", "./textures/south_6.xpm",
		"./textures/south_7.xpm", "./textures/south_8.xpm",
		"./textures/south_9.xpm", "./textures/south_10.xpm",
		"./textures/south_11.xpm", "./textures/south_12.xpm",
	};

	filename = NULL;
	if (i >= COUNT_WEST_XPM)
		return ;
	else
	{
		filename = filenames[i];
		data->south_textures[i].ptr = \
		mlx_xpm_file_to_image(\
		data->mlx.ptr, filename, &data->south_textures[i].w,
				&data->south_textures[i].h);
		if (!data->south_textures[i].ptr)
			ft_exit(data, "Error\ntexture SO not found!", 1);
		load_south_textures(data, i + 1);
	}
}

void	load_north_textures(t_data *data, int i)
{
	char		*filename;
	static char	*filenames[] = {
		"./textures/north_1.xpm", "./textures/north_2.xpm",
		"./textures/north_3.xpm", "./textures/north_4.xpm",
		"./textures/north_5.xpm", "./textures/north_6.xpm",
		"./textures/north_7.xpm", "./textures/north_8.xpm",
		"./textures/north_9.xpm", "./textures/north_10.xpm",
		"./textures/north_11.xpm", "./textures/north_12.xpm",
	};

	filename = NULL;
	if (i >= COUNT_WEST_XPM)
		return ;
	else
	{
		filename = filenames[i];
		data->north_textures[i].ptr = mlx_xpm_file_to_image(data->mlx.ptr,
				filename, &data->north_textures[i].w,
				&data->north_textures[i].h);
		if (!data->north_textures[i].ptr)
			ft_exit(data, "Error\ntexture NO not found!", 1);
		load_north_textures(data, i + 1);
	}
}

void	load_east_textures(t_data *data, int i)
{
	char		*filename;
	static char	*filenames[] = {
		"./textures/east_1.xpm", "./textures/east_2.xpm",
		"./textures/east_3.xpm", "./textures/east_4.xpm",
		"./textures/east_5.xpm", "./textures/east_6.xpm",
		"./textures/east_7.xpm", "./textures/east_8.xpm",
		"./textures/east_9.xpm", "./textures/east_10.xpm",
		"./textures/east_11.xpm", "./textures/east_12.xpm",
	};

	filename = NULL;
	if (i >= COUNT_WEST_XPM)
		return ;
	else
	{
		filename = filenames[i];
		data->east_textures[i].ptr = mlx_xpm_file_to_image(data->mlx.ptr,
				filename, &data->east_textures[i].w, \
				&data->east_textures[i].h);
		if (!data->east_textures[i].ptr)
			ft_exit(data, "Error\ntexture EA not found!", 1);
		load_east_textures(data, i + 1);
	}
}

void	load_west_textures(t_data *data, int i)
{
	char		*filename;
	static char	*filenames[] = {
		"./textures/west_1.xpm",
		"./textures/west_2.xpm", "./textures/west_3.xpm",
		"./textures/west_4.xpm", "./textures/west_5.xpm",
		"./textures/west_6.xpm", "./textures/west_7.xpm",
		"./textures/west_8.xpm", "./textures/west_9.xpm",
		"./textures/west_10.xpm", "./textures/west_11.xpm",
		"./textures/west_12.xpm",
	};

	filename = NULL;
	if (i >= COUNT_WEST_XPM)
		return ;
	else
	{
		filename = filenames[i];
		data->west_textures[i].ptr = mlx_xpm_file_to_image(data->mlx.ptr,
				filename, &data->west_textures[i].w, \
				&data->west_textures[i].h);
		if (!data->west_textures[i].ptr)
			ft_exit(data, "Error\ntexture WE not found!", 1);
		load_west_textures(data, i + 1);
	}
}
