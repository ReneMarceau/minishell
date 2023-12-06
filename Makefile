# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: Invalid date        by                   #+#    #+#              #
#    Updated: 2023/12/06 16:27:59 by rmarceau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -------------------------------------#
#           VARIABLES                  #
# -------------------------------------#

# Project Name
NAME = minishell

# Compiler and Flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g #-fsanitize=address

# Directories
SRC_DIR = src
OBJ_DIR = obj
INC_DIR = includes

# SRC Folder Subdirectories
EXEC_DIR = $(SRC_DIR)/executor
BUILTIN_DIR = $(SRC_DIR)/builtins
SIG_DIR = $(SRC_DIR)/signal
PARS_DIR = $(SRC_DIR)/parser
EXP_DIR = $(SRC_DIR)/expand
GAR_DIR = $(SRC_DIR)/garbage
TOKEN_DIR = $(SRC_DIR)/tokenizer
ENV_DIR = $(SRC_DIR)/env
ERROR_DIR = $(SRC_DIR)/error
UTILS_DIR = $(SRC_DIR)/utils

# External Libraries Directories
LIBFT_DIR = libs/libft
LIBRLINE_DIR = $(INC_DIR)/readline
LIBRLINE = readline-8.2
LIBFT_INC = $(LIBFT_DIR)/inc
LIBRD_INC = $(LIBRLINE_DIR)/inc

# Source and Object Files

SRCS := $(wildcard $(ERROR_DIR)/*.c)	\
		$(wildcard $(ENV_DIR)/*.c)		\
		$(wildcard $(UTILS_DIR)/*.c)	\
		$(wildcard $(TOKEN_DIR)/*.c)	\
		$(wildcard $(PARS_DIR)/*.c)		\
		$(wildcard $(EXP_DIR)/*.c)		\
		$(wildcard $(GAR_DIR)/*.c)		\
		$(wildcard $(BUILTIN_DIR)/*.c)	\
		$(wildcard $(EXEC_DIR)/*.c)		\
		$(wildcard $(SIG_DIR)/*.c)		\
		$(wildcard $(SRC_DIR)/*.c)
OBJS := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

# Libraries
LIBFT = $(LIBFT_DIR)/bin/libft.a
LIBRD = $(LIBRLINE_DIR)/bin/libreadline.a $(LIBRLINE_DIR)/bin/libhistory.a
LIBS = $(LIBFT) -lreadline -lcurses $(LIBRD)

# Colors for terminal prints
BLACK    = \033[30;1m
RED      = \033[0;31m
GREEN    = \033[32;1m
YELLOW   = \033[33;1m
BLUE     = \033[34;1m
PURPLE   = \033[35;1m
CYAN     = \033[36;1m
WHITE    = \033[37;1m
GRAY     = \033[90;1m
MAGENTA  = \033[0;95m
BOLD     = \033[1m
RESET    = \033[0m

# -------------------------------------#
#           COMPILATION RULES          #
# -------------------------------------#

# Rule to build everything
all: $(NAME)

# Rule to compile each source file into an object file
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@echo "$(YELLOW)Compiling $(BLUE)$< $(YELLOW)to $(CYAN)$@$(RESET)"
	@$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

# Rule to link the object files and libraries into the final binary
$(NAME): $(LIBRD) $(LIBFT) $(OBJS)
	@echo "$(YELLOW)Linking objects to create binary $(GREEN)$(NAME)$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBS)
	@echo "$(GREEN)Compilation successful!$(RESET)"

# Rules to compile the external libraries
$(LIBFT):
	@echo "$(YELLOW)Compiling $(BLUE)libft$(RESET)"
	@make -C $(LIBFT_DIR)

$(LIBRD):
	@echo "$(YELLOW)Compiling $(BLUE)readline$(RESET)"
	curl -O ftp://ftp.cwru.edu/pub/bash/$(LIBRLINE).tar.gz
	@echo "$(YELLOW)Extracting $(BLUE)readline$(RESET)"
	tar -zxvf $(LIBRLINE).tar.gz
	@rm -rf $(LIBRLINE).tar.gz
	@cd $(LIBRLINE) && bash configure && make
	@mkdir -p $(LIBRLINE_DIR)/bin
	@mv ./$(LIBRLINE)/*.h $(LIBRLINE_DIR)
	@mv ./$(LIBRLINE)/*.a $(LIBRLINE_DIR)/bin
	@rm -rf $(LIBRLINE)

# -------------------------------------#
#           UTILITY RULES			   #
# -------------------------------------#
clean:
	@if [ -d "$(OBJ_DIR)" ]; then \
		printf "$(RED)Cleaning up $(BLUE)object files$(RED) in $(YELLOW)minishell...$(RESET)\n"; \
		rm -rf $(OBJ_DIR); \
	fi
	@make -C $(LIBFT_DIR) clean

fclean: clean
	@if [ -f "$(NAME)" ]; then \
		echo "$(YELLOW)Removing binary $(RED)$(NAME)$(RESET)"; \
		rm -rf $(NAME); \
	fi
	@make -C $(LIBFT_DIR) fclean

re: fclean all

# Other utility rules
run: all
	@echo "$(YELLOW)Running $(GREEN)$(NAME)$(RESET)"
	@./$(NAME)

norminette:
	@echo "$(YELLOW)Checking norminette...$(RESET)"
	@norminette $(SRC_DIR) $(INC_DIR)

test: all
	@echo "$(YELLOW)Running tests...$(RESET)"
	@bash tests/test.sh

leaks: all
	@echo "$(YELLOW)Running leaks...$(RESET)"
	@valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes --track-origins=yes --suppressions=./$(NAME).sup ./$(NAME)

# -------------------------------------#
#           .PHONY RULES               #
# -------------------------------------#
.PHONY: all clean fclean test run norminette leaks re 