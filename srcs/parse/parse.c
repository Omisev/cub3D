/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:18:24 by raveriss          #+#    #+#             */
/*   Updated: 2024/02/28 17:18:26 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Include/cub3d.h"

void	check_args(t_data *data, int ac, char **av)
{
	if (ac != 2)
		ft_exit(data, "Error\nBad number of arguments!", EXIT_FAIL);
	if (!is_cub(av[1]))
		ft_exit(data, "Error\nBad input file!", EXIT_FAIL);
}

int	check_char(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != ' '\
			&& map[i][j] != 'N' && map[i][j] != 'S' && map[i][j] != 'E' \
			&& map[i][j] != 'W')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_player(char **map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' \
			|| map[i][j] == 'W' || map[i][j] == 'E')
				count++;
			j++;
		}
		i++;
	}
	if (count != 1)
		return (1);
	return (0);
}

int	check_closed(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0' || is_player(map[i][j]))
			{
				if (map[i + 1][j] == ' ' || map[i - 1][j] == ' ' \
				|| map[i][j - 1] == ' ' || map[i][j + 1] == ' ')
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	parse_map(t_data *data, char **map)
{
	if (check_char(map))
		ft_exit(data, "Error\nUnexpected char in the map!", EXIT_FAIL);
	if (check_player(map))
		ft_exit(data, "Error\nSomething wrong with the player!", EXIT_FAIL);
	if (check_closed(map))
		ft_exit(data, "Error\nSomething wrong with the map!", EXIT_FAIL);
}
