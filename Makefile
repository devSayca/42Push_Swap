# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jferone <jferone@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/15 21:53:51 by jferone           #+#    #+#              #
#    Updated: 2026/02/05 16:13:17 by jferone          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = push_swap
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -I./include

NAME_BONUS	= checker

# === SOURCES & OBJECTS === #
SRCS	= main.c \
		mgr_initialization.c \
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
OBJS	= $(SRCS:.c=.o)

SRCS_BONUS	= bonus_checker.c $(filter-out main.c, $(SRCS))
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

# === RULES === #
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(NAME_BONUS): $(OBJS_BONUS)
	$(CC) $(CFLAGS) $(OBJS_BONUS) -o $(NAME_BONUS)

# Compiles mandatory part
m: $(NAME)

# Compiles bonus part
bonus: $(NAME_BONUS)

# Compiles both parts
all: $(NAME) $(NAME_BONUS)

# Cleaning options
clean:
	@rm -rf $(OBJS) $(OBJS_BONUS)

fclean: clean
	@rm -f $(NAME) $(NAME_BONUS)

re: fclean all

# Excludes "make file or command ?" conflicts possibilities
.PHONY: m bonus all clean fclean re