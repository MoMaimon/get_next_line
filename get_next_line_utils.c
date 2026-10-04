/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   get_next_line_utils.c                             :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: mabd-elh <mabd-elh@student.42amman.com>   #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/03 21:15:29 by mabd-elh         #+#    #+#              */
/*   Updated: 2026/10/04 12:47:41 by mabd-elh        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t ft_strlen(const char *s)
{
	size_t i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

void *ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}

char *ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t i;
	char *str;
	size_t min_len;

	if (len < ft_strlen(&s[start]))
		min_len = len;
	else
		min_len = ft_strlen(&s[start]);
	i = 0;
	str = malloc((min_len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (i < min_len && s[i])
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}

char *ft_strjoin(char *s1, char const *s2)
{
	char *str;
	size_t i;
	size_t s1_len;
	size_t s2_len;

	i = 0;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str = malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (i < s1_len)
	{
		str[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < s2_len)
	{
		str[i + s1_len] = s2[i];
		i++;
	}
	str[i + s1_len] = '\0';
	return (str);
}

char *ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&(s[i]));
		i++;
	}
	if (c == 0)
		return ((char *)&(s[i]));
	return (0);
}
