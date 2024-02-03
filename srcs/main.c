/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 19:45:04 by caguillo          #+#    #+#             */
/*   Updated: 2024/02/03 23:53:59 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		return (0);
	game = NULL;
	init_game(game);
	if (count_rows(game, argv[1]) == 0)
		return (0);
	//*********** malloc *****************//
	create_map(game, argv[1]);
	// printf("ici\n");
	if (create_map(game, argv[1]) == 0)
		return (free_map(game), 0);
	check_map(game);
}

int	create_map(t_game *game, char *file)
{
	count_rows(game, file);
	printf("ici\n");
	if ((*game).rows)
	{
		(*game).map = malloc(sizeof(char *) * ((*game).rows + 1));
		if (!(*game).map)
			return (0);
		(*game).map[(*game).rows] = NULL;
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
	size_t	i;
	size_t	j;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	i = 0;
	while (i < (*game).rows)
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

int	count_rows(t_game *game, char *file)
{
	int		fd;
	size_t	count;
	char	*line;

	fd = open(file, O_RDONLY);
	printf("fd %d\n", fd);
	if (fd < 0)
		return (0);
	count = 0;
	line = get_next_line(fd);
	while (line)
	{
		count++;
		line = get_next_line(fd);
	}
	close(fd);
	printf("%ld\n", count);
	(*game).rows = count;
	printf("%ld\n", (*game).rows);
	return (1);
}

void	free_map(t_game *game)
{
	size_t	i;

	i = 0;
	if ((*game).map)
	{
		while (i++ < (*game).rows)
			if ((*game).map[i])
				free((*game).map[i]);
		free((*game).map);
	}
}

void	init_game(t_game *game)
{
	
	//(*game).map = NULL;
	printf("init\n");
	(*game).rows = 0;
	(*game).cols = 0;
}