# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: albernar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/16 17:32:26 by albernar          #+#    #+#              #
#    Updated: 2024/10/16 17:33:17 by albernar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# VARIABLES
CC = cc
FLAGS = -Wall -Wextra -Werror

GREEN = \033[0;32m
YELLOW = \033[0;33m
RED = \033[0;31m
RESET = \033[0m

# FOLDERS
OBJ_DIR = .objs

# SOURCES
SRCS = \
main.c \
check_args.c \
ft_split.c \
get_next_line.c \
get_next_line_utils.c \
manage_args.c \
push_swap_utils.c \
push.c \
revrotate.c \
rotate.c \
sort.c \
sort_utils.c \
sort_score_utils.c \
stack.c \
swap.c \
individual_sort.c

SRCS_BONUS = \
individual_sort.c \
check_args.c \
main_bonus.c \
ft_split.c \
get_next_line.c \
get_next_line_utils.c \
sort_score_utils.c \
manage_args.c \
push_swap_utils.c \
push_swap_bonus.c \
push.c \
revrotate.c \
rotate.c \
sort.c \
swap.c \
sort_utils.c \
stack.c

# OBJECTS
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
BONUS_OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS_BONUS:.c=.o))

# EXECUTABLES
NAME = push_swap
NAME_BONUS = checker

# RULES
all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(YELLOW)Creating $(NAME)...$(RESET)"
	@$(CC) $(FLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)$(NAME) created successfully!$(RESET)"

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(BONUS_OBJS)
	@echo "$(YELLOW)Creating $(NAME_BONUS)...$(RESET)"
	@$(CC) $(FLAGS) $(BONUS_OBJS) -o $(NAME_BONUS)
	@echo "$(GREEN)$(NAME_BONUS) created successfully!$(RESET)"
	
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	@echo "$(YELLOW)Compiling $<...$(RESET)"
	@$(CC) $(FLAGS) -I./ -o $@ -c $<
	
%.o: %.c
	@echo "$(YELLOW)Compiling $<...$(RESET)"
	$(CC) $(FLAGS) -I./ -o $@ -c $<
	
clean:
	@echo "$(RED)Cleaning object files...$(RESET)"
	@rm -rf $(OBJ_DIR)
	
fclean: clean
	@echo "$(RED)Cleaning executables...$(RESET)"
	@rm -f $(NAME) $(NAME_BONUS)
	
re: fclean all

.PHONY: all clean fclean bonus re
