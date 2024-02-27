/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 19:45:04 by caguillo          #+#    #+#             */
/*   Updated: 2024/02/27 19:15:26 by caguillo         ###   ########.fr       */
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
	if (check_map(&game) == 0)
		return (free_map(game.map, game.rows), 0);
	if (init_mlx(&game) == 0)
		return (free_map(game.map, game.rows), 0);
	return (0);
}

// if (!ft_strnstr(argv[1], ".ber", ft_strlen(argv[1]))) -> corrected
int	check_input(int argc, char **argv)
{
	if (argc > 2)
		return (error_msg(3), 0);
	if (argc < 2)
		return (error_msg(4), 0);
	if (check_file_ext(argv[1], ".ber") == 0)
		return (error_msg(5), 0);
	return (1);
}

// newmap = malloc(sizeof(char *) * (rows + 1));
char	**create_map(int rows, char *file)
{
	char	**newmap;
	int		fd;

	newmap = ft_calloc(sizeof(char *), (rows + 1));
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
		if (line)
		{
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
		}
		i++;
	}
	return (newmap[rows] = NULL, newmap);
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

// printf("(%s)\n", line);
// printf("%d\n", ft_strlen(line));
// if (ft_strlen(line) == 2)
// {
// 	printf("0:[%c]\n", line[0]);
// 	printf("1:[%c]\n", line[1]);
// }
