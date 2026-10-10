/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabd-elh <mabd-elh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 21:15:29 by mabd-elh          #+#    #+#             */
/*   Updated: 2026/10/10 20:52:45 by mabd-elh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *) dest)[i] = ((unsigned char *) src)[i];
		i++;
	}
	return (dest);
}

char	*ft_strjoin(char *s1, char const *s2, size_t len)
{
	char	*str;
	size_t	i;
	size_t	s1_len;

	i = 0;
	s1_len = ft_strlen(s1);
	str = malloc((s1_len + len + 1) * sizeof(char));
	if (!str)
	{
		free(s1);
		return (NULL);
	}
	while (i++ < s1_len)
		str[i - 1] = s1[i - 1];
	i = 0;
	while (i < len)
	{
		str[i + s1_len] = s2[i];
		i++;
	}
	str[i + s1_len] = '\0';
	free(s1);
	return (str);
}

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

int	sep_buffer(char **buffer, char **line, char *nl)
{
	long	len;

	len = (long) nl - (long)*buffer + 1;
	*line = ft_strjoin(*line, *buffer, len);
	if (!line)
		return (0);
	ft_memcpy(*buffer, &nl[1], ft_strlen(nl));
	return (1);
}
