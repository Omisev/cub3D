/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:12:46 by raveriss          #+#    #+#             */
/*   Updated: 2024/02/28 17:12:49 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H

# include <fcntl.h>
# include "get_next_line.h"
# include "ft_printf.h"

int		ft_strncmp(char *s1, char *s2, int n);
int		ft_is_alpha(char c);
int		ft_strstr(char *str, char *to_find);
char	**ft_split(char const *s, char c);
int		ft_atoi(const char *nptr);

#endif