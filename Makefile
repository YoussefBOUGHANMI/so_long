# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Youssef <youssef.boughanmi.pro@gmail.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/29 13:45:56 by Youssef           #+#    #+#              #
#    Updated: 2022/06/28 21:07:07 by youssef          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

LFLAGS	=	-I /usr/local/include -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit

NAME	=	so_long

SRCS	=	utils_4.c utils_3.c utils_2.c utils_1.c main.c utils_5.c utils_6.c utils_7.c utils_8.c utils_9.c utils_10.c utils_11.c

OBJ	=	$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(SRCS) $(CFLAGS) $(LFLAGS) -o $(NAME)
	@echo "Making so_long..."

%.o : %.c	
	@$(CC) -o $@ -c $< $(CFLAGS)

clean:
	@rm -f $(OBJ) 
	@echo "Clean(so_long)"

fclean: clean
	@rm -f $(NAME)
	@echo "Fclean(so_long)"

re : fclean all

.PHONY: all fclean clean re $(EXEC)
