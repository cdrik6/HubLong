/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 19:45:04 by caguillo          #+#    #+#             */
/*   Updated: 2024/02/09 23:32:38 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	int		rows;
	t_plgrd	*plgrd;

	if (argc != 2)
		return (0);
	// if (strstr ".ber")
	// 	return ("wrong extensions"; 0);
	rows = count_rows(argv[1]);
	if (rows == 0)
		return (0);
	plgrd = create_playground(rows, argv[1]);
	if (!plgrd)
		return (0);
	check_map(plgrd);
	free(plgrd); // free map ?
}

t_plgrd	*create_playground(int rows, char *file)
{
	char	**newmap;
	t_plgrd	*plgrd;
	int		fd;

	plgrd = malloc(sizeof(t_plgrd));
	if (!plgrd)
		return (error_msg(1), NULL);
	newmap = malloc(sizeof(char *) * (rows + 1));
	if (!newmap)
		return (free(plgrd), error_msg(1), NULL);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (free(newmap), free(plgrd), error_msg(2), NULL);
	newmap = fill_map(newmap, rows, fd);
	close(fd);
	if (newmap)
	{
		newmap[rows] = NULL;
		init_plgrd(plgrd, rows, newmap);
		// (*plgrd).map = newmap;
		// (*plgrd).rows = rows;
		// (*plgrd).cols = 0;
		free_map(newmap, rows);
		printf("ici %s", (*plgrd).map[0]);
		return (plgrd);
	}
	return (free(plgrd), error_msg(1), NULL);
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
	return (newmap);
}

int	count_rows(char *file)
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
	return (count);
}

void	free_map(char **newmap, int rows)
{
	int	i;

	i = 0;
	if (newmap)
	{
		while (i < rows)
		{
			if (newmap[i])
				free(newmap[i]);
			i++;
		}
		free(newmap);
	}
}

void	error_msg(int k)
{
	if (k == 0)
		write(2, "Error\nEmpty file.\n", 18);
	if (k == 1)
		write(2, "Error\nCan't malloc the map.\n", 28);
	if (k == 2)
		write(2, "Error\nCan't open the file.\n", 27);
}


void	init_plgrd(t_plgrd *plgrd, int rows, char **newmap)
{
	int i;
	
	(*plgrd).rows = rows;
	(*plgrd).cols = 0;
	i = 0;
	while(newmap[i])	
	{
		(*plgrd).map[i] = ft_strdup(newmap[i]);
		i++;
	}
	(*plgrd).map[i] = NULL;
}
