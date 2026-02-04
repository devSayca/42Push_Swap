# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jferone <jferone@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/15 21:53:51 by jferone           #+#    #+#              #
#    Updated: 2026/02/04 11:55:22 by jferone          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = push_swap
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -I./include

NAME_BONUS	= checker
SRCS_BONUS	= bonus_checker.c $(filter-out main.c, $(SRCS))

# === SOURCES === # (Main, Managers, Algorithms, Operations, Utils)
SRCS	= main.c \
		mgr_initialization.c \
		mgr_checkers.c \
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

OBJS	= $(SRCS:.c=.o)

# === RULES === #
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_BONUS)
	$(CC) $(CFLAGS) $(OBJS_BONUS) -o $(NAME_BONUS)

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re