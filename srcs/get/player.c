/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:16:44 by raveriss          #+#    #+#             */
/*   Updated: 2024/02/28 17:16:46 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Include/cub3d.h"

void	get_dir(t_data *data, char c)
{
	if (c == 'S')
	{
		data->player.dir_y = 1;
		data->player.dir_x = 0;
	}
	else if (c == 'N')
	{
		data->player.dir_y = -1;
		data->player.dir_x = 0;
	}
	else if (c == 'E')
	{
		data->player.dir_y = 0;
		data->player.dir_x = 1;
	}
	else if (c == 'W')
	{
		data->player.dir_y = 0;
		data->player.dir_x = -1;
	}
}

void	get_player_pos(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->utils.map[i])
	{
		j = 0;
		while (data->utils.map[i][j])
		{
			if (is_player(data->utils.map[i][j]))
			{
				data->player.pos_x = j + 0.5;
				data->player.pos_y = i + 0.5;
				get_dir(data, data->utils.map[i][j]);
			}
			j++;
		}
		i++;
	}
}
