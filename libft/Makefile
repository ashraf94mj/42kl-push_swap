SRCS	=	ft_isdigit.c	ft_atoi.c	ft_strlen.c		ft_split.c						\
			ft_putchar_fd.c ft_putstr_fd.c	ft_putendl_fd.c	ft_putnbr_fd.c	\
			ft_lstnew.c		ft_lstadd_front.c	ft_lstsize.c				\
			ft_lstlast.c	ft_lstadd_back.c	ft_lstdelone.c			\
			ft_lstclear.c	

OBJS	=	$(SRCS:.c=.o)

NAME 	=	libft.a

CC 		=	gcc

CFLAGS 	=	-Wall -Wextra -Werror

RM		=	rm -f

all		:	$(NAME)

$(NAME)	:	$(OBJS)
			@ar rcs $(NAME) $(OBJS)
			@ranlib $(NAME)

%.o 	:	%.c
			@$(CC) $(CFLAGS) -c $< -o $@  

clean	:
			@$(RM) $(OBJS) 

fclean	:	clean
			@$(RM) $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re 
