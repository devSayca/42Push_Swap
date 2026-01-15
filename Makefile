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

# --- PROJECT ---
NAME		= 	push_swap
BONUS_NAME	= 	checker
INCLUDES	=	-I include

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror $(INCLUDES)

# --- SOURCES ---
SRCS		=	src/main.c \
				<><> TO FILL <><>

BONUS_SRCS	=	<><> TO FILL <><>

OBJS		=	$(SRCS:.c=.o)
BONUS_OBJS	=	$(BONUS_SRCS:.c=.o)

# --- RULES --- | @jferone to @all : Please don't touch this except for bonus
all:	$(NAME)

$(NAME):	$(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

bonus:	$(BONUS_NAME)

$(BONUS_NAME):	$(OBJS) $(BONUS_OBJS)
			$(CC) $(CFLAGS) $(OBJS) $(BONUS_OBJS) -o $(BONUS_NAME)

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re bonus