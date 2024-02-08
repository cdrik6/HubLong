# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/25 23:32:02 by caguillo          #+#    #+#              #
#    Updated: 2024/02/08 00:45:54 by caguillo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long
# NAME_BONUS	=	checker

SRCS		=	./srcs/main.c \
				./srcs/check.c \
				./srcs/get_next_line.c \
				./srcs/get_next_line_utils.c
				
# SRCS_BONUS	=	./srcs/checker.c \
				./srcs/list_tools_1.c \
				./srcs/list_tools_2.c \
				./srcs/load_data.c \
				./srcs/check_data.c \
				./srcs/rules_1.c \
				./srcs/rules_2.c \
				./srcs/sort_1.c \
				./srcs/sort_2.c \
				./srcs/sort_3.c \
				./srcs/sort_4.c \
				./srcs/sort_5.c			

MLX_DIR	=	./mlx
MLX		= 	$(LIBFT_DIR)/mlx.a

INCS_DIR	=	./includes
INCS		=	-I $(INCS_DIR)
#INCS		=	-I $(INCS_DIR) -I $(MLX_DIR)


CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror

OBJS		=	$(SRCS:.c=.o)
#OBJS_BONUS	=	$(SRCS_BONUS:.c=.o)

%.o:%.c
			$(CC) $(CFLAGS) $(INCS) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS) 
#			make -C $(MLX_DIR)
#			mv $(MLX) .
			$(CC) $(CFLAGS) $(OBJS) $(INCS) -o $(NAME)
#			$(CC) $(CFLAGS) $(OBJS) $(INCS) -L . -lft -o $(NAME)
			
all:		$(NAME)

re: 		fclean all

#$(NAME_BONUS):	$(OBJS_BONUS) 
#			make -C $(LIBFT_DIR)
#			mv $(LIBFT) .
#			$(CC) $(CFLAGS) $(OBJS_BONUS) $(INCS) -L . -lft -o $(NAME_BONUS)

#bonus:		$(NAME_BONUS)

rebonus: 	fclean bonus
			
clean:
#			make -C $(MLX_DIR) clean
			rm -f $(OBJS)
#			rm -f $(OBJS) $(OBJS_BONUS)

fclean: 	clean
			rm -f $(NAME)
#			rm -f $(NAME) mlx.a	
#			rm -f $(NAME) $(NAME_BONUS) libft.a	

#.PHONY: 	all clean fclean re bonus rebonus
.PHONY: 	all clean fclean re
