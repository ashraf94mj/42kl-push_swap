NAME	=	push_swap
SRC		=	main.c		validation.c	s_operation.c	p_operation.c \
			r_operation.c	rr_operation.c				\
			push_swap.c		push_swap_small.c			\
			utils.c
OBJ		=	$(SRC:.c=.o)

INCLUDE	=	-Ilibft		
LIBRARY	=	-Llibft -lft


CC		=	gcc
CFLAGS	=	 -fsanitize=address  
# -Wall -Werror -Wextra  
			
RM		=	rm -rf

all		: $(NAME)

$(NAME)	: $(OBJ) lib
		@$(CC) $(CFLAGS) -o $@ $(OBJ)  $(LIBRARY) 
		
%.o	: %.c
		@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE) 

lib		:
		@make -C libft
		@make  bonus -C libft

clean	:	
		@$(RM) $(NAME)	
		@make clean -C libft

fclean	:	clean
		@$(RM) $(OBJ)
# @make fclean -C libft

re		: fclean all

.phony	: all clean fclean re lib
