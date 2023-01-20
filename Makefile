# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: synicole <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/29 14:10:25 by synicole          #+#    #+#              #
#    Updated: 2022/11/29 14:10:27 by synicole         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# VARIABLES
CLIENT 			= client
SERVER 			= server
CC				= gcc -g
FLAGS 			= -Wall -Werror -Wextra
SANITIZE		= -fsanitize=address

# OBJ
CLIENT_OBJ		= $(CLIENT_SRC:.c=.o)
SERVER_OBJ		= $(SERVER_SRC:.c=.o)

# SOURCES
CLIENT_SRC	= ./srcs/client/client.c
SERVER_SRC 	= ./srcs/server/server.c \
			  ./srcs/utils/ft_error.c \
			  ./srcs/utils/ft_recursive_power.c

# COLORS
_END=$'\x1b[0m'
_SUCCESS=$'\x1b[42m'
_CLEANED=$'\x1b[44m'

# COMMANDS
$(CLIENT): 		$(CLIENT_OBJ)
				make -C ft_printf
				$(CC) $(FLAGS) $(CLIENT_OBJ) ft_printf/ft_printf.a ft_printf/libft/libft.a -o $(CLIENT)
				@echo "$(_SUCCESS)🚀Build client!$(_END)"

$(SERVER): 		$(SERVER_OBJ)
				make -C ft_printf
				$(CC) $(FLAGS) $(SERVER_OBJ) ft_printf/ft_printf.a ft_printf/libft/libft.a -o $(SERVER)
				@echo "$(_SUCCESS)🚀Build server!$(_END)"

all:			$(CLIENT) $(SERVER)
				@echo "$(_SUCCESS)🚀Build All!$(_END)"

%.o: %.c
				$(CC) -c $(FLAGS) -o $@ $^

clean:
				make clean -C ft_printf
				/bin/rm -rf $(CLIENT_OBJ) $(SERVER_OBJ)
				@echo "$(_CLEANED)🧹Clean object files!$(_END)"

fclean: 		clean
				make fclean -C ft_printf
				/bin/rm -rf $(CLIENT) $(SERVER)
				@echo "$(_CLEANED)🧹Clean executable files!$(_END)"

re: 			fclean all
				@echo "$(_SUCCESS)🧹Clean + 🚀Build!$(_END)"

.PHONY:			all clean fclean re