/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 20:44:35 by caguillo          #+#    #+#             */
/*   Updated: 2024/02/11 23:54:56 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include "get_next_line.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdio.h>

typedef struct s_game
{
	char	**map;
	int		rows;
	int		cols;
	void	*mlx;
	void	*mlx_win;
}			t_game;

typedef struct s_point
{
	int		i;
	int		j;

}			t_point;

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
void		get_point(t_game game, t_point *point, char c);
// t_point		*init_point(void);
//
char		*ft_strnstr(const char *big, const char *little, int len);

// mlx.c
void		init_mlx(t_game *game);

#endif
