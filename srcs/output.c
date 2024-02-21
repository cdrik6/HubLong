/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 23:26:58 by caguillo          #+#    #+#             */
/*   Updated: 2024/02/20 23:28:35 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
	if (k == 0)
		ft_putstr_fd("Error\nEmpty file.\n", 2);
	if (k == 1)
		ft_putstr_fd("Error\nCan't malloc the map.\n", 2);
	if (k == 2)
		ft_putstr_fd("Error\nCan't open the file.\n", 2);
	if (k == 3)
		ft_putstr_fd("Error\nToo many arguments.\n", 2);
	if (k == 4)
		ft_putstr_fd("Error\nMap file (.ber) is missing.\n", 2);
	if (k == 5)
		ft_putstr_fd("Error\nMap should be a \".ber\" file.\n", 2);
	if (k == 6)
		ft_putstr_fd("Error\nCan't initialize the MLX.\n", 2);
	if (k == 7)
		ft_putstr_fd("Error\nThe map is too big for the screen.\n", 2);
	if (k == 8)
		ft_putstr_fd("Error\nMLX can't generate the window.\n", 2);
	if (k == 9)
		ft_putstr_fd("Error\nMLX can't load whole images.\n", 2);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			write(fd, "-", 1);
			n = -n;
		}
		if (n >= 10)
		{
			ft_putnbr_fd(n / 10, fd);
			ft_putnbr_fd(n % 10, fd);
		}
		if (n < 10)
		{
			c = n + 48;
			write(fd, &c, 1);
		}
	}
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}
