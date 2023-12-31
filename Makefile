NAME = libftprintf.a
SRCDIR = ./src/
INCDIR = ./includes/
OBJ_PATH = ./bin/
CFLAGS = -Wall -Wextra -Werror


SOURCES = ft_printf.c ft_printf_utils.c ft_puthex.c ft_putnbr_base.c ft_putptr.c ft_putsig.c

GREEN = \033[1;32m
RED = \033[1;31m
RESET = \033[0m

OBJECTS = $(addprefix $(OBJ_PATH), $(SOURCES:%.c=%.o))


all: $(OBJ_PATH) $(NAME)

$(OBJ_PATH)%.o: $(SRCDIR)%.c
	@echo "$(GREEN)[Compiling...]$(RESET) $<"
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCDIR)

$(NAME): $(OBJECTS)
	@echo "$(GREEN)[Compiling Sucessful!]$(RESET)"
	@ar rcs $(NAME) $?

	
$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)

clean: 
	@rm -rf $(OBJ_PATH)
	@echo "$(RED)[Objects removed successfully!]$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)[$(NAME) removed successfully!]$(RESET)"


re: fclean all

.PHONY: all clean fclean re
