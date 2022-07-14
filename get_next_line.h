/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 22:44:10 by dgoremyk          #+#    #+#             */
/*   Updated: 2022/07/13 19:26:02 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdio.h> //printf
#include <unistd.h> //close read write
#include <fcntl.h> //open
#include <stdlib.h> //malloc

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
//# define BUFFER_SIZE BUFSIZ
#endif

char	*ft_nl(char *s);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char *s2);

char	*ft_substr(char const *s, unsigned int start, size_t len);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strchr(const char *s, int c);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_strdup(const char *s1);

char	*reader(int fd, char *hold);
char	*cleaner(char *hold);
static char	*garbage_collector(char *hold);
char	*get_next_line(int fd);

#endif