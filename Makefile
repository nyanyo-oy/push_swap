NAME	=	push_swap

SRCS	=	main.c					\
			actions/ac_push.c		\
			actions/ac_r_rotate.c	\
			actions/ac_rotate.c		\
			actions/ac_swap.c		\
			ps_actions.c			\
			ps_helpers.c 			\
			ps_sorts.c				\
			ps_validators.c			\
			under_five_elements.c	\
			
OBJDIR	=	OBJS
OBJS	=	$(SRCS:%.c=$(OBJDIR)/%.o)

LIBFT_DIR	=	./libft
LIBFT_LIB	=	$(LIBFT_DIR)/libft.a

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror
RM		=	rm -rf

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_LIB)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_LIB) -o $(NAME)

$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR)
	
$(OBJDIR)/%.o: %.c push_swap.h
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I. -c $< -o $@
	
clean:
	$(RM) $(OBJDIR)
	$(MAKE) -C $(LIBFT_DIR) clean
	
fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean	

re: fclean all

.PHONY: all clean fclean re
	