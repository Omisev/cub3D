/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_images_exist.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:39:51 by raveriss          #+#    #+#             */
/*   Updated: 2024/02/29 18:12:41 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Include/cub3d.h"

char	*get_xpm_filename(int i)
{
	static char	*xpm_filename[] = {
		"textures/east_1.xpm", "textures/east_2.xpm", "textures/east_3.xpm",
		"textures/east_4.xpm", "textures/east_5.xpm", "textures/east_5.xpm",
		"textures/east_6.xpm", "textures/east_7.xpm", "textures/east_8.xpm",
		"textures/east_8.xpm", "textures/east_9.xpm", "textures/east_10.xpm",
		"textures/east_11.xpm", "textures/east_12.xpm", "textures/north_1.xpm",
		"textures/north_2.xpm", "textures/north_3.xpm", "textures/north_4.xpm",
		"textures/north_5.xpm", "textures/north_6.xpm", "textures/north_7.xpm",
		"textures/north_8.xpm", "textures/north_9.xpm",
		"textures/north_10.xpm", "textures/north_11.xpm",
		"textures/north_12.xpm", "textures/south_1.xpm", "textures/south_2.xpm",
		"textures/south_3.xpm", "textures/south_4.xpm", "textures/south_5.xpm",
		"textures/south_6.xpm", "textures/south_7.xpm", "textures/south_8.xpm",
		"textures/south_9.xpm", "textures/south_10.xpm",
		"textures/south_11.xpm", "textures/south_12.xpm", "textures/west_1.xpm",
		"textures/west_2.xpm", "textures/west_3.xpm", "textures/west_4.xpm",
		"textures/west_5.xpm", "textures/west_6.xpm", "textures/west_7.xpm",
		"textures/west_8.xpm", "textures/west_9.xpm", "textures/west_10.xpm",
		"textures/west_11.xpm", "textures/west_12.xpm",
	};

	return (xpm_filename[i]);
}

void	check_images_exist(t_data *data)
{
	int		i;
	int		fd;
	char	*filename;

	i = 0;
	while (i < COUNT_WEST_XPM * 4)
	{
		filename = get_xpm_filename(i);
		fd = open(filename, O_RDONLY);
		if (fd == -1)
		{
			close(fd);
			ft_printf("%s\n", filename);
			filename = NULL;
			ft_exit(data, "Error\ntextures !", 1);
		}
		close(fd);
		i++;
	}
	filename = NULL;
}
