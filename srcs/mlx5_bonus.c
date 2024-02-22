/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx5.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 00:37:41 by caguillo          #+#    #+#             */
/*   Updated: 2024/02/21 00:42:55 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	x_close(t_game *game)
{
	free_game(game);
	return (0);
}

void	open_exit(t_game *game)
{
	(*game).nbr_c--;
	if ((*game).nbr_c == 0)
	{
		(*game).open = 1;
		mlx_put_image_to_window((*game).mlx, (*game).mlx_win, (*game).imge0.xpm,
			(*game).exit.j * IMG_W, (*game).exit.i * IMG_H);
	}
}

void	game_win(t_game *game)
{
	ft_putstr_fd("Welcome at 42!\n", 1);
	ft_putstr_fd("To join the school you needed ", 1);
	ft_putnbr_fd((*game).mvt, 1);
	ft_putstr_fd(" movements... so long !\n", 1);
	free_game(game);
}

void	print_mvt(t_game *game)
{
	char	*nbr;
	char	*str;

	nbr = NULL;
	nbr = ft_itoa((*game).mvt);
	if (nbr)
		str = lib_strjoin("Movements: ", nbr);
	else
		str = NULL;
	mlx_put_image_to_window((*game).mlx, (*game).mlx_win, (*game).img1.xpm, 0
		* IMG_W, 0 * IMG_H);
	mlx_put_image_to_window((*game).mlx, (*game).mlx_win, (*game).img1.xpm, 1
		* IMG_W, 0 * IMG_H);
	mlx_put_image_to_window((*game).mlx, (*game).mlx_win, (*game).img1.xpm, 2
		* IMG_W, 0 * IMG_H);
	if (str)
		mlx_string_put((*game).mlx, (*game).mlx_win, 0, IMG_H / 2, 0xFFFFFF,
			str);
	free(nbr);
	free(str);
}
