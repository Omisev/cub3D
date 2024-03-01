/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoure <lgoure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:27:11 by raveriss          #+#    #+#             */
/*   Updated: 2024/03/01 12:08:42 by lgoure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Include/cub3d.h"

double	ft_atan2(double y, double x)
{
	double	angle;

	angle = -atan2(y, x);
	if (angle < 0)
		angle += 2 * PI;
	return (angle);
}

int	coma_count(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == ',')
			count++;
		i++;
	}
	if (count != 2)
		return (1);
	return (0);
}

int	is_header(t_data *data, char *line)
{
	int	i;

	i = 0;
	if (!line)
		ft_exit(data, "Error\nSomething wrong with the map!", EXIT_FAIL);
	while (line && line[i] && line[i] == ' ')
		i++;
	if ((line && line[i] && line[i] == '1'))
		return (0);
	return (1);
}

int	is_cub(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (str[i - 1] != 'b' || str[i - 2] != 'u' || str[i - 3] != 'c' \
		|| str[i - 4] != '.' || !ft_is_alpha(str[i - 5]))
		return (0);
	return (1);
}

int	is_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}
