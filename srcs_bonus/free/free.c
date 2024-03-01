/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoure <lgoure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:24:20 by raveriss          #+#    #+#             */
/*   Updated: 2024/03/01 12:14:53 by lgoure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Include/cub3d.h"

void	free_garcol(t_data *data)
{
	t_memory	*tmp;
	t_memory	*next;

	tmp = data->mem;
	while (tmp)
	{
		next = tmp->next;
		if (tmp->add)
			free(tmp->add);
		free(tmp);
		tmp = next;
	}
}

void	ft_free_all(t_data *data)
{
	int	i;

	i = 0;
	while (data->utils.input && data->utils.input[i])
		free(data->utils.input[i++]);
	free(data->utils.input);
	i = 0;
	while (data->elem.split_color_c && data->elem.split_color_c[i])
		free(data->elem.split_color_c[i++]);
	if (data->elem.split_color_c)
		free(data->elem.split_color_c);
	i = 0;
	while (data->elem.split_color_f && data->elem.split_color_f[i])
		free(data->elem.split_color_f[i++]);
	if (data->elem.split_color_f)
		free(data->elem.split_color_f);
	free_garcol(data);
}

void	free_text(t_data *data)
{
	int	i;

	if (data->textures[0].ptr)
		mlx_destroy_image(data->mlx.ptr, data->textures[0].ptr);
	if (data->textures[1].ptr)
		mlx_destroy_image(data->mlx.ptr, data->textures[1].ptr);
	if (data->textures[2].ptr)
		mlx_destroy_image(data->mlx.ptr, data->textures[2].ptr);
	if (data->textures[3].ptr)
		mlx_destroy_image(data->mlx.ptr, data->textures[3].ptr);
	if (data->textures[4].ptr)
		mlx_destroy_image(data->mlx.ptr, data->textures[4].ptr);
	i = 0;
	while (i < 12)
	{
		if (data->west_textures[i].ptr)
			mlx_destroy_image(data->mlx.ptr, data->west_textures[i].ptr);
		if (data->south_textures[i].ptr)
			mlx_destroy_image(data->mlx.ptr, data->south_textures[i].ptr);
		if (data->north_textures[i].ptr)
			mlx_destroy_image(data->mlx.ptr, data->north_textures[i].ptr);
		if (data->east_textures[i].ptr)
			mlx_destroy_image(data->mlx.ptr, data->east_textures[i].ptr);
		i++;
	}
}

int	ft_exit(t_data *data, char *msg_err, int exitcode)
{
	printf("%s\n", msg_err);
	free_text(data);
	if (data->mlx.win_ptr)
		mlx_destroy_window(data->mlx.ptr, data->mlx.win_ptr);
	if (data->img.ptr)
		mlx_destroy_image(data->mlx.ptr, data->img.ptr);
	if (data->mlx.ptr)
	{
		mlx_destroy_display(data->mlx.ptr);
		free(data->mlx.ptr);
	}
	if (data->utils.fd > 0)
		close(data->utils.fd);
	ft_free_all(data);
	free(data);
	exit(exitcode);
	return (0);
}
