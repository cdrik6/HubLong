/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 20:44:35 by caguillo          #+#    #+#             */
/*   Updated: 2024/02/09 23:38:37 by caguillo         ###   ########.fr       */
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

typedef struct s_plgrd
{
	char	**map;
	int		rows;
	int		cols;

}			t_plgrd;

// main.c
// main
t_plgrd		*create_playground(int rows, char *file);
char		**fill_map(char **newmap, int rows, int fd);
int			count_rows(char *file);
void		free_map(char **newmap, int rows);
void		error_msg(int k);
void		init_plgrd(t_plgrd *plgrd, int rows, char **newmap);

// check.c
int			check_map(t_plgrd *plgrd);
char		*check_cols(t_plgrd *plgrd);
char		*check_vertical_wall(t_plgrd *plgrd);
char		*check_horizontal_wall(t_plgrd *plgrd);
char		*check_player(t_plgrd *plgrd);
char		*check_exit(t_plgrd *plgrd);
char		*check_collectible(t_plgrd *plgrd);

//
char		*ft_strdup(char *s);

#endif
