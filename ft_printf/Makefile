# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: synicole <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/20 20:11:00 by synicole          #+#    #+#              #
#    Updated: 2022/10/22 14:52:16 by synicole         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# VARIABLES
FT_PRINTF	= ft_printf.a
CC			= gcc -g
FLAGS 		= -Wall -Werror -Wextra
SANITIZE	= -fsanitize=address

# OBJ
OBJS		= $(SRCS:.c=.o)

# SOURCES
SRCS		=	srcs/ft_printf.c \
				srcs/ft_formats.c \
				srcs/ft_print_char.c \
				srcs/ft_print_percent.c \
				srcs/ft_print_str.c \
				srcs/ft_print_nbr.c \
				srcs/ft_print_unbr.c \
				srcs/ft_print_hex.c \
				srcs/ft_print_ptr.c

# COLORS
_END=$'\x1b[0m'
_SUCCESS=$'\x1b[42m'
_CLEANED=$'\x1b[44m'

# COMMANDS
$(FT_PRINTF): 	$(OBJS)
				make -C libft
				ar rcs $(FT_PRINTF) $(OBJS)
				@echo "$(_SUCCESS)🚀Build ft_printf!$(_END)"

all:			$(FT_PRINTF)
				@echo "$(_SUCCESS)🚀Build All!$(_END)"

%.o: %.c
				$(CC) -c $(FLAGS) -o $@ $^

clean:
				make clean -C libft
				/bin/rm -rf $(OBJS)
				@echo "$(_CLEANED)🧹Clean object files!$(_END)"

fclean: 		clean
				make fclean -C libft
				/bin/rm -rf $(FT_PRINTF)
				@echo "$(_CLEANED)🧹Clean executable files!$(_END)"

re: 			fclean all
				@echo "$(_SUCCESS)🧹Clean + 🚀Build!$(_END)"

.PHONY:			all clean fclean re
