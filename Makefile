# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/30 23:11:49 by dgoremyk          #+#    #+#              #
#    Updated: 2022/06/20 13:57:58 by dgoremyk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# this option will define the buffer size for read():
CC = gcc -D BUFFER_SIZE=n
CFLAGS = -Wall -Werror -Wextra
# code will be compiled with command:
# cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c

