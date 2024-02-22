/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:36:17 by caguillo          #+#    #+#             */
/*   Updated: 2024/02/21 20:54:40 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	argc_errors(int argc);
int	is_open(char *filename);

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	if (argc_errors(argc) == 1)
	{
		fd = is_open(argv[1]);
		while (i < 1000)
		{
			line = get_next_line(fd);
			if (line == NULL)
			{
				write(1, "line null\n", 10);
				break ;
			}
			else
				write(1, line, ft_strlen(line));
			free(line);
			i++;
		}
		close(fd);
	}
}

int	argc_errors(int argc)
{
	if (argc == 1)
	{
		write(2, "File name missing.\n", 19);
		return (-1);
	}
	if (argc > 2)
	{
		write(2, "Too many arguments.\n", 20);
		return (-1);
	}
	return (1);
}

int	is_open(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		write(2, "Cannot read file.\n", 18);
	return (fd);
}
