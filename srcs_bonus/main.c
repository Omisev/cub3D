/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:27:26 by raveriss          #+#    #+#             */
/*   Updated: 2024/02/29 18:13:44 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/cub3d.h"

double	to_rad(double angle)
{
	return ((angle * PI) / 180);
}

void	get_and_parse(t_data *data, int ac, char **av)
{
	int	fl_map;

	check_args(data, ac, av);
	get_input(data, av);
	fl_map = get_elem(data);
	get_map(data, fl_map);
	parse_map(data, data->utils.map);
	get_player_pos(data);
}

void	init_data(t_data *data)
{
	int	i;

	i = 0;
	data->mem = NULL;
	data->textures[0].ptr = NULL;
	data->textures[1].ptr = NULL;
	data->textures[2].ptr = NULL;
	data->textures[3].ptr = NULL;
	data->textures[4].ptr = NULL;
	while (i < 12)
	{
		data->west_textures[i].ptr = NULL;
		data->east_textures[i].ptr = NULL;
		data->north_textures[i].ptr = NULL;
		data->south_textures[i].ptr = NULL;
		i++;
	}
	data->mlx.ptr = NULL;
	data->mlx.win_ptr = NULL;
	data->img.ptr = NULL;
	data->utils.input = NULL;
	data->elem.split_color_c = NULL;
	data->elem.split_color_f = NULL;
	data->frame = 0;
	data->utils.fd = -1;
}

int	main(int ac, char **av)
{
	t_data	*data;

	data = NULL;
	data = malloc(sizeof(t_data));
	if (!data)
		ft_exit(data, "Error\nAllocation error!", EXIT_FAIL);
	init_data(data);
	get_and_parse(data, ac, av);
	init_mlx(data);
	check_images_exist(data);
	load_west_textures(data, 0);
	load_east_textures(data, 0);
	load_north_textures(data, 0);
	load_south_textures(data, 0);
	mlx_loop_hook(data->mlx.ptr, draw_game, data);
	mlx_hook(data->mlx.win_ptr, 2, (1L << 0), ft_key, data);
	mlx_hook(data->mlx.win_ptr, 17, 0, ft_end, data);
	mlx_hook(data->mlx.win_ptr, 6, 1L << 6, handle_mouse_move, data);
	mlx_loop(data->mlx.ptr);
	ft_end(data);
}
