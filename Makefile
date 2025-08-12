NAME	=	push_swap


SRCS	=	main.c					\
			actions/ac_push.c		\
			actions/ac_r_rotate.c	\
			actions/ac_rotate.c		\
			actions/ac_swap.c		\
			ps_actions.c			\
			
OBJDIR	=	OBJS
OBJS	=	$(SRCS:%.c=$(OBJDIR)/%.o)

CC		=	cc

CFLAGS	=	-Wall -Wextra -Werror

LIBFT	=	libft-42/libft.a


all:		$(NAME)

$(NAME):	$(OBJS) $(LIBFT)
		$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
		make -C libft-42
	
$(OBJDIR)/%.o: %.c
		@mkdir -p $(dir $@)
		$(CC) $(CFLAGS) -I. -c $< -o $@
	
clean:
		rm -rf $(OBJDIR)
		make -C libft-42 clean
	
fclean:		clean
		rm -f $(NAME)
		make -C libft-42 fclean	

re:			fclean all

.PHONY:		all clean fclean re
	
		