/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 20:44:35 by caguillo          #+#    #+#             */
/*   Updated: 2024/02/25 16:01:57 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../includes/get_next_line.h"
# include "../minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <time.h>
//# include <linux/time.h>
//# include <stdio.h>

# define IMG_W 32
# define IMG_H 32

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_UP 65362
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_DOWN 65364
# define KEY_Q 113
# define KEY_ESC 65307

# define C00 "images/c00.xpm"
# define C01 "images/c01.xpm"
# define C02 "images/c02.xpm"
# define C03 "images/c03.xpm"
# define C04 "images/c04.xpm"
# define C05 "images/c05.xpm"
# define C06 "images/c06.xpm"
# define C07 "images/c07.xpm"
# define C08 "images/c08.xpm"
# define WALL "images/wall.xpm"
# define FLOOR "images/floor.xpm"
# define P_UP "images/up.xpm"
# define P_DOWN "images/down.xpm"
# define P_LEFT "images/left.xpm"
# define P_RIGHT "images/right.xpm"
# define EXIT0 "images/exit0.xpm"
# define EXIT1A "images/exit1a.xpm"
# define EXIT1B "images/exit1b.xpm"
# define EXIT1C "images/exit1c.xpm"
# define EXIT1D "images/exit1d.xpm"
# define TIGR "images/tigr.xpm"
# define C00_NBR 9
# define IMG_NBR 21

typedef struct s_img
{
	void				*xpm;
	int					w;
	int					h;

}						t_img;

typedef struct s_point
{
	int					i;
	int					j;

}						t_point;

typedef struct timespec	t_nsec;

typedef struct s_game
{
	char				**map;
	int					rows;
	int					cols;

	t_point				player;
	t_point				exit;
	int					nbr_c;
	int					open;
	int					mvt;

	void				*mlx;
	void				*mlx_win;

	t_img				img1;
	t_img				img0;
	t_img				imgc00;
	t_img				imgc01;
	t_img				imgc02;
	t_img				imgc03;
	t_img				imgc04;
	t_img				imgc05;
	t_img				imgc06;
	t_img				imgc07;
	t_img				imgc08;
	int					select_c;
	t_img				imge0;
	t_img				imge1a;
	t_img				imge1b;
	t_img				imge1c;
	t_img				imge1d;
	t_img				imgpu;
	t_img				imgpd;
	t_img				imgpl;
	t_img				imgpr;
	t_img				imgtr;
	void				*tab_img[IMG_NBR];

	t_nsec				t0;
	int					exit_frame;

	t_nsec				t_tig;
	t_point				tig;
	int					nbr_tig;
}						t_game;

// main.c
// main
int						check_input(int argc, char **argv);
char					**create_map(int rows, char *file);
char					**fill_map(char **newmap, int rows, int fd);
int						count_rows(t_game *game, char *file);

// output.c
void					free_map(char **map, int rows);
void					error_msg(int k);
void					ft_putnbr_fd(int n, int fd);
void					ft_putstr_fd(char *s, int fd);

// check1.c
int						check_map(t_game *game);
int						check_map2(t_game *game);
char					*check_rows(t_game *game);
char					*check_cols(t_game *game);
int						last_nl(char *str);

// check2.c
char					*check_vertical_wall(t_game *game);
char					*check_horizontal_wall(t_game *game);
char					*check_collectible(t_game *game);
char					*check_other(t_game *game);

// check3.c
char					*check_player(t_game *game);
char					*check_player_case(int count);
char					*check_exit(t_game *game);
char					*check_exit_case(int count);

// check3.c
char					*check_path(t_game *game);
void					flood_fill(t_game *game, int i, int j);
void					back_flood(t_game *game);
// void					check_flood(t_game *game);

// libft
size_t					len_nbr(int n);
char					*fill_nbr(char *nbr, size_t size, int n);
char					*ft_itoa(int n);
char					*lib_strjoin(char *s1, char *s2);
char					*ft_strnstr(const char *big, const char *little,
							int len);

// mlx1.c
int						init_mlx(t_game *game);
void					start_game(t_game *game);
int						check_size_map(t_game *game);
void					draw_init_map(t_game *game);
void					image_loader(t_game *game);

// mlx2.c
void					load_image(t_game *game);
void					load_image2(t_game *game);
void					load_tab_image(t_game *game);
int						check_tab_image(t_game *game);
void					destroy_tab_image(t_game *game);

// mlx3.c
void					init_image_on_map(t_game *game, int i, int j);
void					init_c_image_on_map(t_game *game, int i, int j);
void					init_c_image_on_map2(t_game *game, int i, int j);
void					free_game(t_game *game);
void					destroy_image(t_game *game);

// mlx4.c
int						handle_input(int keysym, t_game *game);
void					replace_image(t_game *game, int i, int j, void *xpm);
void					move(t_game *game, int k, int m, void *xpm);
void					move_prev(t_game *game, int i, int j, void *xpm);

// mlx5.c
int						x_close(t_game *game);
void					open_exit(t_game *game);
void					game_win(t_game *game);
void					print_mvt(t_game *game);

// sprite
int						animation(t_game *game);
int						get_diff_ms(t_nsec nano, t_nsec t0);
int						sprite_exit(t_game *game);
void					put_frame(t_game *game, void *xpm);

// tig.c
int						anim_tig(t_game *game);
int						handle_tig(t_game *game);
void					move_tig(t_game *game, int k, int m, void *xpm);
void					game_lose(t_game *game, int i);

// tig_init.c
int						nbr_tig_on_map(t_game *game);
int						put_tig_on_center(t_game *game);
int						init_tig_on_map(t_game *game);

#endif
