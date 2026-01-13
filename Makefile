# --- PROJECT ---
NAME		= 	push_swap
BONUS_NAME	= 	checker
INCLUDES	=	-I include

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror $(INCLUDES)

# --- SOURCES ---
SRCS		=	src/main.c \
				

BONUS_SRCS	=	bonus/checker_main_bonus.c \
				bonus/checker_apply_bonus.c

OBJS		=	$(SRCS:.c=.o)
BONUS_OBJS	=	$(BONUS_SRCS:.c=.o)

# --- RULES --- | @jferone: Don't touch this except for bonus set-settings
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