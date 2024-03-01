/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoure <lgoure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:27:18 by raveriss          #+#    #+#             */
/*   Updated: 2024/03/01 12:14:44 by lgoure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Include/cub3d.h"

int	ft_strlen2(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != ' ')
		i++;
	return (i);
}

char	*ft_strdup_no_space(t_data *data, char *s1)
{
	int		len;
	int		i;
	char	*res;

	len = ft_strlen2(s1);
	res = NULL;
	res = ft_malloc(data, sizeof(char) * (len + 1));
	if (!res)
		ft_exit(data, "Error\nAllocation error!", EXIT_FAIL);
	i = 0;
	while (s1[i] && s1[i] != ' ')
	{
		res[i] = s1[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

int	check_for_nl(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		while (str[i] && str[i] == ' ')
			i++;
		if (str[i] == '1')
			return (0);
		else
			return (1);
		i++;
	}
	return (1);
}

void	check_after_nl(t_data *data, int j)
{
	while (data->utils.input[j])
	{
		if (data->utils.input[j][0] && data->utils.input[j][0] != '\n' \
		&& data->utils.input[j][0] != ' ')
			ft_exit(data, "Error\nSomething wrong with the map!", EXIT_FAIL);
		j++;
	}
}
