/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:23:50 by raveriss          #+#    #+#             */
/*   Updated: 2024/03/01 00:13:50 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Include/cub3d.h"

void	draw_the_rest(t_data *data)
{
	draw_minimap(data, data->utils.map);
	draw_player(data, data->player.pos_x * T_SIZE * MMSF, \
	data->player.pos_y * T_SIZE * MMSF, 5);
	mlx_put_image_to_window(data->mlx.ptr, data->mlx.win_ptr, \
	data->img.ptr, 0, 0);
}

int	has_hit_a_door(t_data *data)
{
	if (data->utils.map[\
	(int)floor(data->player.pos_y)][(int)floor(data->player.pos_x)] == 'P')
		return (1);
	else if (data->utils.map[\
	(int)floor(data->player.pos_y) - 1][(int)floor(data->player.pos_x)] == 'P')
		return (1);
	else if (data->utils.map[\
	(int)floor(data->player.pos_y) + 1][(int)floor(data->player.pos_x)] == 'P')
		return (1);
	else if (data->utils.map[\
	(int)floor(data->player.pos_y)][(int)floor(data->player.pos_x) + 1] == 'P')
		return (1);
	else if (data->utils.map[\
	(int)floor(data->player.pos_y)][(int)floor(data->player.pos_x) - 1] == 'P')
		return (1);
	return (0);
}

void	update_wall_projection(t_data *data, double ray_angle, double dir_angle)
{
	data->ray.distance = fix_fisheye(data, ray_angle, dir_angle);
	data->wall.height = (double)floor(H / data->ray.distance);
	data->wall.top = (H / 2) - (data->wall.height / 2);
	data->wall.bottom = (H / 2) + (data->wall.height / 2);
}

void	calculate_ray_and_dir_angles(\
t_data *data, double *ray_angle, double *dir_angle)
{
	*ray_angle = ft_atan2(data->ray.y, data->ray.x);
	*dir_angle = ft_atan2(data->player.dir_y, data->player.dir_x);
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
		calculate_ray_and_dir_angles(data, &ray_angle, &dir_angle);
		if (has_hit_a_door(data))
			data->wall.open = 1;
		else
			data->wall.open = 0;
		ray_orientation(data);
		horizontal_hit(data, ray_angle);
		vertical_hit(data, ray_angle);
		data->ray.distance /= T_SIZE;
		stock_ray(data, data->ray.wallhit_x, data->ray.wallhit_y, i);
		update_wall_projection(data, ray_angle, dir_angle);
		texture_hit_x(data);
		draw_strip(data, i++);
		ray_rotate(data);
	}
	draw_the_rest(data);
	return (0);
}
