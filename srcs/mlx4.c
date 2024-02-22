/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 00:37:38 by caguillo          #+#    #+#             */
/*   Updated: 2024/02/22 00:58:37 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	handle_input(int keysym, t_game *game)
{
	if (keysym == KEY_ESC || keysym == KEY_Q)
		free_game(game);
	if (keysym == KEY_UP || keysym == KEY_W)
		move(game, -1, 0, (*game).imgpu.xpm);
	if (keysym == KEY_DOWN || keysym == KEY_S)
		move(game, 1, 0, (*game).imgpd.xpm);
	if (keysym == KEY_LEFT || keysym == KEY_A)
		move(game, 0, -1, (*game).imgpl.xpm);
	if (keysym == KEY_RIGHT || keysym == KEY_D)
		move(game, 0, 1, (*game).imgpr.xpm);
	return (0);
}

void	replace_image(t_game *game, int i, int j, void *xpm)
{
	if ((*game).map[i][j] == '0')
		mlx_put_image_to_window((*game).mlx, (*game).mlx_win, (*game).img0.xpm,
			j * IMG_W, i * IMG_H);
	if ((*game).map[i][j] == 'P')
		mlx_put_image_to_window((*game).mlx, (*game).mlx_win, xpm, j * IMG_W, i
			* IMG_H);
}

void	move(t_game *game, int k, int m, void *xpm)
{
	int	i;
	int	j;

	i = (*game).player.i + k;
	j = (*game).player.j + m;
	if (i >= 0 && j >= 0 && i < (*game).rows && j < (*game).cols)
	{
		if (i >= 0 && j >= 0 && i == (*game).tig.i && j == (*game).tig.j)
			game_lose(game, 0);
		if ((*game).map[i][j] == 'C')
			open_exit(game);
		if ((*game).map[i][j] == 'E' && (*game).open == 1)
		{
			move_prev(game, i, j, xpm);
			game_win(game);
		}
		else if ((*game).map[i][j] != '1' && (*game).map[i][j] != 'E')
		{
			move_prev(game, i, j, xpm);
			(*game).map[(*game).player.i][(*game).player.j] = 'P';
			replace_image(game, (*game).player.i, (*game).player.j, xpm);
		}
		else
			replace_image(game, (*game).player.i, (*game).player.j, xpm);
	}
}

void	move_prev(t_game *game, int i, int j, void *xpm)
{
	(*game).map[(*game).player.i][(*game).player.j] = '0';
	replace_image(game, (*game).player.i, (*game).player.j, xpm);
	(*game).player.i = i;
	(*game).player.j = j;
	(*game).mvt++;
	print_mvt(game);
}
