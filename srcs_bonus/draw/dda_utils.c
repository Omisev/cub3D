/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:23:35 by raveriss          #+#    #+#             */
/*   Updated: 2024/02/29 23:30:51 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Include/cub3d.h"

bool	is_new_hit_distance_smaller(t_data *data)
{
	return (data->ray.distance > hypot(data->ray.xintercept - data->player. \
			pos_x * T_SIZE, \
			data->ray.yintercept - data->player.pos_y * T_SIZE));
}

bool	is_ray_in_limits(const t_data *data)
{
	return (data->ray.xintercept >= 0 \
		&& data->ray.xintercept <= data->utils.max_len * T_SIZE \
		&& data->ray.yintercept >= 0 \
		&& data->ray.yintercept <= data->utils.max_height * T_SIZE);
}

void	update_hor_hit(t_data *data)
{
	data->ray.wallhit_x = data->ray.xintercept;
	data->ray.wallhit_y = data->ray.yintercept;
	data->ray.hithv = 0;
	data->ray.distance = \
	hypot(data->ray.xintercept - data->player.pos_x * T_SIZE, \
	data->ray.yintercept - data->player.pos_y * T_SIZE);
}

int	is_wallv(t_data *data, double x, double y)
{
	if (!data->ray.isfacingr)
		x--;
	else
		x++;
	if ((int)floor(x / T_SIZE) < 0 || (int)floor(x
			/ T_SIZE) > data->utils.max_len)
		return (0);
	if ((int)floor(y / T_SIZE) < 0 || (int)floor(y
			/ T_SIZE) > data->utils.max_height)
		return (0);
	if (data->utils.map[(int)floor(y / T_SIZE)][(int)floor(x / T_SIZE)] == '1')
		return (1);
	if (data->utils.map[(int)floor(y / T_SIZE)][(int)floor(x / T_SIZE)] == 'P')
		return (2);
	return (0);
}

int	is_wallh(t_data *data, double x, double y)
{
	if (!data->ray.isfacingd)
		y--;
	else
		y++;
	if ((int)floor(x / T_SIZE) < 0 || (int)floor(x
			/ T_SIZE) > data->utils.max_len)
		return (0);
	if ((int)floor(y / T_SIZE) < 0 || (int)floor(y
			/ T_SIZE) > data->utils.max_height)
		return (0);
	if (data->utils.map[(int)floor(y / T_SIZE)][(int)floor(x / T_SIZE)] == '1')
		return (1);
	if (data->utils.map[(int)floor(y / T_SIZE)][(int)floor(x / T_SIZE)] == 'P')
		return (2);
	return (0);
}
