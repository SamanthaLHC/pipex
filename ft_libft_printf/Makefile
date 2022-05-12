# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sam <sam@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/21 15:51:28 by sle-huec          #+#    #+#              #
#    Updated: 2022/04/20 13:12:12 by sam              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror -I./libft

CC = cc

SRC = ft_putnbr_unsigned.c \
	  ft_printf.c \
	  ft_putnbr_hexa.c \
	  ft_putnbr_hexa_upp.c \
	  ft_put_ptr.c \
	  ft_putnbr.c \
	  ft_putstr.c \
	  ft_putchar.c

OBJ = ${SRC:%.c=%.o}

NAME = libftprintf.a

LIBFT = libft/libft.a

all: ${NAME}

${LIBFT}:
		make -C ./libft

${NAME}: ${LIBFT} ${OBJ}
		cp ${LIBFT} ${NAME}
		ar -rcs ${NAME} ${OBJ}
		 
clean:
	  rm -rf ${OBJ} 
	  make -C ./libft clean
	  
fclean: clean
	  rm -rf ${NAME}
	  make -C ./libft fclean

re: fclean all

.PHONY: all clean fclean re 
