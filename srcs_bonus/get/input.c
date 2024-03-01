/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:25:32 by raveriss          #+#    #+#             */
/*   Updated: 2024/02/29 17:13:17 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Include/cub3d.h"

int	nb_fileline(t_data *data, char **av)
{
	int		nb;
	int		fd;
	char	*line;

	nb = 0;
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		ft_exit(data, "Error\nReading input file!", EXIT_FAIL);
	line = " ";
	while (line)
	{
		line = get_next_line(fd);
		free(line);
		nb++;
	}
	close(fd);
	return (nb);
}

void	get_input(t_data *data, char **av)
{
	int	i;
	int	j;

	j = 0;
	i = nb_fileline(data, av);
	data->utils.input = malloc(sizeof(char *) * (i + 1));
	if (!data->utils.input)
		ft_exit(data, "Error\nAllocation!", EXIT_FAIL);
	data->utils.fd = open(av[1], O_RDONLY);
	if (data->utils.fd < 0)
		ft_exit(data, "Error\nReading input file!", EXIT_FAIL);
	while (j <= i)
	{
		data->utils.input[j] = get_next_line(data->utils.fd);
		j++;
	}
	j--;
	data->utils.input[j] = NULL;
}
