/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 23:33:34 by caguillo          #+#    #+#             */
/*   Updated: 2024/02/21 21:15:52 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	*check_vertical_wall(t_game *game)
{
	int	i;

	i = 0;
	while (i < (*game).rows)
	{
		if ((*game).map[i][0] != '1' || (*game).map[i][(*game).cols - 1] != '1')
			return ("Error\nInvalid map (wall missing/empty line).\n");
		i++;
	}
	return (NULL);
}

char	*check_horizontal_wall(t_game *game)
{
	int	j;

	j = 0;
	while (j < (*game).cols)
	{
		if ((*game).map[0][j] != '1')
			return ("Error\nInvalid map (wall missing).\n");
		if ((*game).map[(*game).rows - 1][j] != '1')
			return ("Error\nInvalid map (wall missing).\n");
		j++;
	}
	return (NULL);
}

char	*check_collectible(t_game *game)
{
	int	count;
	int	i;
	int	j;

	count = 0;
	i = 0;
	while (i < (*game).rows)
	{
		j = 0;
		while (j < (*game).cols)
		{
			if ((*game).map[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	if (count < 1)
		return ("Error\nInvalid map (collectible missing).\n");
	(*game).nbr_c = count;
	(*game).select_c = count;
	return (NULL);
}

char	*check_other(t_game *game)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < (*game).rows)
	{
		j = 0;
		while (j < (*game).cols)
		{
			c = (*game).map[i][j];
			if (!(c == 'P' || c == 'E' || c == 'C' || c == '0' || c == '1'))
				return ("Error\nInvalid map (wrong character).\n");
			j++;
		}
		i++;
	}
	return (NULL);
}
