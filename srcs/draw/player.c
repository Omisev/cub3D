/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:15:44 by raveriss          #+#    #+#             */
/*   Updated: 2024/02/28 17:15:47 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Include/cub3d.h"

void	draw_each_ray(t_data *data, double x1, double y1, int j)
{
	double	steps;
	double	step_x;
	double	step_y;
	int		i;

	i = 0;
	steps = fmax(fabs(data->utils.rays[j].x * MMSF - x1), \
	fabs(data->utils.rays[j].y * MMSF - y1));
	step_x = (data->utils.rays[j].x * MMSF - x1) / steps;
	step_y = (data->utils.rays[j].y * MMSF - y1) / steps;
	while (i <= steps)
	{
		my_mlx_pixel_put(&data->img, x1, y1, data->ray.color);
		x1 += step_x;
		y1 += step_y;
		i++;
	}
}

void	draw_ray(t_data *data)
{
	int	j;

	j = 0;
	while (j < W)
	{
		draw_each_ray(data, data->player.pos_x * T_SIZE * MMSF, \
		data->player.pos_y * T_SIZE * MMSF, j);
		j++;
	}
}

void	check_out_circle(int y_pos, int *err, int *radius)
{
	if (*err <= 0)
		*err += 2 * y_pos + 1;
	else
	{
		(*radius)--;
		*err += 2 * (y_pos - *radius) + 1;
	}
}

void	draw_player(t_data *data, double x, double y, int radius)
{
	int	y_pos;
	int	err;
	int	i;

	err = 0;
	y_pos = 0;
	draw_ray(data);
	while (radius >= y_pos)
	{
		i = x - radius;
		while (i++ <= x + radius)
		{
			my_mlx_pixel_put(&data->img, i, y + y_pos, 0x000000);
			my_mlx_pixel_put(&data->img, i, y - y_pos, 0x000000);
		}
		i = x - y_pos;
		while (i++ <= x + y_pos)
		{
			my_mlx_pixel_put(&data->img, i, y + radius, 0x000000);
			my_mlx_pixel_put(&data->img, i, y - radius, 0x000000);
		}
		y_pos++;
		check_out_circle(y_pos, &err, &radius);
	}
}

void	stock_ray(t_data *data, double x, double y, int i)
{
	data->utils.rays[i].x = x;
	data->utils.rays[i].y = y;
}
