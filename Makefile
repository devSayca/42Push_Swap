# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jferone <jferone@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/15 21:53:51 by jferone           #+#    #+#              #
#    Updated: 2026/01/15 21:53:51 by jferone          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = push_swap
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -I./include

SRC_DIR     = src
OBJ_DIR     = obj

# --- SOURCES (in separated responsabilities) --- #
SRC_MAIN    = main.c

SRC_MGR     = managers/initialization.c \
              managers/checks.c \
              managers/flags.c \
              managers/metrics.c \
              managers/strategy.c \
              managers/benchmark.c

SRC_ALGO    = algorithms/algo_simple.c \
              algorithms/algo_medium.c \
              algorithms/algo_complex.c

SRC_OPS     = operations/ops_push.c \
              operations/ops_swap.c \
              operations/ops_rotate.c \
              operations/ops_rrotate.c

SRC_UTILS   = utils/cleanup.c \
              utils/cost.c \
              utils/wrappers.c

# --- CONCATENATION ---
SRCS        = $(addprefix $(SRC_DIR)/, $(SRC_MAIN) $(SRC_MGR) $(SRC_ALGO) $(SRC_OPS) $(SRC_UTILS))
OBJS        = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

# --- RULES ---
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

# Redirects each objects in their folder, NOT in the root file.
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re