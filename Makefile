NAME = libftprintf.a
LIBFT = libft

SRCDIR = ./src/
OBJ_PATH = ./bin/
CC = cc
CFLAGS = -Wall -Wextra -Werror
HEADERS = libft.h ft_printf.h
SOURCES = ft_printf.c

all: $(NAME)

$(NAME): $(OBJECTS)
	@make -C $(LIBFT)
	@cp $(LIBFT)/libft.a .
	@mv libft.a $(NAME)
	ar rcs $(NAME) $(OBJECTS)

OBJECTS = $(addprefix $(OBJ_PATH), $(SOURCES:%.c=%.o))

$(OBJ_PATH)%.o: $(SRCDIR)%.c $(HEADERS)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@
	

clean: 
	rm -rf $(OBJ_PATH)
	@make clean -C $(LIBFT)

fclean: clean
	@rm -f $(NAME)
	@rm -f $(LIBFT)/libft.a

re: fclean all

.PHONY: all clean fclean re
