/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:23:56 by raveriss          #+#    #+#             */
/*   Updated: 2024/03/01 04:06:59 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Include/cub3d.h"

void	draw_floor(t_data *data, int x, int y)
{
	int	tmpx;
	int	tmpy;

	tmpx = x;
	tmpy = y;
	while (y < (tmpy + T_SIZE * MMSF))
	{
		x = tmpx;
		while (x < (tmpx + T_SIZE * MMSF))
		{
			my_mlx_pixel_put(&data->img, x, y, 0xFFFFFF);
			x++;
		}
		y++;
	}
}

void	draw_wall(t_data *data, int x, int y)
{
	int	tmpx;
	int	tmpy;

	tmpx = x;
	tmpy = y;
	while (y < (tmpy + T_SIZE * MMSF))
	{
		x = tmpx;
		while (x < (tmpx + T_SIZE * MMSF))
		{
			my_mlx_pixel_put(&data->img, x, y, 0x000000);
			x++;
		}
		y++;
	}
}

void	draw_minimap(t_data *data, char **map)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = 0;
	y = 0;
	while (map[i])
	{
		j = 0;
		x = 0;
		while (map[i][j])
		{
			if (map[i][j] == '1')
				draw_wall(data, x * MMSF, y * MMSF);
			else if (map[i][j] == '0' || is_player(map[i][j]))
				draw_floor(data, x * MMSF, y * MMSF);
			x += T_SIZE;
			j++;
		}
		y += T_SIZE;
		i++;
	}
}
