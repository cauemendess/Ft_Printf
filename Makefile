NAME = libftprintf.a
SRCDIR = ./Mandatory/src/
INCDIR = ./Mandatory/includes/
BONUS_SRCDIR = ./Bonus/src/
BONUS_INCDIR = ./Bonus/includes/
OBJ_PATH = ./bin/
CFLAGS = -Wall -Wextra -Werror

SOURCES = ft_printf.c ft_printf_utils.c ft_putnbr_base.c ft_putptr.c
BONUS_SOURCES = ft_printf_bonus.c ft_printf_utils_bonus.c ft_puthex_bonus.c ft_putnbr_base_bonus.c ft_putptr_bonus.c ft_putsig_bonus.c

GREEN = \033[1;32m
RED = \033[1;31m
RESET = \033[0m

OBJECTS = $(addprefix $(OBJ_PATH), $(SOURCES:%.c=%.o))
BONUS_OBJECTS = $(addprefix $(OBJ_PATH), $(BONUS_SOURCES:%.c=%.o))

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

bonus:
	@make OBJECTS="$(BONUS_OBJECTS)" \
	SRCDIR="$(BONUS_SRCDIR)" \
	INCDIR="$(BONUS_INCDIR)" --no-print-directory

rebonus: fclean bonus

re: fclean all

.PHONY: all clean fclean re bonus
