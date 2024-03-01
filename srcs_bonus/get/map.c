/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:25:37 by raveriss          #+#    #+#             */
/*   Updated: 2024/02/29 17:13:21 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Include/cub3d.h"

char	*complete_spaces(t_data *data, int fl_map)
{
	char	*line;
	int		j;
	int		i;

	i = 0;
	j = 1;
	line = ft_malloc(data, sizeof(char) * (data->utils.max_len + 3));
	if (!line)
		ft_exit(data, "Error\nAllocation error!", EXIT_FAIL);
	line[0] = ' ';
	while (data->utils.input[fl_map][i])
	{
		line[j] = data->utils.input[fl_map][i];
		i++;
		j++;
	}
	while (j <= data->utils.max_len)
	{
		line[j] = ' ';
		j++;
	}
	line[j] = ' ';
	j++;
	line[j] = '\0';
	return (line);
}

char	*fill_spaces(t_data *data, int max_len)
{
	char	*line;
	int		i;

	i = 0;
	line = ft_malloc(data, sizeof(char) * (max_len + 3));
	if (!line)
		ft_exit(data, "Error\nAllocation error!", EXIT_FAIL);
	while (i < max_len + 2)
	{
		line[i] = ' ';
		i++;
	}
	line[i] = '\0';
	return (line);
}

void	get_map2(t_data *data, int k, int i, int fl_map)
{
	while (k <= i)
	{
		data->utils.map[k] = complete_spaces(data, fl_map);
		fl_map++;
		k++;
	}
	data->utils.map[k] = fill_spaces(data, data->utils.max_len);
	data->utils.max_height = k;
	k++;
	data->utils.map[k] = NULL;
}

void	get_map(t_data *data, int fl_map)
{
	int	j;
	int	i;
	int	k;

	k = 1;
	i = 0;
	j = fl_map;
	data->utils.max_len = 0;
	while (data->utils.input[j])
	{
		if (check_for_nl(data->utils.input[j]))
			break ;
		if (ft_strlen(data->utils.input[j]) > data->utils.max_len)
			data->utils.max_len = ft_strlen(data->utils.input[j]);
		j++;
		i++;
	}
	check_after_nl(data, j);
	data->utils.map = ft_malloc(data, sizeof(char *) * (i + 3));
	if (!data->utils.map)
		ft_exit(data, "Error\nAllocation error!", EXIT_FAIL);
	data->utils.map[0] = fill_spaces(data, data->utils.max_len);
	get_map2(data, k, i, fl_map);
}
