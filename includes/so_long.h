/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 20:44:35 by caguillo          #+#    #+#             */
/*   Updated: 2024/02/16 00:41:49 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include "get_next_line.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdio.h>

# define IMG_W 32
# define IMG_H 32

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
// # define KEY_2 65433
// # define KEY_4 65430
// # define KEY_6 65432
// # define KEY_8 65431
# define KEY_UP 65362
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_DOWN 65364
# define KEY_Q 113
# define KEY_ESC 65307

# define WALL "images/wall.xpm"
# define FLOOR "images/floor.xpm"
# define P_UP "images/up.xpm"
# define P_DOWN "images/down.xpm"
# define P_LEFT "images/left.xpm"
# define P_RIGHT "images/right.xpm"
# define EXIT0 "images/exit0.xpm"
# define EXIT1 "images/exit1.xpm"
# define C00 "images/c00.xpm"
# define C01 "images/c01.xpm"
# define C02 "images/c02.xpm"
# define C03 "images/c03.xpm"

typedef struct s_img
{
	void	*xpm;
	int		w;
	int		h;

}			t_img;

typedef struct s_point
{
	int		i;
	int		j;

}			t_point;

typedef struct s_game
{
	// map
	char	**map;
	int		rows;
	int		cols;
	// utils
	t_point	player;
	t_point	exit;
	int		nbr_c;
	int		open;
	int		mvt;
	// mlx
	void	*mlx;
	void	*mlx_win;
	// images
	t_img	img1;
	t_img	img0;
	t_img	imgC00;
	t_img	imgC01;
	t_img	imgC02;
	t_img	imgC03;
	int		temp_c;
	t_img	imgE0;
	t_img	imgE1;
	t_img	imgPu;
	t_img	imgPd;
	t_img	imgPl;
	t_img	imgPr;

}			t_game;

// main.c
// main
int			check_input(int argc, char **argv);
char		**create_map(int rows, char *file);
char		**fill_map(char **newmap, int rows, int fd);
int			count_rows(t_game *game, char *file);
void		free_map(char **map, int rows);
void		error_msg(int k);

// check.c
int			check_map(t_game *game);
int			check_map2(t_game *game);
char		*check_rows(t_game *game);
char		*check_cols(t_game *game);
int			last_nl(char *str);
char		*check_vertical_wall(t_game *game);
char		*check_horizontal_wall(t_game *game);
char		*check_player(t_game *game);
char		*check_exit(t_game *game);
char		*check_collectible(t_game *game);
char		*check_other(t_game *game);
char		*check_path(t_game *game);
void		flood_fill(t_game *game, int i, int j);
void		check_flood(t_game *game);
void		back_flood(t_game *game);
// void		get_point(t_game game, t_point *point, char c);
// t_point		*init_point(void);

// libft
char		*ft_strnstr(const char *big, const char *little, int len);
void		ft_putnbr_fd(int n, int fd);
void		ft_putstr_fd(char *s, int fd);

// mlx.c
int			init_mlx(t_game *game);
void		draw_init_map(t_game *game);
void		load_image(t_game *game);
void		init_image_on_map(t_game *game, int i, int j);
void		init_C_image_on_map(t_game *game, int i, int j);
void		free_game(t_game *game);
int			handle_input(int keysym, t_game *game);
void		destroy_image(t_game *game);

void		replace_image(t_game *game, int i, int j, void *xpm);
void		move(t_game *game, int k, int m, void *xpm);
int			x_close(t_game *game);
void		open_exit(t_game *game);
void		game_win(t_game *game);
int			check_size_map(t_game *game);

#endif
