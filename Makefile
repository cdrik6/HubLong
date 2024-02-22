# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/25 23:32:02 by caguillo          #+#    #+#              #
#    Updated: 2024/02/22 19:17:16 by caguillo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long
NAME_BONUS	=	so_long_bonus

SRCS		=	./srcs/main.c \
				./srcs/output.c \
				./srcs/check1.c \
				./srcs/check2.c \
				./srcs/check3.c \
				./srcs/check4.c \
				./srcs/mlx1.c \
				./srcs/mlx2.c \
				./srcs/mlx3.c \
				./srcs/mlx4.c \
				./srcs/mlx5.c \
				./srcs/libft.c \
				./srcs/get_next_line.c \
				./srcs/get_next_line_utils.c

SRCS_BONUS	=	./srcs/main.c \
				./srcs/output.c \
				./srcs/check1.c \
				./srcs/check2.c \
				./srcs/check3.c \
				./srcs/check4.c \
				./srcs/mlx1_bonus.c \
				./srcs/mlx2.c \
				./srcs/mlx3.c \
				./srcs/mlx4.c \
				./srcs/mlx5_bonus.c \
				./srcs/sprite.c \
				./srcs/tig.c \
				./srcs/tig_init.c \
				./srcs/libft.c \
				./srcs/get_next_line.c \
				./srcs/get_next_line_utils.c

MLX_DIR		=	./minilibx-linux
MLX			= 	$(MLX_DIR)/libmlx.a
MLXLIB		= 	$(MLX) -lXext -lX11 -lm -lrt

INCS_SRCS	=	./includes/so_long.h
INCS_DIR	=	-Iincludes -Iminilibx-linux

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror

OBJS		=	$(SRCS:.c=.o)
OBJS_BONUS	=	$(SRCS_BONUS:.c=.o)

%.o:%.c		$(INCS_SRCS)
			$(CC) $(CFLAGS) $(INCS_DIR) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
			make -C $(MLX_DIR)
			$(CC) $(CFLAGS) $(OBJS) $(MLXLIB) -o $(NAME)
			
all:		$(NAME)

re: 		fclean all

$(NAME_BONUS):	$(OBJS_BONUS) 
			make -C $(MLX_DIR)
			$(CC) $(CFLAGS) $(OBJS_BONUS) $(MLXLIB) -o $(NAME_BONUS)

bonus:		$(NAME_BONUS)

rebonus: 	fclean bonus
			
clean:
			make -C $(MLX_DIR) clean
			rm -f $(OBJS) $(OBJS_BONUS)

fclean: 	clean
			rm -f $(NAME) $(NAME_BONUS)
			
.PHONY: 	all clean fclean re bonus rebonus