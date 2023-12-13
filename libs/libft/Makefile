# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/22 10:10:05 by rmarceau          #+#    #+#              #
#    Updated: 2023/12/11 11:35:53 by rmarceau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -------------------------------------#
#           VARIABLES                  #
# -------------------------------------#

# Compiler and Flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Output Binary
BIN_DIR = bin
BIN = libft.a
NAME = $(BIN_DIR)/$(BIN)

# Source Directories
SRC_DIR = src
SRC_CORE_DIR = $(SRC_DIR)/core
SRC_ADD_DIR = $(SRC_DIR)/add
SRC_BONUS_DIR = $(SRC_DIR)/bonus

# Object Directories
OBJ_DIR = obj
OBJ_CORE_DIR = $(OBJ_DIR)/core
OBJ_ADD_DIR = $(OBJ_DIR)/add
OBJ_BONUS_DIR = $(OBJ_DIR)/bonus

# Header File
HEADER = libft.h

# Source Files
SRC_CORE =	ft_atoi.c ft_bzero.c ft_calloc.c ft_putendl_fd.c ft_itoa.c \
		ft_putchar_fd.c ft_putstr_fd.c ft_memccpy.c ft_memchr.c \
		ft_memcmp.c ft_memcpy.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
		ft_isdigit.c ft_isprint.c ft_memmove.c ft_memset.c \
		ft_strchr.c ft_strdup.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c \
		ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strcmp.c ft_strnstr.c ft_strrchr.c \
		ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c ft_putnbr_fd.c
		
SRC_BONUS =	ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c \
		ft_lstiter.c ft_lstlast.c ft_lstsize.c ft_lstnew.c ft_lstmap.c \
		ft_lstget_at.c
		
SRC_ADD =	ft_putnbr_base_fd.c ft_putstrn_fd.c ft_putnchar_fd.c ft_isspace.c \
		ft_uitoa.c ft_nbrlen.c ft_strrncmp.c ft_countchar.c ft_strenlarge.c \
		ft_recursive_power.c ft_chartostr.c ft_sqrt.c ft_newvector.c \
		ft_euclideandistance.c ft_atoi2.c ft_free_matrix.c ft_dup_matrix.c \
		ft_strchr_i.c ft_putmatrix_fd.c ft_matrixlen.c ft_strchars_i.c \
		ft_between_chars.c ft_subsplit.c ft_extend_matrix.c ft_matrixtolst.c \
		ft_lsttomatrix.c ft_matrix_replace_in.c

# Object Files
OBJ_CORE = $(addprefix $(OBJ_CORE_DIR)/, $(SRC_CORE:.c=.o))
OBJ_BONUS = $(addprefix $(OBJ_BONUS_DIR)/, $(SRC_BONUS:.c=.o))
OBJ_ADD = $(addprefix $(OBJ_ADD_DIR)/, $(SRC_ADD:.c=.o))

# Progress Variables
SRC_COUNT_TOT := $(shell expr $(shell echo -n $(SRC_CORE) | wc -w) - \
					$(shell ls -l $(OBJ_CORE_DIR) 2>&1 | grep ".o" | wc -l) + 1)
SRC_COUNT := 0
SRC_PCT = $(shell expr 100 \* $(SRC_COUNT) / $(SRC_COUNT_TOT))

SRCB_COUNT_TOT := $(shell expr $(shell echo -n $(SRC_BONUS) | wc -w) - \
					$(shell ls -l $(OBJ_BONUS_DIR) 2>&1 | grep ".o" | wc -l) + 1)
SRCB_COUNT := 0
SRCB_PCT = $(shell expr 100 \* $(SRCB_COUNT) / $(SRCB_COUNT_TOT))

SRCA_COUNT_TOT := $(shell expr $(shell echo -n $(SRC_ADD) | wc -w) - \
					$(shell ls -l $(OBJ_ADD_DIR) 2>&1 | grep ".o" | wc -l) + 1)
SRCA_COUNT := 0
SRCA_PCT = $(shell expr 100 \* $(SRCA_COUNT) / $(SRCA_COUNT_TOT))

# Colors for Output Messages
BLACK = \033[30;1m
RED = \033[0;31m
GREEN = \033[32;1m
YELLOW = \033[33;1m
BLUE = \033[34;1m
MAGENTA = \033[0;95m
CYAN = \033[36;1m
WHITE = \033[37;1m
RESET = \033[0m

# -------------------------------------#
#           COMPILATION RULES          #
# -------------------------------------#
all: $(NAME)

$(NAME): $(OBJ_CORE) $(OBJ_BONUS) $(OBJ_ADD) | $(BIN_DIR)
	@ar rcs $(NAME) $^
	@printf "\033c"
	@printf "\r%100s\r$(CYAN)$(BIN)$(GREEN) is up to date!$(RESET)\n"

$(OBJ_CORE_DIR)/%.o: $(SRC_CORE_DIR)/%.c | $(OBJ_CORE_DIR)
	@$(eval SRC_COUNT = $(shell expr $(SRC_COUNT) + 1))
	@printf "\r%100s\r[ %d/%d (%d%%) ] Compiling $(BLUE)$<$(RESET)..." "" \
		$(SRC_COUNT) $(SRC_COUNT_TOT) $(SRC_PCT)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_BONUS_DIR)/%.o: $(SRC_BONUS_DIR)/%.c | $(OBJ_BONUS_DIR)
	@$(eval SRCB_COUNT = $(shell expr $(SRCB_COUNT) + 1))
	@printf "\r%100s\r[ %d/%d (%d%%) ] Compiling $(MAGENTA)$<$(RESET)..." "" \
		$(SRCB_COUNT) $(SRCB_COUNT_TOT) $(SRCB_PCT)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_ADD_DIR)/%.o: $(SRC_ADD_DIR)/%.c | $(OBJ_ADD_DIR)
	@$(eval SRCA_COUNT = $(shell expr $(SRCA_COUNT) + 1))
	@printf "\r%100s\r[ %d/%d (%d%%) ] Compiling $(YELLOW)$<$(RESET)..." "" \
		$(SRCA_COUNT) $(SRCA_COUNT_TOT) $(SRCA_PCT)
	@$(CC) $(CFLAGS) -c $< -o $@

# Directory creation rules
$(OBJ_CORE_DIR) $(OBJ_BONUS_DIR) $(OBJ_ADD_DIR) $(BIN_DIR):
	@mkdir -p $@

# -------------------------------------#
#           UTILITY RULES			   #	
# -------------------------------------#
clean:
	@if [ -d "$(OBJ_DIR)" ]; then \
		printf "$(RED)Cleaning up $(BLUE)object files$(RED) in $(YELLOW)libft...$(RESET)\n"; \
		rm -rf $(OBJ_DIR); \
	fi

fclean: clean
	@if [ -d "$(BIN_DIR)" ]; then \
		printf "$(YELLOW)Removing binary $(RED)$(NAME)$(RESET)\n"; \
		rm -rf $(BIN_DIR); \
	fi

norminette:
	@printf "$(YELLOW)Checking norminette...$(RESET)\n"
	@norminette -R CheckForbiddenSourceHeader $(SRC_DIR) inc

leaks: $(NAME)
	@printf "$(YELLOW)Running leaks...$(RESET)\n"
	@valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes ./$(NAME)

re: fclean
	@make all

# -------------------------------------#
#           .PHONY RULES               #
# -------------------------------------#
.PHONY: all clean fclean norminette leaks re