# [ VARIABLES ] #

NAME		=	pipex
RM			= 	rm -rf
MAKE		= 	make
LIBFT		= 	./libft

# [ COMPILATION VARIABLES ] #

CC				=	gcc -Wall -Wextra -Werror 
CFLAGS			=	#-Wall -Wextra -Werror
LIBFT_INC		=	-I./libft -I./libft/char -I./libft/file -I./libft/int -I./libft/lst -I./libft/mem -I./libft/print -I./libft/str
PROG_INC		=
# [ SRCS ]

SRCS		=	main.c\
				pipex.c\
				free.c\
				struct.c\
				cmd.c\
				error.c\

# [ OBJECTS ] #

OBJ			=	./objs
OBJS		=	$(addprefix $(OBJ)/, $(SRCS:.c=.o))

# [ PATH ] #

VPATH		=	includes:srcs:libft:

# [ RULES ] #

all:		$(NAME)

$(NAME):	$(OBJS)
			$(MAKE) bonus -s -C $(LIBFT)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -I./includes $(LIBFT_INC) $(PROG_INC) $(LIBFT)/libft.a

$(OBJ):
			mkdir -p $(OBJ)

$(OBJS):	| $(OBJ)

$(OBJ)/%.o: %.c
			$(CC) $(CFLAGS) -c $< -o $@ -I./includes $(LIBFT_INC) $(PROG_INC)
clean:
			$(RM) $(OBJ)
			$(MAKE) clean -C $(LIBFT)

fclean:		clean
			@$(RM) $(NAME) 2>/dev/null
			@$(MAKE) fclean -C $(LIBFT)

re:			fclean all

.PHONY:		all libft clean re fclean

