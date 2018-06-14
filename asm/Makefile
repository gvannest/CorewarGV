# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msicot <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/14 09:42:10 by msicot            #+#    #+#              #
#    Updated: 2018/06/14 09:58:03 by msicot           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_NAME = main.c ft_error.c

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC_PATH = ./src/
OBJ_PATH = ./obj/
INC_PATH = ./includes/

MN_NAME = asm
complete = @echo "\033[92mComplete\033[0m"
cleaning = @echo "Project building...\n\033[92mCleaning complete\033[0m"


CC = gcc
CFLAGS = -Werror -Wextra -Wall
NAME = asm
FSANIT = -fsanitize=address

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))

all: $(NAME)

$(NAME): $(OBJ)
	@make -C ../libft
	@gcc $(CFLGAS) $(OBJ) -L../libft/ -lft -o $(MN_NAME)
	$(complete)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@clear
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean :
	@rm -f $(OBJ)
	@rmdir $(OBJ_PATHJ) 2> /dev/null || true
	@make clean -C ../libft
	@echo "ASM's objects have been removed"
	$(cleaning)

fclean : clean
	@rm -f $(NAME)
	@make fclean -C ../libft
	@echo "ASM has been removed"

re : fclean all

