
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msicot <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/14 09:42:10 by msicot            #+#    #+#              #
#    Updated: 2018/07/12 15:30:12 by msicot           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COMPILATION
CC = gcc
FLAGS = -Wall -Wextra -Werror -g

#BINARY
NAME = asm
#DST = ../../
DST = ./
# OPTIONS
DEBUG = no
ifeq ($(DEBUG), yes)
	FLAGS += -g -fsanitize=address
endif

NOFLAGS = no
ifeq ($(NOFLAGS), yes)
	FLAGS = -g -w
endif

# PATHS
LIBS = ../../libft/libft.a
LIB_PATH = ../../libft/
export LIB_NEED = ../../libft
SRC_PATH = ./srcs/
OBJ_PATH = ./objs/

# SOURCES
SRC_NAME = main.c \
		   ft_token_type.c \
		   ft_token.c \
		   op.c \
		   ft_parsing.c \
		   ft_parse_correctly.c	\
		   analyse_separator.c	\
		   ft_retrieve_line.c \
		   ft_errorm.c	\
		   ft_fill_labels.c \
		   ft_is_smthg.c \
		   ft_syntax.c \
		   ft_tests_label.c \
		   ft_test_params.c \
		   ft_tests_syntax.c \
		   ft_display.c \
		   ft_token_free.c \
		   ft_get_value.c \
		   ft_create_champ.c \
		   ft_write_cor.c \
		   ft_error.c


# OBJECTS
OBJ_NAME = $(SRC_NAME:.c=.o)

# PREFIXES
SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))

# FLAGS
CPPFLAGS = -I./includes/ -I../../libft/includes -I../../includes

# **************************************************************************** #
# SPECIAL CHARS

LOG_CLEAR= \033[2K
LOG_UP= \033[A
LOG_NOCOLOR= \033[0m
LOG_BOLD= \033[1m
LOG_UNDERLINE= \033[4m
LOG_BLINKING= \033[5m
LOG_BLACK= \033[1;30m
LOG_RED= \033[1;31m
LOG_GREEN= \033[1;32m
LOG_YELLOW= \033[1;33m
LOG_BLUE= \033[1;34m
LOG_MAGENTA= \033[1;35m
LOG_CYAN= \033[1;36m
LOG_WHITE= \033[1;37m
LOG_ORANGE= \033[1;38;5;208m

# **************************************************************************** #

# RULES

.PHONY: all
all : libftcomp building $(OBJ_PATH) $(NAME) Makefile

building:
	@echo -e "$(LOG_CLEAR)$(LOG_BLUE)build $(NAME)$(LOG_NOCOLOR)"

libftcomp:
	@$(MAKE) -C $(LIB_PATH)

$(NAME): $(OBJ)
	@echo -e "--$(LOG_CLEAR)$(LOG_MAGENTA)$(NAME)$(LOG_NOCOLOR)....................... $(LOG_ORANGE)assembling$(LOG_NOCOLOR)$(LOG_UP)"
	@$(CC) $^ -o $(DST)$@ $(LIBS) $(FLAGS)
	@echo -e "--$(LOG_CLEAR)$(LOG_CYAN)$(NAME)$(LOG_NOCOLOR) compiled................. $(LOG_GREEN)✓$(LOG_NOCOLOR)"

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@echo -e "--$(LOG_CLEAR)$(LOG_MAGENTA)$(NAME)$(LOG_NOCOLOR)........................ $(LOG_YELLOW)$<$(LOG_NOCOLOR)$(LOG_UP)"
	@$(CC) $(FLAGS) $(CPPFLAGS) -c -o $@ $^

.PHONY: clean
clean:
	@$(MAKE) clean -C $(LIB_PATH)
	@echo -e "$(LOG_CLEAR)$(LOG_BLUE)clean $(NAME)$(LOG_NOCOLOR)"
	@rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	@echo -e "--$(LOG_CLEAR)$(LOG_YELLOW)Objects$(LOG_NOCOLOR) deleted.............. $(LOG_RED)×$(LOG_NOCOLOR)"

.PHONY: fclean
fclean:
	@$(MAKE) fclean -C $(LIB_PATH)
	@echo -e "$(LOG_CLEAR)$(LOG_BLUE)clean $(NAME)$(LOG_NOCOLOR)"
	@rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	@echo -e "--$(LOG_CLEAR)$(LOG_YELLOW)Objects$(LOG_NOCOLOR) deleted.............. $(LOG_RED)×$(LOG_NOCOLOR)"
	@echo -e "$(LOG_CLEAR)$(LOG_BLUE)fclean $(NAME)$(LOG_NOCOLOR)"
	@rm -f $(DST)$(NAME)
	@echo -e "--$(LOG_CLEAR)$(LOG_YELLOW)Binary$(LOG_NOCOLOR) deleted............... $(LOG_RED)×$(LOG_NOCOLOR)"

.PHONY: re
re:
	@$(MAKE) fclean
	@$(MAKE) all
