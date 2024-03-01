/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elem.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:25:17 by raveriss          #+#    #+#             */
/*   Updated: 2024/02/29 17:13:10 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Include/cub3d.h"

void	get_no_path(t_data *data, char *str)
{
	int	i;

	i = 0;
	if (data->elem.no_path)
		ft_exit(data, "Error\nInvalid north path!", EXIT_FAIL);
	while (str[i] == ' ')
		i++;
	if ((str[i] == '/') || (str[i] == '.' && str[i + 1] == '/'))
		data->elem.no_path = ft_strdup_no_space(data, &str[i]);
	else
		ft_exit(data, "Error\nInvalid north path!", EXIT_FAIL);
	i = open(data->elem.no_path, 0);
	if (i == -1)
	{
		close(i);
		ft_exit(data, "Error\nInvalid north path!", EXIT_FAIL);
	}
	close(i);
}

void	ft_get_elem(t_data *data, char *line)
{
	int	i;

	i = 0;
	while (line && line[i] && line[i] == ' ')
		i++;
	if (!line || !line[i])
		return ;
	if (!ft_strncmp(&line[i], "NO", 2))
		get_no_path(data, &line[i] + 2);
	else if (!ft_strncmp(&line[i], "SO", 2))
		get_so_path(data, &line[i] + 2);
	else if (!ft_strncmp(&line[i], "EA", 2))
		get_ea_path(data, &line[i] + 2);
	else if (!ft_strncmp(&line[i], "WE", 2))
		get_we_path(data, &line[i] + 2);
	else if (line[i] == 'C')
		get_c_colors(data, &line[i] + 1);
	else if (line[i] == 'F')
		get_f_colors(data, &line[i] + 1);
	else
		ft_exit(data, "Error\nSomething wrong with the input!", EXIT_FAIL);
}

void	init_elem(t_data *data)
{
	data->elem.no_path = NULL;
	data->elem.so_path = NULL;
	data->elem.ea_path = NULL;
	data->elem.we_path = NULL;
	data->elem.colors_c[0] = -1;
	data->elem.colors_c[1] = -1;
	data->elem.colors_c[2] = -1;
	data->elem.colors_f[0] = -1;
	data->elem.colors_f[1] = -1;
	data->elem.colors_f[2] = -1;
}

int	get_elem(t_data *data)
{
	int	j;

	j = 0;
	init_elem(data);
	while (is_header(data, data->utils.input[j]))
		ft_get_elem(data, data->utils.input[j++]);
	if (!data->elem.so_path || !data->elem.no_path || !data->elem.ea_path
		|| !data->elem.we_path || data->elem.colors_c[0] == -1
		|| data->elem.colors_c[1] == -1 || data->elem.colors_c[2] == -1
		|| data->elem.colors_f[0] == -1 || data->elem.colors_f[1] == -1
		|| data->elem.colors_f[2] == -1)
		ft_exit(data, "Error\nMissing element!", EXIT_FAIL);
	j = 0;
	while (is_header(data, data->utils.input[j]))
		j++;
	return (j);
}
