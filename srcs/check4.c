/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 23:37:31 by caguillo          #+#    #+#             */
/*   Updated: 2024/02/20 23:38:23 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// check_flood(game);
char	*check_path(t_game *game)
{
	int	i;
	int	j;

	flood_fill(game, (*game).player.i, (*game).player.i);
	i = 0;
	while (i < (*game).rows)
	{
		j = 0;
		while (j < (*game).cols)
		{
			if ((*game).map[i][j] == 'C')
				return ("Error\nInvalid map (no path to get collectibles).\n");
			if ((*game).map[i][j] == 'E')
				return ("Error\nInvalid map (no path to get exit).\n");
			j++;
		}
		i++;
	}
	back_flood(game);
	return (NULL);
}

void	flood_fill(t_game *game, int i, int j)
{
	if ((*game).map[i][j] == 'C')
		(*game).map[i][j] = 'D';
	else
		(*game).map[i][j] = 'X';
	if ((*game).map[i + 1][j] != '1' && (*game).map[i + 1][j] != 'X'
		&& (*game).map[i + 1][j] != 'D')
		flood_fill(game, i + 1, j);
	if ((*game).map[i - 1][j] != '1' && (*game).map[i - 1][j] != 'X'
		&& (*game).map[i - 1][j] != 'D')
		flood_fill(game, i - 1, j);
	if ((*game).map[i][j + 1] != '1' && (*game).map[i][j + 1] != 'X'
		&& (*game).map[i][j + 1] != 'D')
		flood_fill(game, i, j + 1);
	if ((*game).map[i][j - 1] != '1' && (*game).map[i][j - 1] != 'X'
		&& (*game).map[i][j - 1] != 'D')
		flood_fill(game, i, j - 1);
}

void	back_flood(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < (*game).rows)
	{
		j = 0;
		while (j < (*game).cols)
		{
			if ((*game).map[i][j] == 'D')
				(*game).map[i][j] = 'C';
			if ((*game).map[i][j] == 'X')
				(*game).map[i][j] = '0';
			j++;
		}
		i++;
	}
	(*game).map[(*game).player.i][(*game).player.j] = 'P';
	(*game).map[(*game).exit.i][(*game).exit.j] = 'E';
}

/*
void	check_flood(t_game *game)
{
	int	i;

	i = 0;
	printf("%d\n", (*game).rows);
	printf("%d\n", (*game).cols);
	while (i < (*game).rows)
	{
		printf("%s", (*game).map[i]);
		i++;
	}
}
*/
