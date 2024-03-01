/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:15:25 by raveriss          #+#    #+#             */
/*   Updated: 2024/02/28 17:15:28 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Include/cub3d.h"

double	fix_fisheye(t_data *data, double ray_angle, double dir_angle)
{
	double	distance;

	distance = data->ray.distance * cos(ray_angle - dir_angle);
	return (distance);
}

void	find_ver_hit(t_data *data, double xstep, double ystep)
{
	while (data->ray.xintercept >= 0 && data->ray.xintercept <= \
	data->utils.max_len * T_SIZE && data->ray.yintercept >= 0 && \
	data->ray.yintercept <= data->utils.max_height * T_SIZE)
	{
		if (is_wallv(data, data->ray.xintercept, data->ray.yintercept))
		{
			if (data->ray.distance > hypot(data->ray.xintercept - data->player. \
			pos_x * T_SIZE, data->ray.yintercept - data->player.pos_y * T_SIZE))
			{
				data->ray.wallhit_x = data->ray.xintercept;
				data->ray.wallhit_y = data->ray.yintercept;
				data->ray.hithv = 1;
				data->ray.distance = hypot(data->ray.xintercept - \
				data->player.pos_x * T_SIZE, data->ray.yintercept - \
				data->player.pos_y * T_SIZE);
				return ;
			}
		}
		data->ray.xintercept += xstep;
		data->ray.yintercept += ystep;
	}
}

void	vertical_hit(t_data *data, double ray_angle)
{
	double	xstep;
	double	ystep;

	if (data->ray.isfacingr)
		data->ray.xintercept = floor(data->player.pos_x) * T_SIZE + T_SIZE;
	else
		data->ray.xintercept = floor(data->player.pos_x) * T_SIZE;
	data->ray.yintercept = data->player.pos_y * T_SIZE + \
	((data->player.pos_x * T_SIZE) - data->ray.xintercept) * tan(ray_angle);
	xstep = T_SIZE;
	if (!data->ray.isfacingr)
		xstep *= -1;
	ystep = tan(ray_angle) * T_SIZE;
	if (!data->ray.isfacingd && ystep > 0)
		ystep *= -1;
	if (data->ray.isfacingd && ystep < 0)
		ystep *= -1;
	find_ver_hit(data, xstep, ystep);
}

void	find_hor_hit(t_data *data, double xstep, double ystep)
{
	while (data->ray.xintercept >= 0 && data->ray.xintercept \
	<= data->utils.max_len * T_SIZE && data->ray.yintercept \
	>= 0 && data->ray.yintercept <= data->utils.max_height * T_SIZE)
	{
		if (is_wallh(data, data->ray.xintercept, data->ray.yintercept))
		{
			data->ray.wallhit_x = data->ray.xintercept;
			data->ray.wallhit_y = data->ray.yintercept;
			data->ray.hithv = 0;
			data->ray.distance = hypot(data->ray.xintercept - \
			data->player.pos_x * T_SIZE, data->ray.yintercept - \
			data->player.pos_y * T_SIZE);
			return ;
		}
		data->ray.xintercept += xstep;
		data->ray.yintercept += ystep;
	}
	data->ray.wallhit_x = data->player.pos_x;
	data->ray.wallhit_y = data->player.pos_y;
	data->ray.distance = 100000000;
}

void	horizontal_hit(t_data *data, double ray_angle)
{
	double	xstep;
	double	ystep;

	if (data->ray.isfacingd)
		data->ray.yintercept = floor(data->player.pos_y) * T_SIZE + T_SIZE;
	else
		data->ray.yintercept = floor(data->player.pos_y) * T_SIZE;
	data->ray.xintercept = data->player.pos_x * T_SIZE \
	+ ((data->player.pos_y * T_SIZE) - data->ray.yintercept) / (tan(ray_angle));
	ystep = T_SIZE;
	if (!data->ray.isfacingd)
		ystep = -T_SIZE;
	xstep = (T_SIZE) / (tan(ray_angle));
	if (!data->ray.isfacingr && xstep > 0)
		xstep *= -1;
	if (data->ray.isfacingr && xstep < 0)
		xstep *= -1;
	find_hor_hit(data, xstep, ystep);
}
