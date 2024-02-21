/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tig.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 19:30:16 by caguillo          #+#    #+#             */
/*   Updated: 2024/02/21 00:52:25 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	anim_tig(t_game *game)
{
	t_nsec	t1;

	clock_gettime(CLOCK_MONOTONIC, &t1);
	if (get_diff_ms(t1, (*game).t_tig) < 500)
		return (0);
	else
	{
		(*game).t_tig = t1;
		srand(time(0));
		handle_tig(game);
	}
	return (1);
}

int	handle_tig(t_game *game)
{
	int	k;

	k = rand() % 6;
	if (k == 0)
		move_tig(game, -1, 0, (*game).imgtr.xpm);
	if (k == 1)
		move_tig(game, 1, 0, (*game).imgtr.xpm);
	if (k == 2)
		move_tig(game, 0, -1, (*game).imgtr.xpm);
	if (k == 3)
		move_tig(game, 0, 1, (*game).imgtr.xpm);
	if (k == 4)
		move_tig(game, 3, 3, (*game).imgtr.xpm);
	if (k == 5)
		move_tig(game, -3, -3, (*game).imgtr.xpm);
	return (0);
}

void	move_tig(t_game *game, int k, int m, void *xpm)
{
	int	i;
	int	j;

	i = (*game).tig.i + k;
	j = (*game).tig.j + m;
	if (i >= 0 && j >= 0 && i < (*game).rows && j < (*game).cols)
	{
		if ((*game).map[i][j] == 'P')
			game_lose(game, 1);
		if ((*game).map[i][j] == '0')
		{
			mlx_put_image_to_window((*game).mlx, (*game).mlx_win,
				(*game).img0.xpm, (*game).tig.j * IMG_W, (*game).tig.i * IMG_H);
			(*game).tig.i = i;
			(*game).tig.j = j;
			mlx_put_image_to_window((*game).mlx, (*game).mlx_win, xpm,
				(*game).tig.j * IMG_W, (*game).tig.i * IMG_H);
		}
		else
			handle_tig(game);
	}
	else
		handle_tig(game);
}

void	game_lose(t_game *game, int i)
{
	if (i == 1)
		ft_putstr_fd("You lost, TIG bits you!\nSo long!\n", 1);
	if (i == 0)
		ft_putstr_fd("You lost, you bits TIG!\nSo long!\n", 1);
	free_game(game);
}
