/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   get_next_line.c                                   :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: mabd-elh <mabd-elh@student.42amman.com>   #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/03 17:44:44 by mabd-elh         #+#    #+#              */
/*   Updated: 2026/10/04 14:03:07 by mabd-elh        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int handle_remain(char **line, char **remain)
{
	char *nl;
	int temp;

	nl = ft_strchr(*remain, '\n');
	if (nl)
	{
		temp = (long)nl - (long)*remain + 1;
		*line = ft_strjoin(*line, ft_substr(*remain, 0, temp));
		ft_memcpy(*remain, &nl[1], ft_strlen(nl));
		return (1);
	}
	else
	{
		*line = ft_strjoin(*line, *remain);
		*remain[0] = '\0';
		return (0);
	}
}

int get_until_new_line(int fd, char **remain, char **line)
{
	char *buffer;
	char *nl;
	ssize_t bytes;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	nl = NULL;
	if (!buffer)
		return (0);
	while ((bytes = read(fd, buffer, BUFFER_SIZE)))
	{
		buffer[BUFFER_SIZE] = '\0';
		nl = ft_strchr(buffer, '\n');
		if (nl)
			break;
		*line = ft_strjoin(*line, buffer);
	}
	if (nl)
	{
		*remain = ft_strjoin(*remain, ft_substr(buffer, 0, bytes));
		handle_remain(line, remain);
	}
	if (!buffer)
		return (0);
	return (1);
}

char *get_next_line(int fd)
{
	static char *remain;
	char *line;

	line = NULL;
	if (!remain)
	{
		remain = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!remain)
			return (NULL);
	}
	if (remain[0] && handle_remain(&line, &remain))
		return (line);
	else if (!get_until_new_line(fd, &remain, &line))
		return (NULL);
	return (line);
}
