NAME	=	push_swap
SRC		=	main.c		validation.c						\
			ops_s.c		ops_p.c 							\
			ops_r.c		ops_rr.c							\
			utils.c											\
			push_swap.c			push_swap_small.c			\
			push_swap_big.c		utils_big.c					\
			optimize_moves.c	rotate_big.c

OBJ		=	$(SRC:.c=.o)

INCLUDE	=	-Ilibft		
LIBRARY	=	-Llibft -lft


CC		=	gcc
CFLAGS	=	 -fsanitize=address  -Wall -Werror -Wextra  
			
RM		=	rm -rf

all		: $(NAME)

$(NAME)	: $(OBJ) lib
		@$(CC) $(CFLAGS) -o $@ $(OBJ)  $(LIBRARY) 
		
%.o	: %.c
		@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE) 

lib		:
		@make -C libft
		@make   -C libft

clean	:	
		@$(RM) $(NAME)	
		@make clean -C libft

fclean	:	clean
		@$(RM) $(OBJ)
		@make fclean -C libft

re		: fclean all

.phony	: all clean fclean re lib
