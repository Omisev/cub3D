/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:14:52 by raveriss          #+#    #+#             */
/*   Updated: 2024/02/28 17:14:55 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

char	*ft_free_gnl(char *str)
{
	free(str);
	return (NULL);
}

char	*ft_remove(char *stash)
{
	char	*line;
	int		i;

	i = 0;
	if (!stash || !stash[0])
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	line [i] = '\0';
	while (--i >= 0)
		line[i] = stash[i];
	return (line);
}

char	*ft_add(char *stash)
{
	char	*newstash;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!stash)
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\0')
	{
		free(stash);
		return (NULL);
	}
	newstash = malloc(sizeof(char) * (ft_strlen(stash) - i + 1));
	if (!newstash)
		return (NULL);
	while (stash[i])
		newstash[j++] = stash[++i];
	newstash[j++] = '\0';
	free(stash);
	return (newstash);
}

char	*read_line(int fd, char *save)
{
	char	*buffer;
	int		red;

	red = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (red > 0)
	{
		red = read(fd, buffer, BUFFER_SIZE);
		if (red == -1)
			return (ft_free_gnl(buffer));
		buffer[red] = '\0';
		save = ft_strjoin(save, buffer);
		if (!save)
		{
			free(buffer);
			return (ft_free_gnl(save));
		}
		if (ft_strrchr(save, '\n'))
			break ;
	}
	free (buffer);
	return (save);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_line(fd, stash);
	if (!stash)
		return (NULL);
	line = ft_remove(stash);
	stash = ft_add(stash);
	if (stash)
	{
		if (!stash[0])
		{
			free(stash);
			stash = NULL;
		}
	}
	return (line);
}

// int	main(void)
// {
// 	int	fd;
// 	int	i;
// 	char	*line;

// 	i = 0;
// 	fd = open("test.txt", O_RDONLY);
// 	while (i < 2)
// 	{
// 		line = get_next_line(fd);
// 		printf("%s", line);
// 		free(line);
// 		i++;
// 	}
// 	close(fd);
// }