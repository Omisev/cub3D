/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:18:17 by raveriss          #+#    #+#             */
/*   Updated: 2024/02/29 19:31:57 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Include/cub3d.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->ll + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

void	init_mlx2(t_data *data)
{
	data->textures[0].ptr = mlx_xpm_file_to_image(data->mlx.ptr, \
	data->elem.no_path, &data->textures[0].w, &data->textures[0].h);
	if (!data->textures[0].ptr)
		ft_exit(data, "Error\ntexture NO not found!", EXIT_FAIL);
	data->textures[1].ptr = mlx_xpm_file_to_image(data->mlx.ptr, \
	data->elem.so_path, &data->textures[1].w, &data->textures[1].h);
	if (!data->textures[1].ptr)
		ft_exit(data, "Error\ntexture SO not found!", EXIT_FAIL);
	data->textures[2].ptr = mlx_xpm_file_to_image(data->mlx.ptr, \
	data->elem.ea_path, &data->textures[2].w, &data->textures[2].h);
	if (!data->textures[2].ptr)
		ft_exit(data, "Error\ntexture EA not found!", EXIT_FAIL);
	data->textures[3].ptr = mlx_xpm_file_to_image(data->mlx.ptr, \
	data->elem.we_path, &data->textures[3].w, &data->textures[3].h);
	if (!data->textures[3].ptr)
		ft_exit(data, "Error\ntexture WE not found!", EXIT_FAIL);
}

void	init_mlx(t_data *data)
{
	data->mlx.ptr = mlx_init();
	if (!data->mlx.ptr)
		ft_exit(data, "Error\nMLX error!", EXIT_FAIL);
	data->mlx.win_ptr = mlx_new_window(data->mlx.ptr, W, H, "cub3d");
	if (!data->mlx.win_ptr)
		ft_exit(data, "Error\nMLX error!", EXIT_FAIL);
	data->img.ptr = mlx_new_image(data->mlx.ptr, W, H);
	if (!data->img.ptr)
		ft_exit(data, "Error\nMLX error!", EXIT_FAIL);
	data->img.addr = mlx_get_data_addr(data->img.ptr, &data->img.bpp, \
	&data->img.ll, &data->img.end);
	if (!data->img.addr)
		ft_exit(data, "Error\nMLX error!", EXIT_FAIL);
	init_mlx2(data);
}
