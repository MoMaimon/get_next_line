/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabd-elh <mabd-elh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 17:44:44 by mabd-elh          #+#    #+#             */
/*   Updated: 2026/10/03 22:16:13 by mabd-elh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char) c)
			return ((char *) & (s[i]));
		i++;
	}
	if (c == 0)
		return ((char *) & (s[i]));
	return (0);
}

void	handle_remain(char *buffer)
{
}

char	*get_next_line(int fd)
{
	char	*buffer;
	char	*new_line;
	char	*line;

	// static char	*remain;
	buffer = malloc(BUFFER_SIZE * sizeof(char));
	// printf("BUFFER_SIZE = %i\n", BUFFER_SIZE);
	if (!buffer)
		return (NULL);
	new_line = NULL;
	line = NULL;
	read(fd, buffer, BUFFER_SIZE);
	while (!new_line && buffer)
	{
		line = ft_strjoin(line, buffer);
		read(fd, buffer, BUFFER_SIZE);
		new_line = ft_strchr(buffer, '\n');
	}
	free(buffer);
	return (line);
}
