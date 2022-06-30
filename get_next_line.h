/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 22:44:10 by dgoremyk          #+#    #+#             */
/*   Updated: 2022/06/30 14:51:39 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdio.h> //printf
#include <unistd.h> //close read write
#include <fcntl.h> //open
#include <stdlib.h> //malloc

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
//void	*ft_calloc(size_t count, size_t size);
char	*ft_strnew(size_t size);
char	*ft_strchr(const char *s, int c);

// #include <string.h> 
//NULL - this macro is the value of a null pointer constant
//size_t  - this is the unsigned integral type and 
//is the result of the sizeof keyword)
#endif