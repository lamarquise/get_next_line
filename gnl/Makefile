# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erlazo <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/31 17:57:37 by erlazo            #+#    #+#              #
#    Updated: 2020/10/28 16:36:01 by ericlazo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	gnl

S		=	4

SRC		=	get_next_line.c \
			get_next_line_utils.c \
			main.c

SRC_B	=	get_next_line_bonus.c \
			get_next_line_utils_bonus.c \
			main.c

OBJ		=	$(SRC:.c=.o)

OBJ_B	=	$(SRC_B:.c=.o)

CC		=	gcc

CFLAGS	=	-Wall -Werror -Wextra


all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ -g

clean:
	rm -rf $(OBJ) $(OBJ_B)
fclean: clean
	rm -rf $(NAME)

re:	fclean all

bonus:	$(OBJ_B)
	$(CC) -D BUFFER_SIZE=$S $(CFLAGS) -o $@ $^


		
