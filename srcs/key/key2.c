/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:18:10 by raveriss          #+#    #+#             */
/*   Updated: 2024/02/28 17:18:13 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Include/cub3d.h"

int	ft_end(t_data *data)
{
	ft_exit(data, "Merci d'avoir joué au jeu!", EXIT_SUCCESS);
	return (1);
}

void	rotate_left(t_data *data)
{
	double	distance;

	data->player.dir_x = data->player.dir_x * cos(PI / TURN_ANGLE) \
	+ data->player.dir_y * sin(PI / TURN_ANGLE);
	data->player.dir_y = data->player.dir_y * cos(PI / TURN_ANGLE) \
	- data->player.dir_x * sin(PI / TURN_ANGLE);
	distance = hypot(data->player.dir_x, data->player.dir_y);
	data->player.dir_y /= distance;
	data->player.dir_x /= distance;
}

void	rotate_right(t_data *data)
{
	double	distance;

	data->player.dir_x = data->player.dir_x * cos(PI / TURN_ANGLE) \
	- data->player.dir_y * sin(PI / TURN_ANGLE);
	data->player.dir_y = data->player.dir_x * sin(PI / TURN_ANGLE) \
	+ data->player.dir_y * cos(PI / TURN_ANGLE);
	distance = hypot(data->player.dir_x, data->player.dir_y);
	data->player.dir_x /= distance;
	data->player.dir_y /= distance;
}
