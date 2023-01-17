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
SERVER_SRC 	= ./srcs/server/server.c

# COLORS
_END=$'\x1b[0m'
_SUCCESS=$'\x1b[42m'
_CLEANED=$'\x1b[44m'

# COMMANDS
$(CLIENT): 		$(CLIENT_OBJ)
				$(CC) $(FLAGS) $(CLIENT_OBJ) -o $(CLIENT)
				@echo "$(_SUCCESS)🚀Build client!$(_END)"

$(SERVER): 		$(SERVER_OBJ)
				$(CC) $(FLAGS) $(SERVER_OBJ) -o $(SERVER)
				@echo "$(_SUCCESS)🚀Build server!$(_END)"

all:			$(CLIENT) $(SERVER)
				@echo "$(_SUCCESS)🚀Build All!$(_END)"

%.o: %.c
				$(CC) -c $(FLAGS) -o $@ $^

clean:
				/bin/rm -rf $(CLIENT_OBJ) $(SERVER_OBJ)
				@echo "$(_CLEANED)🧹Clean object files!$(_END)"

fclean: 		clean
				/bin/rm -rf $(CLIENT) $(SERVER)
				@echo "$(_CLEANED)🧹Clean executable files!$(_END)"

re: 			fclean all
				@echo "$(_SUCCESS)🧹Clean + 🚀Build!$(_END)"

.PHONY:			all clean fclean re