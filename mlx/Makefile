# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/13 16:14:02 by caguillo          #+#    #+#              #
#    Updated: 2024/02/03 22:48:32 by caguillo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBC =	mlx_init.c \
		mlx_hook.c

NAME = mlx.a

SRCS = $(LIBC)

OBJS = $(SRCS:.c=.o)

HEADERS = .

.c.o:
		gcc -Wall -Wextra -Werror -I $(HEADERS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
		ar -rc $(NAME) $(OBJS)
		
all: $(NAME)

clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME) 

re: fclean all

.PHONY: all clean fclean re
