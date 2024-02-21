/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 23:36:29 by caguillo          #+#    #+#             */
/*   Updated: 2024/02/20 23:37:15 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	*check_player(t_game *game)
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
			if ((*game).map[i][j] == 'P')
			{
				count++;
				(*game).player.i = i;
				(*game).player.j = j;
			}
			j++;
		}
		i++;
	}
	return (check_player_case(count));
}

char	*check_player_case(int count)
{
	if (count > 1)
		return ("Error\nInvalid map (too many players).\n");
	if (count < 1)
		return ("Error\nInvalid map (player missing).\n");
	return (NULL);
}

char	*check_exit(t_game *game)
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
			if ((*game).map[i][j] == 'E')
			{
				count++;
				(*game).exit.i = i;
				(*game).exit.j = j;
			}
			j++;
		}
		i++;
	}
	(*game).open = 0;
	return (check_exit_case(count));
}

char	*check_exit_case(int count)
{
	if (count > 1)
		return ("Error\nInvalid map (too many exits).\n");
	else if (count < 1)
		return ("Error\nInvalid map (exit missing).\n");
	return (NULL);
}
