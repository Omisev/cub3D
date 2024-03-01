/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:26:00 by raveriss          #+#    #+#             */
/*   Updated: 2024/02/29 18:46:58 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Include/cub3d.h"

void	normalize_vector(t_data *data, double distance)
{
	if (distance > 0)
	{
		data->player.dir_y /= distance;
		data->player.dir_x /= distance;
	}
}

static void	rotate_mouse_player(t_data *data, double speed)
{
	double	distance;

	if (data == NULL || &(data->player) == NULL)
		return ;
	if (speed < 0)
	{
		speed = -speed;
		data->player.dir_x = data->player.dir_x * cos(PI / TURN_ANGLE)
			+ data->player.dir_y * sin(PI / TURN_ANGLE) / 6;
		data->player.dir_y = data->player.dir_y * cos(PI / TURN_ANGLE)
			- data->player.dir_x * sin(PI / TURN_ANGLE) / 6;
		distance = hypot(data->player.dir_x, data->player.dir_y);
		normalize_vector(data, distance);
	}
	else if (speed > 0)
	{
		data->player.dir_x = data->player.dir_x * cos(PI / TURN_ANGLE)
			- data->player.dir_y * sin(PI / TURN_ANGLE) / 6;
		data->player.dir_y = data->player.dir_x * (sin(PI / TURN_ANGLE) / 6)
			+ data->player.dir_y * cos(PI / TURN_ANGLE);
		distance = hypot(data->player.dir_x, data->player.dir_y);
		normalize_vector(data, distance);
	}
	mlx_mouse_move(data->mlx.ptr, data->mlx.win_ptr, W / 2, H / 2);
}

int	handle_mouse_move(int x, int y, void *param)
{
	t_data	*data;

	(void)y;
	data = (t_data *)param;
	if (1)
	{
		if (x != W / 2)
			rotate_mouse_player(data, (double)(x - (W / 2)));
	}
	return (0);
}
