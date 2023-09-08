NAME = libftprintf.a
LIBFT = ./libft

SRCDIR = ./src/
INCDIR = ./includes/
OBJ_PATH = ./bin/
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SOURCES = ft_printf.c ft_printf_utils.c ft_puthex.c ft_putptr.c ft_putsig.c ft_putnbr_base.c
#EXEC = test.c
#EXECUTABLE = test_executable

OBJECTS = $(addprefix $(OBJ_PATH), $(SOURCES:%.c=%.o))

all: libft $(OBJ_PATH) $(NAME)

$(NAME): $(OBJECTS)

libft:
	@make -C $(LIBFT) --no-print-directory
	@cp $(LIBFT)/libft.a $(NAME)

$(OBJ_PATH)%.o: $(SRCDIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCDIR)
	@ar rcs $(NAME) $?
	
$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)

bonus: all

clean: 
	rm -rf $(OBJ_PATH)
	@make clean -C $(LIBFT)

fclean: clean
	@rm -f $(NAME)
	@rm -f $(LIBFT)/libft.a
#@rm -f $(EXECUTABLE)

re: fclean
	@make --no-print-directory

.PHONY: all clean fclean re libft bonus

#run: all
#	$(CC) -w -o $(EXECUTABLE) $(EXEC) -I $(INCDIR) -L . -lftprintf -L $(LIBFT) -lft
#	./$(EXECUTABLE)