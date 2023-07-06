# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dinoguei <dinoguei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/10 13:11:14 by dinoguei          #+#    #+#              #
#    Updated: 2023/05/22 18:08:11 by dinoguei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = main.c \
	error.c \
	operations/inserts.c \
	operations/op_stack_a.c \
	operations/op_stack_b.c \
	operations/op_both.c \
	sort_three.c \
	sort_two.c \
	algorithm/main_algorithm.c \
	algorithm/algorithm.c \
	algorithm/functions.c \
	get_n_ops/get_n_op_a.c \
	get_n_ops/get_n_op_b.c \
	get_n_ops/count_ops_a.c \
	get_n_ops/count_ops_b.c \
	get_number.c \
	put_top_a.c \
	put_top_b.c \
	help.c \
	get_closer_a.c \
	get_closer_b.c \
	sorted.c

OBJS = $(SRC:.c=.o)

LIBFTDIR = ./libft
LIBFT = ./libft/libft.a

CC = cc 
CFLAGS = -Wall -Wextra -Werror -g
AR = ar rc
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) --no-print-directory -C $(LIBFTDIR)
	$(CC) $(CFLAGS) $(SRC) $(LIBFT) -o $(NAME)

clean:
	$(RM) $(OBJS)
	$(MAKE) clean --no-print-directory -C  $(LIBFTDIR)

fclean: clean
	$(RM) $(NAME)
	$(MAKE) fclean --no-print-directory -C $(LIBFTDIR)

re: fclean all
