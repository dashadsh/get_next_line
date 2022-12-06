/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 22:44:10 by dgoremyk          #+#    #+#             */
/*   Updated: 2022/12/06 18:42:12 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

/* library for printf*/
# include <stdio.h> 
/* library for close & write*/
# include <unistd.h>
/* library for open*/
# include <fcntl.h>
/* library for malloc*/
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE BUFSIZ
# endif

# ifndef FD_MAX
#  define FD_MAX 65536
# endif

char		*gnl_newline_found(char *s);
size_t		gnl_strlen(const char *s);
char		*gnl_strjoin(char *s1, char *s2);

char		*reader(int fd, char *hold);
char		*cleaner(char *hold);
char		*garbage_collector(char *hold);
char		*get_next_line(int fd);

#endif