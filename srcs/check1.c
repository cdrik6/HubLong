/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 00:29:14 by caguillo          #+#    #+#             */
/*   Updated: 2024/02/20 23:42:35 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_map(t_game *game)
{
	char	*msg;

	msg = check_rows(game);
	if (msg)
		return (write(2, msg, ft_strlen(msg)), 0);
	msg = check_cols(game);
	if (msg)
		return (write(2, msg, ft_strlen(msg)), 0);
	msg = check_vertical_wall(game);
	if (msg)
		return (write(2, msg, ft_strlen(msg)), 0);
	msg = check_horizontal_wall(game);
	if (msg)
		return (write(2, msg, ft_strlen(msg)), 0);
	msg = check_player(game);
	if (msg)
		return (write(2, msg, ft_strlen(msg)), 0);
	msg = check_exit(game);
	if (msg)
		return (write(2, msg, ft_strlen(msg)), 0);
	msg = check_collectible(game);
	if (msg)
		return (write(2, msg, ft_strlen(msg)), 0);
	return (check_map2(game));
}

int	check_map2(t_game *game)
{
	char	*msg;

	msg = check_other(game);
	if (msg)
		return (write(2, msg, ft_strlen(msg)), 0);
	msg = check_path(game);
	if (msg)
		return (write(2, msg, ft_strlen(msg)), 0);
	return (1);
}

char	*check_rows(t_game *game)
{
	if ((*game).rows < 3)
		return ("Error\nInvalid map (not enough lines).\n");
	return (NULL);
}

// '\n' except for the last
char	*check_cols(t_game *game)
{
	int	i;

	i = 0;
	(*game).cols = ft_strlen((*game).map[0]) - 1;
	if ((*game).cols == 0)
		return ("Error\nInvalid map (empty line).\n");
	while (i < (*game).rows - 1)
	{
		if (ft_strlen((*game).map[i]) - 1 == 0)
			return ("Error\nInvalid map (empty line).\n");
		if (ft_strlen((*game).map[i]) - 1 != (*game).cols)
			return ("Error\nInvalid map (not rectangular).\n");
		i++;
	}
	if (ft_strlen((*game).map[i]) - last_nl((*game).map[i]) == 0)
		return ("Error\nInvalid map (empty line).\n");
	if (ft_strlen((*game).map[i]) - last_nl((*game).map[i]) != (*game).cols)
		return ("Error\nInvalid map (not rectangular).\n");
	return (NULL);
}

int	last_nl(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
