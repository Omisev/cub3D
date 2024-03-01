/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fix_fisheye.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 23:31:28 by raveriss          #+#    #+#             */
/*   Updated: 2024/02/29 23:32:01 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Include/cub3d.h"

double	fix_fisheye(t_data *data, double ray_angle, double dir_angle)
{
	double	distance;

	distance = data->ray.distance * cos(ray_angle - dir_angle);
	return (distance);
}
