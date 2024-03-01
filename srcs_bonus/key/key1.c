/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:25:49 by raveriss          #+#    #+#             */
/*   Updated: 2024/02/29 18:13:18 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Include/cub3d.h"

void	move_front(t_data *data)
{
	data->player.pos_x += data->player.dir_x * SPEED;
	if (data->utils.map[\
	(int)floor(data->player.pos_y)][(int)floor(data->player.pos_x)] == '1')
		data->player.pos_x -= SPEED * (data->player.dir_x);
	data->player.pos_y += data->player.dir_y * SPEED;
	if (data->utils.map[\
	(int)floor(data->player.pos_y)][(int)floor(data->player.pos_x)] == '1')
		data->player.pos_y -= SPEED * (data->player.dir_y);
}

void	move_back(t_data *data)
{
	data->player.pos_x -= data->player.dir_x * SPEED;
	if (data->utils.map[\
	(int)floor(data->player.pos_y)][(int)floor(data->player.pos_x)] == '1')
		data->player.pos_x += SPEED * (data->player.dir_x);
	data->player.pos_y -= data->player.dir_y * SPEED;
	if (data->utils.map[\
	(int)floor(data->player.pos_y)][(int)(data->player.pos_x)] == '1')
		data->player.pos_y += SPEED * (data->player.dir_y);
}

void	move_left(t_data *data)
{
	data->player.pos_x += data->player.dir_y * SPEED;
	if (data->utils.map[\
	(int)floor(data->player.pos_y)][(int)(data->player.pos_x)] == '1')
		data->player.pos_x -= SPEED * (data->player.dir_y);
	data->player.pos_y -= data->player.dir_x * SPEED;
	if (data->utils.map[\
	(int)floor(data->player.pos_y)][(int)(data->player.pos_x)] == '1')
		data->player.pos_y += SPEED * (data->player.dir_x);
}

void	move_right(t_data *data)
{
	data->player.pos_x -= data->player.dir_y * SPEED;
	if (data->utils.map[\
	(int)floor(data->player.pos_y)][(int)(data->player.pos_x)] == '1')
		data->player.pos_x += SPEED * (data->player.dir_y);
	data->player.pos_y += data->player.dir_x * SPEED;
	if (data->utils.map[\
	(int)floor(data->player.pos_y)][(int)(data->player.pos_x)] == '1')
		data->player.pos_y -= SPEED * (data->player.dir_x);
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
