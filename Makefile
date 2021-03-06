# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sam <sam@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/12 14:47:00 by sle-huec          #+#    #+#              #
#    Updated: 2022/06/04 00:12:49 by sam              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex	

CFLAGS = -MMD -Wall -Wextra -Werror -g3
CC = cc
SRCS = 		$(addprefix $(SRCS_PATH), \
				pipex.c \
				path.c \
				utils.c \
				exec.c \
			)
INCLUDES = -I./\
		-I./ft_libft_printf\
		-I./ft_libft_printf/libft

SRCS_PATH = ./srcs/
OBJ_PATH = ./objs/
LIBFT = ./ft_libft_printf/libft/libft.a
LIBFT_PRINTF = ./ft_libft_printf/libftprintf.a


OBJ = $(SRCS:$(SRCS_PATH)%.c=$(OBJ_PATH)%.o)
DEP = $(SRCS:$(SRCS_PATH)%.c=$(OBJ_PATH)%.d)


all: $(NAME)

$(NAME): $(OBJ) $(LIBFT_PRINTF)
	$(CC) $(OBJ) -o $(NAME) $(LIBFT_PRINTF)

${LIBFT_PRINTF}:
		make -C ./ft_libft_printf all

$(OBJ_PATH)%.o: $(SRCS_PATH)%.c 
	mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

clean:
	rm -rf $(OBJ) $(DEP)
	rm -rf $(OBJ_PATH)
	make -C ./ft_libft_printf/ clean

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT_PRINTF)
	rm -f $(LIBFT)

re: fclean
	make -C ./ft_libft_printf re
	make all

.PHONY: all clean fclean re

-include $(DEP)