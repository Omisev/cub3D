/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:14:30 by raveriss          #+#    #+#             */
/*   Updated: 2024/02/28 17:14:33 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib.h"

int	ft_strncmp(char *s1, char *s2, int n)
{
	int	i;
	int	t;

	i = 0;
	t = 0;
	if (s1[i] == '\0' && s2[i] == '\0')
		return (0);
	while (i < n && (s1[i] || s2[i]))
	{
		t = (unsigned char)s1[i] - (unsigned char)s2[i];
		if (t != 0)
			return (t);
		i++;
	}
	return (t);
}
