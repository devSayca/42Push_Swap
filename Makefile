# --- PROJECT ---
NAME		= 	push_swap
BONUS_NAME	= 	checker
INCLUDES	=	-I include

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror $(INCLUDES)

# --- SOURCES ---
SRCS		=	src/main.c \
				src/error.c \
				src/parse/parse_args.c src/parse/atoi_checked.c src/parse/dedup.c \
				src/stack/stack_init.c src/stack/stack_utils.c \
				src/stack/stack_ops_swap.c src/stack/stack_ops_rot.c src/stack/stack_ops_small.c \
				src/algo/sort_dispatch.c src/algo/sort_small.c src/algo/sort_radix.c

BONUS_SRCS	=	bonus/checker_main_bonus.c \
				bonus/checker_apply_bonus.c

OBJS		=	$(SRCS:.c=.o)
BONUS_OBJS	=	$(BONUS_SRCS:.c=.o)

# --- RULES ---
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