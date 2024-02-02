/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 19:45:04 by caguillo          #+#    #+#             */
/*   Updated: 2024/02/03 00:29:10 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int		create_map(t_game *game, char *file);
int		fill_map(t_game *game, char *file);
void	count_lines(t_game *game, char *file);
void	free_map(t_game *game);

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		return (0);
	// init_game
	//*********** malloc *****************//
	if (create_map(game, argv[1]) == 0)
		return (free_map(game), 0);
	check_map(game);
}

int	create_map(t_game *game, char *file)
{
	count_lines(game, file);
	if ((*game).nbr_line)
	{
		(*game).map = malloc(sizeof(char *) * ((*game).nbr_line + 1));
		if (!(*game).map)
			return (0);
		(*game).map[(*game).nbr_line] = NULL;
		if (fill_map(game, file) == 0)
			return (free_map(game), 0);
		return (1);
	}
	return (0);
}

int	fill_map(t_game *game, char *file)
{
	int		fd;
	char	*line;
	int		i;
	int		j;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	i = 0;
	while (i < (*game).nbr_line)
	{
		line = get_next_line(fd);
		(*game).map[i] = malloc(sizeof(char) * (ft_strlen(line) + 1));
		if (!(*game).map[i])
			return (0);
		j = 0;
		while (line[j++])
			(*game).map[i][j] = line[j];
		(*game).map[i][j] = '\0';
		i++;
	}
	close(fd);
	return (1);
}

void	count_lines(t_game *game, char *file)
{
	int		fd;
	int		count;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return ;
	count = 0;
	line = get_next_line(fd);
	while (line)
	{
		count++;
		line = get_next_line(fd);
	}
	close(fd);
	(*game).nbr_line = count;
}

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	if ((*game).map)
	{
		while (i++ < (*game).nbr_line)
			if ((*game).map[i])
				free((*game).map[i]);
		free((*game).map);
	}
}
