/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:15:31 by raveriss          #+#    #+#             */
/*   Updated: 2024/02/29 16:29:26 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Include/cub3d.h"

void	init(t_data *data)
{
	double	distance;

	data->ray.x = data->player.dir_x * cos(-to_rad(FOV_ANGLE) / 2) \
	- data->player.dir_y * sin(-to_rad(FOV_ANGLE) / 2);
	data->ray.y = data->player.dir_x * sin(-to_rad(FOV_ANGLE) / 2) \
	+ data->player.dir_y * cos(-to_rad(FOV_ANGLE) / 2);
	distance = hypot(data->ray.x, data->ray.y);
	data->ray.x /= distance;
	data->ray.y /= distance;
	data->ray.wallhit_x = 0;
	data->ray.wallhit_y = 0;
	data->ray.distance = 0;
	data->ray.hithv = 0;
	data->ray.color = 0x87CEEB;
	draw_skyground(data);
}

void	ray_orientation(t_data *data)
{
	if (data->ray.x > 0)
		data->ray.isfacingr = 1;
	else
		data->ray.isfacingr = 0;
	if (data->ray.y < 0)
		data->ray.isfacingd = 0;
	else
		data->ray.isfacingd = 1;
}

void	ray_rotate(t_data *data)
{
	double	distance;

	data->ray.x = data->ray.x * cos(-to_rad(FOV_ANGLE) / W) \
	+ data->ray.y * sin(-to_rad(FOV_ANGLE) / W);
	data->ray.y = data->ray.y * cos(-to_rad(FOV_ANGLE) / W) \
	- data->ray.x * sin(-to_rad(FOV_ANGLE) / W);
	distance = hypot(data->ray.x, data->ray.y);
	data->ray.x /= distance;
	data->ray.y /= distance;
}

void	draw_the_rest(t_data *data)
{
	mlx_put_image_to_window(data->mlx.ptr, data->mlx.win_ptr, \
	data->img.ptr, 0, 0);
}

int	draw_game(t_data *data)
{
	int		i;
	double	ray_angle;
	double	dir_angle;

	init(data);
	i = 0;
	while (i < W)
	{
		ray_angle = ft_atan2(data->ray.y, data->ray.x);
		dir_angle = ft_atan2(data->player.dir_y, data->player.dir_x);
		ray_orientation(data);
		horizontal_hit(data, ray_angle);
		vertical_hit(data, ray_angle);
		data->ray.distance /= T_SIZE;
		stock_ray(data, data->ray.wallhit_x, data->ray.wallhit_y, i);
		data->ray.distance = fix_fisheye(data, ray_angle, dir_angle);
		data->wall.height = (double)floor(H / data->ray.distance);
		data->wall.top = (H / 2) - (data->wall.height / 2);
		data->wall.bottom = (H / 2) + (data->wall.height / 2);
		texture_hit_x(data);
		draw_strip(data, i++);
		ray_rotate(data);
	}
	draw_the_rest(data);
	return (0);
}
