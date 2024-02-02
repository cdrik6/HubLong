/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 20:44:35 by caguillo          #+#    #+#             */
/*   Updated: 2024/02/03 00:28:55 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line.h"
# include "mlx.h"

typedef struct s_game
{
	char	**map;
    int nbr_line;
    
}			t_game;


//main.c
//main
int		create_map(t_game *game, char *file);
int		fill_map(t_game *game, char *file);
void	count_lines(t_game *game, char *file);
void	free_map(t_game *game);

//check.c


#endif
