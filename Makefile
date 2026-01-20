# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jferone <jferone@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/15 21:53:51 by jferone           #+#    #+#              #
#    Updated: 2026/01/20 18:32:59 by jferone          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = push_swap
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -I./include

# === SOURCES === # (Main, Managers, Algorithms, Operations, Utils)
SRC		= main.c \
		mgr_init.c \
		mgr_checks.c \
		mgr_flags.c \
		mgr_metrics.c \
		mgr_strategy.c \
		mgr_benchmark.c \
		algo_simple.c \
		algo_medium.c \
		algo_complex.c \
		ops_swap.c \
		ops_push.c \
		ops_rotate.c \
		ops_rrotate.c \
		utils_cleanup.c \
		utils_cost.c \
		utils_wrappers.c

OBJ		= 
# DON'T FORGET TO CHECK OBJS IMPLEMENTATION AND SOURCE TRANSFORMATION

# === RULES === #
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re