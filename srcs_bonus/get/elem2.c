/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elem2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:25:24 by raveriss          #+#    #+#             */
/*   Updated: 2024/02/29 17:13:13 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Include/cub3d.h"

void	get_f_colors(t_data *data, char *str)
{
	int	i;
	int	nb;

	i = 0;
	if (data->elem.colors_f[0] != -1 || data->elem.colors_f[1] != -1
		|| data->elem.colors_f[2] != -1)
		ft_exit(data, "Error\nInvalid color for floor!", EXIT_FAIL);
	while (str[i] == ' ')
		i++;
	if (coma_count(&str[i]))
		ft_exit(data, "Error\nInvalid color for floor!", EXIT_FAIL);
	data->elem.split_color_f = ft_split(&str[i], ',');
	i = 0;
	while (data->elem.split_color_f[i])
	{
		nb = ft_atoi(data->elem.split_color_f[i]);
		if (nb < 0 || nb > 255)
			ft_exit(data, "Error\nInvalid color for floor!", EXIT_FAIL);
		data->elem.colors_f[i] = nb;
		i++;
	}
	if (data->elem.colors_f[0] == -1 || data->elem.colors_f[1] == -1
		|| data->elem.colors_f[2] == -1)
		ft_exit(data, "Error\nInvalid color for floor!", EXIT_FAIL);
}

void	get_c_colors(t_data *data, char *str)
{
	int	i;
	int	nb;

	i = 0;
	if (data->elem.colors_c[0] != -1 || data->elem.colors_c[1] != -1
		|| data->elem.colors_c[2] != -1)
		ft_exit(data, "Error\nInvalid color for ceiling!", EXIT_FAIL);
	while (str[i] == ' ')
		i++;
	if (coma_count(&str[i]))
		ft_exit(data, "Error\nInvalid color for ceiling!", EXIT_FAIL);
	data->elem.split_color_c = ft_split(&str[i], ',');
	i = 0;
	while (data->elem.split_color_c[i])
	{
		nb = ft_atoi(data->elem.split_color_c[i]);
		if (nb < 0 || nb > 255)
			ft_exit(data, "Error\nInvalid color for ceiling!", EXIT_FAIL);
		data->elem.colors_c[i] = nb;
		i++;
	}
	if (data->elem.colors_c[0] == -1 || data->elem.colors_c[1] == -1
		|| data->elem.colors_c[2] == -1)
		ft_exit(data, "Error\nInvalid color for ceiling!", EXIT_FAIL);
}

void	get_we_path(t_data *data, char *str)
{
	int	i;

	i = 0;
	if (data->elem.we_path)
		ft_exit(data, "Error\nInvalid west path!", EXIT_FAIL);
	while (str[i] == ' ')
		i++;
	if ((str[i] == '/') || (str[i] == '.' && str[i + 1] == '/'))
		data->elem.we_path = ft_strdup_no_space(data, &str[i]);
	else
		ft_exit(data, "Error\nInvalid west path!", EXIT_FAIL);
	i = open(data->elem.we_path, 0);
	if (i == -1)
	{
		close(i);
		ft_exit(data, "Error\nInvalid south path!", EXIT_FAIL);
	}
	close(i);
}

void	get_ea_path(t_data *data, char *str)
{
	int	i;

	i = 0;
	if (data->elem.ea_path)
		ft_exit(data, "Error\nInvalid east path!", EXIT_FAIL);
	while (str[i] == ' ')
		i++;
	if ((str[i] == '/') || (str[i] == '.' && str[i + 1] == '/'))
		data->elem.ea_path = ft_strdup_no_space(data, &str[i]);
	else
		ft_exit(data, "Error\nInvalid eath path!", EXIT_FAIL);
	i = open(data->elem.ea_path, 0);
	if (i == -1)
	{
		close(i);
		ft_exit(data, "Error\nInvalid south path!", EXIT_FAIL);
	}
	close(i);
}

void	get_so_path(t_data *data, char *str)
{
	int	i;

	i = 0;
	if (data->elem.so_path)
		ft_exit(data, "Error\nInvalid south path!", EXIT_FAIL);
	while (str[i] == ' ')
		i++;
	if ((str[i] == '/') || (str[i] == '.' && str[i + 1] == '/'))
		data->elem.so_path = ft_strdup_no_space(data, &str[i]);
	else
		ft_exit(data, "Error\nInvalid south path!", EXIT_FAIL);
	i = open(data->elem.so_path, 0);
	if (i == -1)
	{
		close(i);
		ft_exit(data, "Error\nInvalid south path!", EXIT_FAIL);
	}
	close(i);
}
