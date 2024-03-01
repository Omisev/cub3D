/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:16:50 by raveriss          #+#    #+#             */
/*   Updated: 2024/02/29 01:01:09 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Include/cub3d.h"

void	move_front(t_data *data)
{
	data->player.pos_x += data->player.dir_x * SPEED;
	data->player.pos_y += data->player.dir_y * SPEED;
}

void	move_back(t_data *data)
{
	data->player.pos_x -= data->player.dir_x * SPEED;
	data->player.pos_y -= data->player.dir_y * SPEED;
}

void	move_left(t_data *data)
{
	data->player.pos_x += data->player.dir_y * SPEED;
	data->player.pos_y -= data->player.dir_x * SPEED;
}

void	move_right(t_data *data)
{
	data->player.pos_x -= data->player.dir_y * SPEED;
	data->player.pos_y += data->player.dir_x * SPEED;
}

int	ft_key(int key, t_data *data)
{
	if (key == XK_w)
		move_front(data);
	else if (key == XK_s)
		move_back(data);
	else if (key == XK_a)
		move_left(data);
	else if (key == XK_d)
		move_right(data);
	else if (key == XK_Escape)
		ft_exit(data, "Merci d'avoir joué au jeu!", EXIT_SUCCESS);
	else if (key == XK_Right)
		rotate_right(data);
	else if (key == XK_Left)
		rotate_left(data);
	return (1);
}
