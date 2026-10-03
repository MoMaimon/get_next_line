/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabd-elh <mabd-elh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 21:15:29 by mabd-elh          #+#    #+#             */
/*   Updated: 2026/10/03 21:52:36 by mabd-elh         ###   ########.fr       */
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

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	s1_len;
	size_t	s2_len;

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
	free(s1);
	return (str);
}

// char	**ft_cat(char *str1, char *str2, int buffer_size)
// {
// 	size_t	i;
// 	size_t	str1_len;
// 	size_t	str2_len;
// 	size_t	remain_len;

// 	str1_len = ft_strlen(str1);
// 	str2_len = ft_strlen(str2);
// 	remain_len = buffer_size -
// 	i = 0;
// 	while (str2[i])
// 	{
// 	}
// }
