/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 00:29:14 by caguillo          #+#    #+#             */
/*   Updated: 2024/02/03 00:29:52 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	*check_vertical_wall(t_game *game);
char	*check_horizontal_wall(t_game *game);

int	check_map(t_game *game)
{
	check_wall(game);
}

char	*check_vertical_wall(t_game *game)
{
	int	i;

	if ((*game).nbr_line < 3)
		return ("Invalid map (only 2 lines).\n");
	i = 0;
	while (i < (*game).nbr_line)
	{
		if ((*game).map[i][0] != '1' || (*game).map[i][ft_strlen((*game).map[i])
			- 1] != '1')
			return ("Invalid map (wall missing).\n");
		i++;
	}
	return (NULL);
}

char	*check_horizontal_wall(t_game *game)
{
	int	j;

	j = 0;
	while ((*game).map[0][j])
	{
		if ((*game).map[0][j] != '1')
			return ("Invalid map (wall missing).\n");
		j++;
	}
	while ((*game).map[(*game).nbr_line - 1][j])
	{
		if ((*game).map[(*game).nbr_line - 1][j] != '1')
			return ("Invalid map (wall missing).\n");
		j++;
	}
	return (NULL);
}
