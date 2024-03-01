/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:15:56 by raveriss          #+#    #+#             */
/*   Updated: 2024/02/28 17:15:59 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Include/cub3d.h"

unsigned int	get_text_color(void *img, int x, int y)
{
	t_img			tmp;
	unsigned int	color;
	char			*dst;

	tmp.addr = mlx_get_data_addr(img, &tmp.bpp, &tmp.ll, &tmp.end);
	dst = tmp.addr + (y * tmp.ll + x * (tmp.bpp / 8));
	color = *(unsigned int *)dst;
	return (color);
}

void	draw_text(t_data *data, t_img *imgtext, int x, int y)
{
	int	color;

	color = get_text_color(imgtext->ptr, data->ray.texx, data->ray.texy);
	my_mlx_pixel_put(&data->img, x, y, color);
}

void	draw_texture(t_data *data, int y, int i)
{
	int	distancefromtop;

	distancefromtop = y + (data->wall.height / 2) - (H / 2);
	data->ray.texy = distancefromtop * \
	((float)TEXTURE_SIZE / data->wall.height);
	if (!data->ray.hithv && data->ray.isfacingd)
		draw_text(data, &data->textures[1], i, y);
	else if (!data->ray.hithv && !data->ray.isfacingd)
		draw_text(data, &data->textures[0], i, y);
	else if (data->ray.hithv && !data->ray.isfacingr)
		draw_text(data, &data->textures[3], i, y);
	else if (data->ray.hithv && data->ray.isfacingr)
		draw_text(data, &data->textures[2], i, y);
}

void	draw_strip(t_data *data, int i)
{
	int	y;

	y = 0;
	while (y < H)
	{
		if (y >= round(data->wall.top) && y < (data->wall.bottom))
			draw_texture(data, y, i);
		y++;
	}
}

void	texture_hit_x(t_data *data)
{
	if (!data->ray.hithv)
		data->ray.texx = (int)data->ray.wallhit_x % T_SIZE;
	else
		data->ray.texx = (int)data->ray.wallhit_y % T_SIZE;
}
