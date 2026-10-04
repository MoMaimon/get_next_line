/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   get_next_line.h                                   :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: mabd-elh <mabd-elh@student.42amman.com>   #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/03 17:34:06 by mabd-elh         #+#    #+#              */
/*   Updated: 2026/10/04 12:51:53 by mabd-elh        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
#include <unistd.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

#if BUFFER_SIZE <= 0
#undef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

char *get_next_line(int fd);
char *ft_strjoin(char *s1, char const *s2);
char *ft_substr(char const *s, unsigned int start, size_t len);
void *ft_memcpy(void *dest, const void *src, size_t n);
size_t ft_strlen(const char *s);
char *ft_strchr(const char *s, int c);

#endif
