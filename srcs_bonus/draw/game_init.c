/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 23:40:28 by raveriss          #+#    #+#             */
/*   Updated: 2024/03/01 03:56:10 by raveriss         ###   ########.fr       */
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
	data->wall.porte = 0;
	data->wall.open = 0;
	data->ray.color = 0x808080;
	draw_skyground(data);
}
