/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 20:00:45 by caguillo          #+#    #+#             */
/*   Updated: 2024/02/21 00:43:16 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	init_mlx(t_game *game)
{
	(*game).mlx = mlx_init();
	if (!(*game).mlx)
		return (error_msg(6), 0);
	if (check_size_map(game) == 1)
	{
		(*game).mlx_win = mlx_new_window((*game).mlx, (*game).cols * IMG_W,
				(*game).rows * IMG_H, "So Long");
		if (!(*game).mlx_win)
		{
			mlx_destroy_display((*game).mlx);
			free((*game).mlx);
			return (error_msg(8), 0);
		}
		start_game(game);
	}
	return (0);
}

void	start_game(t_game *game)
{
	image_loader(game);
	draw_init_map(game);
	(*game).mvt = 0;
	print_mvt(game);
	clock_gettime(CLOCK_MONOTONIC, &((*game).t0));
	clock_gettime(CLOCK_MONOTONIC, &((*game).t_tig));
	(*game).exit_frame = 0;
	if (nbr_tig_on_map(game) == 1)
		init_tig_on_map(game);
	mlx_loop_hook((*game).mlx, animation, game);
	mlx_hook((*game).mlx_win, KeyPress, KeyPressMask, handle_input, game);
	mlx_hook((*game).mlx_win, DestroyNotify, NoEventMask, x_close, game);
	mlx_loop((*game).mlx);
}

int	check_size_map(t_game *game)
{
	int	screen_w;
	int	screen_h;

	mlx_get_screen_size((*game).mlx, &screen_w, &screen_h);
	if ((*game).cols * IMG_W > screen_w || (*game).rows * IMG_H > screen_h)
	{
		error_msg(7);
		mlx_destroy_display((*game).mlx);
		free((*game).mlx);
		return (0);
	}
	return (1);
}

void	draw_init_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < (*game).rows)
	{
		j = 0;
		while (j < (*game).cols)
		{
			init_image_on_map(game, i, j);
			j++;
		}
		i++;
	}
}

void	image_loader(t_game *game)
{
	load_image(game);
	load_tab_image(game);
	if (check_tab_image(game) != 0)
	{
		error_msg(9);
		destroy_tab_image(game);
		mlx_destroy_window((*game).mlx, (*game).mlx_win);
		mlx_destroy_display((*game).mlx);
		free((*game).mlx);
		free_map((*game).map, (*game).rows);
		exit(0);
	}
}
