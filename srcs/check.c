/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 00:29:14 by caguillo          #+#    #+#             */
/*   Updated: 2024/02/20 03:14:47 by caguillo         ###   ########.fr       */
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

char	*check_cols(t_game *game)
{
	int	i;

	i = 0;
	// '\n' except for the last
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

char	*check_vertical_wall(t_game *game)
{
	int	i;

	i = 0;
	while (i < (*game).rows)
	{
		if ((*game).map[i][0] != '1' || (*game).map[i][(*game).cols - 1] != '1')
			return ("Error\nInvalid map (wall missing).\n");
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
	if (count > 1)
		return ("Error\nInvalid map (too many players).\n");
	if (count < 1)
		return ("Error\nInvalid map (player missing).\n");
	return (NULL);
	/**************************************************************/
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
	if (count > 1)
		return ("Error\nInvalid map (too many exits).\n");
	else if (count < 1)
		return ("Error\nInvalid map (exit missing).\n");
	return (NULL);
	(*game).open = 0;
	/**************************************************************/
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

char	*check_path(t_game *game)
{
	int	i;
	int	j;

	flood_fill(game, (*game).player.i, (*game).player.i);
	// check_flood(game); /****************************************************/
	i = 0;
	while (i < (*game).rows)
	{
		j = 0;
		while (j < (*game).cols)
		{
			if ((*game).map[i][j] == 'C')
				return ("Error\nInvalid map (no path to get all collectibles).\n");
			if ((*game).map[i][j] == 'E')
				return ("Error\nInvalid map (no path to get exit).\n");
			j++;
		}
		i++;
	}
	back_flood(game);
	// check_flood(game); /****************************************************/
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

/*
void	get_point(t_game game, t_point *point, char c)
{
	int	i;
	int	j;

	i = 0;
	while (i < game.rows)
	{
		j = 0;
		while (j < game.cols)
		{
			if (game.map[i][j] == c)
			{
				(*point).i = i;
				(*point).j = j;
				// printf("%d\n", (*point).i);
				// printf("%d\n", (*point).j);
				return ;
			}
			j++;
		}
		i++;
	}
}
*/
/*
t_point	*init_point(void)
{
	t_point	point;

	point.i = 0;
	point.j = 0;
	return(&point);
}
*/

/*
int	nbr_rows(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

// printf("cols %d\n", cols);
// 	printf("%s", map[0]);
// 	printf("rows %d\n", nbr_rows(map));

*/
