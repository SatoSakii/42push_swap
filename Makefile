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
instructions/swap.c \
instructions/rotate.c \
instructions/revrotate.c \
instructions/push.c \
sort/individual_sort.c \
sort/sort_score_utils.c \
sort/sort_utils.c \
sort/sort.c \
utils/check_args.c \
utils/ft_split.c \
utils/manage_args.c \
utils/push_swap_utils.c \
utils/stack.c

SRCS_BONUS = \
main_bonus.c \
instructions/swap.c \
instructions/rotate.c \
instructions/revrotate.c \
instructions/push.c \
sort/sort_utils.c \
utils/check_args.c \
utils/ft_split.c \
utils/manage_args.c \
utils/push_swap_utils.c \
utils/stack.c \
utils/get_next_line_bonus.c \
utils/get_next_line_utils_bonus.c \
utils/push_swap_bonus.c

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
	
$(OBJ_DIR)/%.o: ./srcs/%.c
	@mkdir -p $(dir $@)
	@echo "$(YELLOW)Compiling $<...$(RESET)"
	@$(CC) $(FLAGS) -I./includes -o $@ -c $<
	
clean:
	@echo "$(RED)Cleaning object files...$(RESET)"
	@rm -rf $(OBJ_DIR)
	
fclean: clean
	@echo "$(RED)Cleaning executables...$(RESET)"
	@rm -f $(NAME) $(NAME_BONUS)
	
re: fclean all

.PHONY: all clean fclean bonus re
