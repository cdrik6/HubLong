/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 00:29:14 by caguillo          #+#    #+#             */
/*   Updated: 2024/02/03 23:20:19 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	*check_cols(t_game *game);
char	*check_vertical_wall(t_game *game);
char	*check_horizontal_wall(t_game *game);
char	*check_player(t_game *game);
char	*check_exit(t_game *game);
char	*check_collectible(t_game *game);

int	check_map(t_game *game)
{
	check_cols(game);
	check_vertical_wall(game);
	check_horizontal_wall(game);
	check_player(game);
	check_exit(game);
	check_collectible(game);
	return(0);
}

char	*check_cols(t_game *game)
{
	size_t	i;

	i = 0;
	// '\n' except for the last
	(*game).cols = ft_strlen((*game).map[0]) - 1;
	while (i < (*game).rows - 1)
	{
		if (ft_strlen((*game).map[i]) - 1 != (*game).cols)
			return ("Invalid map (not rectangular).\n");
		i++;
	}
	if (ft_strlen((*game).map[i]) != (*game).cols)
		return ("Invalid map (not rectangular).\n");
	return (NULL);
}

char	*check_vertical_wall(t_game *game)
{
	size_t	i;

	if ((*game).rows < 3)
		return ("Invalid map (only 2 lines).\n");
	i = 0;
	while (i < (*game).rows)
	{
		if ((*game).map[i][0] != '1' || (*game).map[i][(*game).cols - 1] != '1')
			return ("Invalid map (wall missing).\n");
		i++;
	}
	return (NULL);
}

char	*check_horizontal_wall(t_game *game)
{
	size_t	j;

	j = 0;
	while (j < (*game).cols)
	{
		if ((*game).map[0][j] != '1')
			return ("Invalid map (wall missing).\n");
		if ((*game).map[(*game).rows - 1][j] != '1')
			return ("Invalid map (wall missing).\n");
		j++;
	}
	return (NULL);
}

char	*check_player(t_game *game)
{
	int	count;
	size_t	i;
	size_t	j;

	count = 0;
	while (i++ < (*game).rows)
	{
		while (j++ < (*game).cols)
		{
			if ((*game).map[i][j] == 'P')
				count++;
		}
	}
	if (count > 1)
		return ("Invalid map (too many players).\n");
	else if (count < 1)
		return ("Invalid map (player missing).\n");
	return (NULL);
}

char	*check_exit(t_game *game)
{
	int	count;
	size_t	i;
	size_t	j;

	count = 0;
	while (i++ < (*game).rows)
	{
		while (j++ < (*game).cols)
		{
			if ((*game).map[i][j] == 'E')
				count++;
		}
	}
	if (count > 1)
		return ("Invalid map (too many exits).\n");
	else if (count < 1)
		return ("Invalid map (exit missing).\n");
	return (NULL);
}

char	*check_collectible(t_game *game)
{
	int	count;
	size_t	i;
	size_t	j;

	count = 0;
	while (i++ < (*game).rows)
	{
		while (j++ < (*game).cols)
		{
			if ((*game).map[i][j] == 'C')
				count++;
		}
	}
	if (count < 1)
		return ("Invalid map (collectible missing).\n");
	return (NULL);
}

char	*check_path(t_game *game)
{
	int count;
	size_t i;
	size_t j;

	count = 0;
	while (i++ < (*game).rows)
	{
		while (j++ < (*game).cols)
		{
			if ((*game).map[i][j] == 'C')
				count++;
		}
	}
	if (count < 1)
		return ("Invalid map (collectible missing).\n");
	return (NULL);
}