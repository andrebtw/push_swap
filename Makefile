# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/30 16:58:58 by anrodri2          #+#    #+#              #
#    Updated: 2023/02/14 17:34:32 by anrodri2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#### SYSTEM ####
.PHONY: $(NAME) all clean fclean re
CC = gcc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra 

#### DIRECTORIES ####
SRC_DIR = src

#### SOURCE FILES ####
SRCS =	$(SRC_DIR)/main.c \
		$(SRC_DIR)/errors/error_printing.c \
		$(SRC_DIR)/errors/errors.c \
		$(SRC_DIR)/parsing/parsing.c \
		$(SRC_DIR)/linked_lists/linked_list_utils1.c \
		$(SRC_DIR)/linked_lists/linked_list_utils2.c \
		$(SRC_DIR)/operations/swap.c \
		$(SRC_DIR)/operations/push.c \
		$(SRC_DIR)/operations/rotate.c \
		$(SRC_DIR)/operations/reverse_rotate.c \
		$(SRC_DIR)/exec/exec.c \
		$(SRC_DIR)/exec/list_utils1.c \
		$(SRC_DIR)/exec/list_utils2.c \
		$(SRC_DIR)/exec/two_.c \
		$(SRC_DIR)/exec/three_.c \
		$(SRC_DIR)/exec/four_.c \
		$(SRC_DIR)/exec/five_.c \
		$(SRC_DIR)/exec/five_2.c \
		$(SRC_DIR)/exec/radix.c \
		$(SRC_DIR)/lib/ft_putstr.c \
		$(SRC_DIR)/lib/ft_strlen.c \
		$(SRC_DIR)/lib/ft_isdigit.c \
		$(SRC_DIR)/lib/ft_tablen.c \
		$(SRC_DIR)/lib/ft_atoi.c \
		$(SRC_DIR)/lib/ft_atoi_long.c \

OBJS = $(SRCS:.c=.o)

HEADER = $(SRC_DIR)/header.h

### FINAL COMPILATION FILE ###
NAME = push_swap

#### RULES ####
$(NAME):	$(OBJS) $(HEADER)
			$(CC) $(CFLAGS) $(MLXFLAGS) $(OBJS) -o $(NAME) -g3

%.o: %.c	$(HEADER) Makefile
			$(CC) $(CFLAGS) -c $< -o $@ -g3

all:		$(NAME)

clean:
			$(RM) $(OBJS)

fclean:
			$(RM) $(OBJS) $(NAME)

re:	fclean $(NAME)
