NAME = libftprintf.a
LIBFT = ./libft

SRCDIR = ./src/
INCDIR = ./includes/
OBJ_PATH = ./bin/
CC = cc
CFLAGS = -Wall -Wextra -Werror
SOURCES = ft_printf.c ft_printf_utils.c ft_puthex.c ft_putnbr_base.c ft_putptr.c ft_putsig.c
EXEC = test.c
EXECUTABLE = test_executable

OBJECTS = $(addprefix $(OBJ_PATH), $(SOURCES:%.c=%.o))

all: libft $(OBJ_PATH) $(NAME)


$(OBJ_PATH)%.o: $(SRCDIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCDIR)

$(NAME): $(OBJECTS)
	@ar rcs $(NAME) $?

libft:
	@make -C $(LIBFT) --no-print-directory
	@cp $(LIBFT)/libft.a $(NAME)
	
$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)

run: all
	$(CC) -w -o $(EXECUTABLE) $(EXEC) -I $(INCDIR) -L . -lftprintf -L $(LIBFT) -lft
	./$(EXECUTABLE)

clean: 
	rm -rf $(OBJ_PATH)
	@make clean -C $(LIBFT)

fclean: clean
	@rm -f $(NAME)
	@rm -f $(LIBFT)/libft.a
	@rm -f $(EXECUTABLE)


bonus: all

rebonus: fclean bonus

re: fclean all

.PHONY: all clean fclean re libft