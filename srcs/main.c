/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 19:45:04 by caguillo          #+#    #+#             */
/*   Updated: 2024/02/11 23:35:04 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	game = (t_game){0};
	if (check_input(argc, argv) == 0)
		return (0);
	if (count_rows(&game, argv[1]) == 0)
		return (0);
	game.map = create_map(game.rows, argv[1]);
	if (!game.map)
		return (0);
	check_map(&game);
	init_mlx(&game);
	free_map(game.map, game.rows);
}

int	check_input(int argc, char **argv)
{
	if (argc > 2)
		return (error_msg(3), 0);
	if (argc < 2)
		return (error_msg(4), 0);
	if (!ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])))
		return (error_msg(5), 0);
	return (1);
}

char	**create_map(int rows, char *file)
{
	char	**newmap;
	int		fd;

	newmap = malloc(sizeof(char *) * (rows + 1));
	if (!newmap)
		return (error_msg(1), NULL);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (free(newmap), error_msg(2), NULL);
	newmap = fill_map(newmap, rows, fd);
	close(fd);
	return (newmap);
}

char	**fill_map(char **newmap, int rows, int fd)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	while (i < rows)
	{
		line = get_next_line(fd);
		newmap[i] = malloc(sizeof(char) * (ft_strlen(line) + 1));
		if (!newmap[i])
			return (free_map(newmap, rows), error_msg(1), NULL);
		j = 0;
		while (line[j])
		{
			newmap[i][j] = line[j];
			j++;
		}
		newmap[i][j] = '\0';
		free(line);
		i++;
	}
	newmap[rows] = NULL;
	return (newmap);
}

int	count_rows(t_game *game, char *file)
{
	int		fd;
	int		count;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (error_msg(2), 0);
	count = 0;
	line = get_next_line(fd);
	while (line)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	if (count == 0)
		error_msg(0);
	(*game).rows = count;
	return (count);
}

void	free_map(char **map, int rows)
{
	int	i;

	i = 0;
	if (map)
	{
		while (i < rows)
		{
			if (map[i])
				free(map[i]);
			i++;
		}
		free(map);
	}
}

void	error_msg(int k)
{
	char	*msg;

	msg = "Error\nEmpty file.\n";
	if (k == 0)
		write(2, msg, ft_strlen(msg));
	msg = "Error\nCan't malloc the map.\n";
	if (k == 1)
		write(2, msg, ft_strlen(msg));
	msg = "Error\nCan't open the file.\n";
	if (k == 2)
		write(2, msg, ft_strlen(msg));
	msg = "Error\nToo many arguments.\n";
	if (k == 3)
		write(2, msg, ft_strlen(msg));
	msg = "Error\nMap file (.ber) is missing.\n";
	if (k == 4)
		write(2, msg, ft_strlen(msg));
	msg = "Error\nMap should be a \".ber\" file.\n";
	if (k == 5)
		write(2, msg, ft_strlen(msg));
}

// printf("rows main %d\n", (*game).rows);

// void	init_game(t_game *game, int rows)
// {
// 	int	i;

// 	// t_game	*game;
// 	//(*game).map = map;
// 	(*game).rows = rows;
// 	(*game).cols = 0;
// 	printf("rows %d\n", (*game).rows);
// 	i = 0;
// 	while ((*game).map[i])
// 	{
// 		printf("%s", (*game).map[i]);
// 		i++;
// 	}
// 	// 	printf("%s", map[0]);
// 	//
// 	/*
// 	while (newmap[i])
// 	{
// 		(*plgrd).map[i] = ft_strdup(newmap[i]);
// 		i++;
// 	}
// 	(*plgrd).map[i] = NULL;
// 	*/
// 	// return (game);
// }
