/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 22:44:10 by dgoremyk          #+#    #+#             */
/*   Updated: 2022/07/17 11:46:57 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE BUFSIZ
# endif

char		*ft_newline_found(char *s);
size_t		ft_strlen(const char *s);
char		*ft_strjoin(char *s1, char *s2);

char		*reader(int fd, char *hold);
char		*cleaner(char *hold);
char		*get_next_line(int fd);

#endif