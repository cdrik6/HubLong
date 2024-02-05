/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 20:44:35 by caguillo          #+#    #+#             */
/*   Updated: 2024/02/05 02:06:21 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line.h"
# include "mlx.h"
# include <stdio.h>

typedef struct s_game
{
	char	**map;
	size_t	rows;
	size_t	cols;

}			t_game;

// main.c
// main
int			create_map(t_game *game, char *file);
int			fill_map(t_game *game, char *file);
int			count_rows(t_game *game, char *file);
void		free_map(t_game *game);
t_game		*init_game();

// check.c
int			check_map(t_game *game);
char		*check_cols(t_game *game);
char		*check_vertical_wall(t_game *game);
char		*check_horizontal_wall(t_game *game);
char		*check_player(t_game *game);
char		*check_exit(t_game *game);
char		*check_collectible(t_game *game);

#endif
