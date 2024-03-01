/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 00:13:07 by raveriss          #+#    #+#             */
/*   Updated: 2024/03/01 00:13:27 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Include/cub3d.h"

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
