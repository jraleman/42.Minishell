# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaleman <jraleman@student.42.us.org>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/15 18:18:00 by jaleman           #+#    #+#              #
#    Updated: 2019/02/15 18:18:01 by jaleman          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= minishell
SRC			= src/main.c \
			  src/minishell.c \
			  src/execute.c \
			  src/builtins.c \
			  src/builtins/cmd_cd.c \
			  src/builtins/cmd_echo.c \
			  src/builtins/cmd_exit.c \
			  src/builtins/cmd_env.c \
			  src/builtins/cmd_help.c \
			  src/builtins/cmd_setenv.c \
			  src/builtins/cmd_unsetenv.c \
			  src/builtins/cmd_pwd.c \
			  src/builtins/cmd_yoshi.c \
			  src/utils/ft_find_env.c \
			  src/utils/ft_bzero.c \
			  src/utils/ft_error.c \
			  src/utils/ft_memalloc.c \
			  src/utils/ft_strclr.c \
			  src/utils/ft_strcpy.c \
			  src/utils/ft_strdup.c \
			  src/utils/ft_strlen.c \
			  src/utils/ft_strncat.c \
			  src/utils/ft_strnew.c \
			  src/utils/ft_strsub.c \
			  src/utils/ft_strcat.c \
			  src/utils/ft_tablen.c \
			  src/utils/ft_tabfree.c \
			  src/utils/ft_strtok.c \
			  src/utils/ft_memset.c \
			  src/utils/ft_strchr.c \
			  src/utils/ft_strrchr.c \
			  src/utils/ft_strjoin.c \
			  src/utils/ft_strncmp.c \
			  src/utils/ft_strcmp.c \
			  src/utils/ft_putstr.c \
			  src/utils/get_next_line.c \
			  src/utils/ft_strncpy.c
INC			= includes/
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra -I $(INC)
OBJ			= $(SRC:.c=.o)
DEBUG		= -g3 -fsanitize=address

all: $(NAME)
%.o: %.c
	@printf "[minishell] Compiling [.:]\r"
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "[minishell] Compiling [:.]\r"
$(NAME): $(OBJ)
	@printf "[minishell] Compiled successfuly! [OK]\n"
	@gcc $(CFLAGS) $(OBJ) -o $(NAME)
debug: $(OBJ)
	@printf "[minishell] Compiled debug successfuly! [OK]\n"
	@gcc $(CFLAGS) $(DEBUG) $(OBJ) -o $(NAME)
clean:
	@/bin/rm -f $(OBJ)
	@printf "[minishell] Removed object files!\n"
fclean: clean
	@/bin/rm -f $(NAME)
	@printf "[minishell] Removed minishell binary!\n"
re: fclean all

.PHONY: all clean fclean re
