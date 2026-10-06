/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabd-elh <mabd-elh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 17:44:44 by mabd-elh          #+#    #+#             */
/*   Updated: 2026/10/06 22:09:19 by mabd-elh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	handle_remain(char **line, char **buffer, ssize_t bytes)
{
	char	*nl;

	nl = ft_strchr(*buffer, '\n');
	if (nl)
		return (sep_buffer(buffer, line, nl));
	if (bytes < BUFFER_SIZE && bytes)
	{
		*line = ft_strjoin(*line, *buffer, bytes);
		if (!line)
			return (0);
		(*buffer)[0] = '\0';
		return (1);
	}
	else
	{
		*line = ft_strjoin(*line, *buffer, ft_strlen(*buffer));
		if (!line)
			return (0);
		*buffer[0] = '\0';
		return (-1);
	}
}

int	get_until_new_line(int fd, char **buffer, char **line)
{
	ssize_t	bytes;

	bytes = read(fd, *buffer, BUFFER_SIZE);
	if (bytes < 0)
		return (0);
	(*buffer)[bytes] = '\0';
	while (bytes && !ft_strchr(*buffer, '\n'))
	{
		(*buffer)[bytes] = '\0';
		*line = ft_strjoin(*line, *buffer, ft_strlen(*buffer));
		if (!*line)
			return (0);
		bytes = read(fd, *buffer, BUFFER_SIZE);
	}
	(*buffer)[bytes] = '\0';
	if (**buffer)
	{
		if (!handle_remain(line, buffer, bytes))
			return (0);
	}
	if (!bytes && !*line)
		return (0);
	return (1);
}

char	*free_all(char **buffer, char *line)
{
	free(*buffer);
	*buffer = NULL;
	free(line);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*buffer[2048];
	char		*line;
	int			temp;

	line = NULL;
	if (!buffer[fd])
	{
		buffer[fd] = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!buffer[fd])
			return (NULL);
		buffer[fd][0] = '\0';
	}
	if (buffer[fd][0])
	{
		temp = handle_remain(&line, &buffer[fd], 0);
		if (!temp)
			return (NULL);
		else if (temp == 1)
			return (line);
	}
	if (!get_until_new_line(fd, &buffer[fd], &line))
		return (free_all(&buffer[fd], line));
	return (line);
}
