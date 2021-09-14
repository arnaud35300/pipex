# [ VARIABLES ] #

NAME		=	pipex
RM			= 	rm -rf
MAKE		= 	make
LIBFT		= 	./libft

# [ COMPILATION VARIABLES ] #

CC				=	gcc
CFLAGS			=	#-Wall -Wextra -Werror
LIBFT_INC		=	-I./libft -I./libft/char -I./libft/file -I./libft/int -I./libft/lst -I./libft/mem -I./libft/print -I./libft/str
PROG_INC		=
# [ SRCS ]

SRCS		=	main.c\

# [ OBJECTS ] #

OBJ			=	./objs
OBJS		=	$(addprefix $(OBJ)/, $(SRCS:.c=.o))

# [ PATH ] #

VPATH		=	includes:srcs:libft:

# [ RULES ] #

all:		$(NAME)

$(NAME):	$(LIBFT) $(OBJ) $(OBJS)
			$(CC) $(CFLAGS) -I./includes -I./libft $(PROG_INC) -o $(NAME) $(OBJS) $(LIBFT)/libft.a

$(OBJ):
			@mkdir -p $(OBJ)

$(LIBFT):
			@$(MAKE) bonus -C $(LIBFT)

$(OBJ)/%.o: %.c
			$(CC) $(CFLAGS) -I./includes $(LIBFT_INC) $(PROG_INC) -c $< -o $@
clean:
			@$(RM) $(OBJ)
			@$(MAKE) clean -C $(LIBFT)

fclean:		clean
			@$(RM) $(NAME) 2>/dev/null
			@$(MAKE) fclean -C $(LIBFT)

re:			fclean all

.PHONY:		all libft clean re fclean

