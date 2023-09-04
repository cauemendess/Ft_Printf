NAME = libftprintf.a
LIBFT = ./libft

SRCDIR = ./src/
INCDIR = ./includes/
OBJ_PATH = ./bin/
CC = cc
CFLAGS = -Wall -Wextra -Werror
SOURCES = ft_printf.c ft_printf_utils.c

OBJECTS = $(addprefix $(OBJ_PATH), $(SOURCES:%.c=%.o))

all: libft $(OBJ_PATH) $(NAME)

$(NAME): $(OBJECTS)
	@ar rcs $(NAME) $?

libft:
	@make -C $(LIBFT) --no-print-directory
	@cp $(LIBFT)/libft.a $(NAME)

$(OBJ_PATH)%.o: $(SRCDIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCDIR)
	
$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)

clean: 
	rm -rf $(OBJ_PATH)
	@make clean -C $(LIBFT)

fclean: clean
	@rm -f $(NAME)
	@rm -f $(LIBFT)/libft.a

remake:
	

re: fclean all

.PHONY: all clean fclean re libft
