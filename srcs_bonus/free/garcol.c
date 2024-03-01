/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garcol.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:24:25 by raveriss          #+#    #+#             */
/*   Updated: 2024/02/28 17:24:28 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Include/cub3d.h"

void	add_in_list(t_data *data, void *add)
{
	t_memory	*maillon;
	t_memory	*tmp;

	maillon = malloc(sizeof(t_memory));
	if (!maillon)
		ft_exit(data, "Error\nMalloc error!", EXIT_FAIL);
	maillon->add = add;
	maillon->next = NULL;
	if (!data->mem)
		data->mem = maillon;
	else
	{
		tmp = data->mem;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = maillon;
	}
}

void	*ft_malloc(t_data *data, size_t size)
{
	void	*add;

	add = malloc(size);
	if (!add)
		ft_exit(data, "Error\nMalloc error!", EXIT_FAIL);
	add_in_list(data, add);
	return (add);
}
