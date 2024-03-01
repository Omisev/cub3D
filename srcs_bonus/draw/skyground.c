/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skyground.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:24:07 by raveriss          #+#    #+#             */
/*   Updated: 2024/02/29 17:12:50 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Include/cub3d.h"

int	get_color(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void	draw_skyground(t_data *data)
{
	int	color;
	int	x;
	int	y;

	x = 0;
	while (x < W)
	{
		y = 0;
		while (y < H)
		{
			if (y < H / 2)
			{
				color = get_color(data->elem.colors_c[0],
						data->elem.colors_c[1], data->elem.colors_c[2]);
				my_mlx_pixel_put(&data->img, x, y++, color);
			}
			else
			{
				color = get_color(data->elem.colors_f[0],
						data->elem.colors_f[1], data->elem.colors_f[2]);
				my_mlx_pixel_put(&data->img, x, y++, color);
			}
		}
		x++;
	}
}
