/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:14:36 by raveriss          #+#    #+#             */
/*   Updated: 2024/02/28 17:14:38 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib.h"

int	ft_strstr(char *str, char *to_find)
{
	int	i;
	int	z;
	int	find_size;

	i = 0;
	z = 0;
	find_size = 0;
	while (to_find[find_size] != '\0')
		find_size++;
	while (str[i] != '\0')
	{
		while (to_find[z] == str[i + z])
		{
			if (z == find_size - 1)
				return (1);
			z++;
		}
		z = 0;
		i++;
	}
	return (0);
}
