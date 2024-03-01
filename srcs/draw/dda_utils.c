/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:15:18 by raveriss          #+#    #+#             */
/*   Updated: 2024/02/28 17:15:21 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Include/cub3d.h"

int	is_wallv(t_data *data, double x, double y)
{
	if (!data->ray.isfacingr)
		x--;
	else
		x++;
	if ((int)floor(x / T_SIZE) < 0 \
	|| (int)floor(x / T_SIZE) > data->utils.max_len)
		return (0);
	if ((int)floor(y / T_SIZE) < 0 \
	|| (int)floor(y / T_SIZE) > data->utils.max_height)
		return (0);
	if (data->utils.map[(int)floor(y / T_SIZE)] \
	[(int)floor(x / T_SIZE)] == '1')
		return (1);
	return (0);
}

int	is_wallh(t_data *data, double x, double y)
{
	if (!data->ray.isfacingd)
		y--;
	else
		y++;
	if ((int)floor(x / T_SIZE) < 0 \
	|| (int)floor(x / T_SIZE) > data->utils.max_len)
		return (0);
	if ((int)floor(y / T_SIZE) < 0 \
	|| (int)floor(y / T_SIZE) > data->utils.max_height)
		return (0);
	if (data->utils.map[(int)floor(y / T_SIZE)] \
	[(int)floor(x / T_SIZE)] == '1')
		return (1);
	return (0);
}
