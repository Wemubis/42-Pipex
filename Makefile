# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/07 12:34:07 by mle-boud          #+#    #+#              #
#    Updated: 2023/01/07 12:34:07 by mle-boud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

HEADER = pipex.h

################ SRCS ################
SRCS = main.c pipex.c \
		check_args.c left_right_pipe.c \

################ OBJS ################
OBJS = $(patsubst %.c,%.o,$(SRCS))

################ PHONY ################
.PHONY: all clean fclean re

################ RULES ################
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -I. -c $< -o $@ libft/libft.a

clean:
	make -C ./libft/ clean
	$(RM) $(OBJS)

fclean: clean
	make -C ./libft/ fclean
	$(RM) $(NAME)

re: fclean all
