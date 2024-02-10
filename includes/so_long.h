/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 20:44:35 by caguillo          #+#    #+#             */
/*   Updated: 2024/02/10 23:15:15 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line.h"
# include "mlx.h"
# include <stdio.h>

/*typedef struct s_matrix
{
	int		rows;
	int		cols;

}			t_matrix;*/

typedef struct s_game
{
	char	**map;
	int		rows;
	int		cols;

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

//
char		*ft_strnstr(const char *big, const char *little, int len);

#endif
