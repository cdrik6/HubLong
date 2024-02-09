/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 00:29:14 by caguillo          #+#    #+#             */
/*   Updated: 2024/02/09 23:09:05 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	*check_cols(t_plgrd *plgrd);
char	*check_vertical_wall(t_plgrd *plgrd);
char	*check_horizontal_wall(t_plgrd *plgrd);
char	*check_player(t_plgrd *plgrd);
char	*check_exit(t_plgrd *plgrd);
char	*check_collectible(t_plgrd *plgrd);

int	check_map(t_plgrd *plgrd)
{
	char	*msg;

	msg = check_cols(plgrd);
	if (msg)
		return (write(2, msg, ft_strlen(msg)), 0);
	msg = check_vertical_wall(plgrd);
	if (msg)
		return (write(2, msg, ft_strlen(msg)), 0);
	msg = check_horizontal_wall(plgrd);
	if (msg)
		return (write(2, msg, ft_strlen(msg)), 0);
	msg = check_player(plgrd);
	if (msg)
		return (write(2, msg, ft_strlen(msg)), 0);
	msg = check_exit(plgrd);
	if (msg)
		return (write(2, msg, ft_strlen(msg)), 0);
	msg = check_collectible(plgrd);
	if (msg)
		return (write(2, msg, ft_strlen(msg)), 0);
	return (1);
}

char	*check_cols(t_plgrd *plgrd)
{
	int	i;

	i = 0;
	// '\n' except for the last
	printf("%d\n", (*plgrd).cols);
	printf("%s", (*plgrd).map[0]);
	(*plgrd).cols = ft_strlen((*plgrd).map[0]) - 1;
	if ((*plgrd).cols == 0)
		return ("Invalid map (empty line).\n");
	while (i < (*plgrd).rows - 1)
	{
		if (ft_strlen((*plgrd).map[i]) - 1 == 0)
			return ("Invalid map (empty line).\n");
		if (ft_strlen((*plgrd).map[i]) - 1 != (*plgrd).cols)
			return ("Invalid map (not rectangular).\n");
		i++;
	}
	if (ft_strlen((*plgrd).map[i]) == 0)
		return ("Invalid map (empty line).\n");
	if (ft_strlen((*plgrd).map[i]) != (*plgrd).cols)
		return ("Invalid map (not rectangular).\n");
	return (NULL);
}

char	*check_vertical_wall(t_plgrd *plgrd)
{
	int	i;

	if ((*plgrd).rows < 3)
		return ("Invalid map (only 2 lines).\n");
	i = 0;
	while (i < (*plgrd).rows)
	{
		if ((*plgrd).map[i][0] != '1' || (*plgrd).map[i][(*plgrd).cols
			- 1] != '1')
			return ("Invalid map (wall missing).\n");
		i++;
	}
	return (NULL);
}

char	*check_horizontal_wall(t_plgrd *plgrd)
{
	int	j;

	j = 0;
	while (j < (*plgrd).cols)
	{
		if ((*plgrd).map[0][j] != '1')
			return ("Invalid map (wall missing).\n");
		if ((*plgrd).map[(*plgrd).rows - 1][j] != '1')
			return ("Invalid map (wall missing).\n");
		j++;
	}
	return (NULL);
}

char	*check_player(t_plgrd *plgrd)
{
	int	count;
	int	i;
	int	j;

	count = 0;
	while (i++ < (*plgrd).rows)
	{
		while (j++ < (*plgrd).cols)
		{
			if ((*plgrd).map[i][j] == 'P')
				count++;
		}
	}
	if (count > 1)
		return ("Invalid map (too many players).\n");
	else if (count < 1)
		return ("Invalid map (player missing).\n");
	return (NULL);
}

char	*check_exit(t_plgrd *plgrd)
{
	int	count;
	int	i;
	int	j;

	count = 0;
	while (i++ < (*plgrd).rows)
	{
		while (j++ < (*plgrd).cols)
		{
			if ((*plgrd).map[i][j] == 'E')
				count++;
		}
	}
	if (count > 1)
		return ("Invalid map (too many exits).\n");
	else if (count < 1)
		return ("Invalid map (exit missing).\n");
	return (NULL);
}

char	*check_collectible(t_plgrd *plgrd)
{
	int	count;
	int	i;
	int	j;

	count = 0;
	while (i++ < (*plgrd).rows)
	{
		while (j++ < (*plgrd).cols)
		{
			if ((*plgrd).map[i][j] == 'C')
				count++;
		}
	}
	if (count < 1)
		return ("Invalid map (collectible missing).\n");
	return (NULL);
}

char	*check_path(t_plgrd *plgrd)
{
	int	count;
	int	i;
	int	j;

	count = 0;
	while (i++ < (*plgrd).rows)
	{
		while (j++ < (*plgrd).cols)
		{
			if ((*plgrd).map[i][j] == 'C')
				count++;
		}
	}
	if (count < 1)
		return ("Invalid map (collectible missing).\n");
	return (NULL);
}

/*
void	error_check(char *msg)
{
	write(2, msg, ft_strlen(msg));
}
*/