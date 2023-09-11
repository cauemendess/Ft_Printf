NAME = libftprintf.a
SRCDIR = ./src/
INCDIR = ./includes/
OBJ_PATH = ./bin/
CC = cc
CFLAGS = -Wall -Wextra -Werror
SOURCES = ft_printf.c ft_printf_utils.c ft_puthex.c ft_putnbr_base.c ft_putptr.c ft_putsig.c
EXEC = test.c
EXECUTABLE = test_executable

GREEN = \033[1;32m
RED = \033[1;31m
RESET = \033[0m

OBJECTS = $(addprefix $(OBJ_PATH), $(SOURCES:%.c=%.o))

all: $(OBJ_PATH) $(NAME)
	@echo "$(GREEN)[Compiling Sucessful!]$(RESET) $<"

$(OBJ_PATH)%.o: $(SRCDIR)%.c
	@echo "$(GREEN)[Compiling...]$(RESET) $<"
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCDIR)

$(NAME): $(OBJECTS)
	@ar rcs $(NAME) $?

	
$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)

clean: 
	rm -rf $(OBJ_PATH)
	@echo "$(RED)[Objetos removidos com sucesso!]$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@rm -f $(EXECUTABLE)


bonus: all

rebonus: fclean bonus

re: fclean all

.PHONY: all clean fclean re

run: all
	$(CC) $(CFLAGS) -o $(EXECUTABLE) $(EXEC) -I $(INCDIR) -L . -lftprintf 
	./$(EXECUTABLE)