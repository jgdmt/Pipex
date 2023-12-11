SRCS			:=	main.c \
					parsing.c \
					utils.c \

SRCS_BON		:=	bonus/main_bonus.c \
					bonus/parsing_bonus.c \
					bonus/utils_bonus.c \

OBJS			:= $(SRCS:.c=.o)
OBJS_BON		:= $(SRCS_BON:.c=.o)

CC				:= gcc
RM				:= rm -f
CFLAGS			:= -I. -Wall -Wextra -Werror

NAME			:= pipex
NAME_BON		:= pipex_bonus

all:			$(NAME)

$(NAME):		$(OBJS)
				$(MAKE) -C ./libft
				$(CC) $(CFLAGS) -o $(NAME) $(OBJS) libft/libft.a

bonus:			$(NAME_BON)

$(NAME_BON):	$(OBJS_BON)
				$(MAKE) -C ./libft
				$(CC) $(CFLAGS) -o $(NAME_BON) $(OBJS_BON) libft/libft.a

clean:
				$(MAKE) clean -C ./libft
				$(RM) $(OBJS) $(OBJS_BON)

fclean:			clean
				$(MAKE) fclean -C ./libft
				$(RM) $(NAME) $(NAME_BON)

re:				fclean $(NAME)
	
.PHONY:			all clean fclean re bonus