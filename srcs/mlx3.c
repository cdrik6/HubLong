/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 00:37:26 by caguillo          #+#    #+#             */
/*   Updated: 2024/02/21 00:39:50 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_game(t_game *game)
{
	destroy_image(game);
	mlx_destroy_window((*game).mlx, (*game).mlx_win);
	mlx_destroy_display((*game).mlx);
	free((*game).mlx);
	free_map((*game).map, (*game).rows);
	exit(0);
}

void	destroy_image(t_game *game)
{
	mlx_destroy_image((*game).mlx, (*game).imgc00.xpm);
	mlx_destroy_image((*game).mlx, (*game).imgc01.xpm);
	mlx_destroy_image((*game).mlx, (*game).imgc02.xpm);
	mlx_destroy_image((*game).mlx, (*game).imgc03.xpm);
	mlx_destroy_image((*game).mlx, (*game).imgc04.xpm);
	mlx_destroy_image((*game).mlx, (*game).imgc05.xpm);
	mlx_destroy_image((*game).mlx, (*game).imgc06.xpm);
	mlx_destroy_image((*game).mlx, (*game).imgc07.xpm);
	mlx_destroy_image((*game).mlx, (*game).imgc08.xpm);
	mlx_destroy_image((*game).mlx, (*game).img0.xpm);
	mlx_destroy_image((*game).mlx, (*game).img1.xpm);
	mlx_destroy_image((*game).mlx, (*game).imge0.xpm);
	mlx_destroy_image((*game).mlx, (*game).imge1a.xpm);
	mlx_destroy_image((*game).mlx, (*game).imge1b.xpm);
	mlx_destroy_image((*game).mlx, (*game).imge1c.xpm);
	mlx_destroy_image((*game).mlx, (*game).imge1d.xpm);
	mlx_destroy_image((*game).mlx, (*game).imgpu.xpm);
	mlx_destroy_image((*game).mlx, (*game).imgpd.xpm);
	mlx_destroy_image((*game).mlx, (*game).imgpr.xpm);
	mlx_destroy_image((*game).mlx, (*game).imgpl.xpm);
	mlx_destroy_image((*game).mlx, (*game).imgtr.xpm);
}

void	init_image_on_map(t_game *game, int i, int j)
{
	if ((*game).map[i][j] == '1')
		mlx_put_image_to_window((*game).mlx, (*game).mlx_win, (*game).img1.xpm,
			j * IMG_W, i * IMG_H);
	if ((*game).map[i][j] == '0')
		mlx_put_image_to_window((*game).mlx, (*game).mlx_win, (*game).img0.xpm,
			j * IMG_W, i * IMG_H);
	if ((*game).map[i][j] == 'E')
		mlx_put_image_to_window((*game).mlx, (*game).mlx_win,
			(*game).imge1a.xpm, j * IMG_W, i * IMG_H);
	if ((*game).map[i][j] == 'P')
		mlx_put_image_to_window((*game).mlx, (*game).mlx_win, (*game).imgpu.xpm,
			j * IMG_W, i * IMG_H);
	if ((*game).map[i][j] == 'C')
		init_c_image_on_map(game, i, j);
}

void	init_c_image_on_map(t_game *game, int i, int j)
{
	if ((*game).select_c % 9 == 1)
		mlx_put_image_to_window((*game).mlx, (*game).mlx_win,
			(*game).imgc01.xpm, j * IMG_W, i * IMG_H);
	if ((*game).select_c % 9 == 2)
		mlx_put_image_to_window((*game).mlx, (*game).mlx_win,
			(*game).imgc02.xpm, j * IMG_W, i * IMG_H);
	if ((*game).select_c % 9 == 3)
		mlx_put_image_to_window((*game).mlx, (*game).mlx_win,
			(*game).imgc03.xpm, j * IMG_W, i * IMG_H);
	if ((*game).select_c % 9 == 4)
		mlx_put_image_to_window((*game).mlx, (*game).mlx_win,
			(*game).imgc04.xpm, j * IMG_W, i * IMG_H);
	if ((*game).select_c % 9 == 5)
		mlx_put_image_to_window((*game).mlx, (*game).mlx_win,
			(*game).imgc05.xpm, j * IMG_W, i * IMG_H);
	if ((*game).select_c % 9 == 6)
		mlx_put_image_to_window((*game).mlx, (*game).mlx_win,
			(*game).imgc06.xpm, j * IMG_W, i * IMG_H);
	init_c_image_on_map2(game, i, j);
}

void	init_c_image_on_map2(t_game *game, int i, int j)
{
	if ((*game).select_c % 9 == 7)
		mlx_put_image_to_window((*game).mlx, (*game).mlx_win,
			(*game).imgc07.xpm, j * IMG_W, i * IMG_H);
	if ((*game).select_c % 9 == 8)
		mlx_put_image_to_window((*game).mlx, (*game).mlx_win,
			(*game).imgc08.xpm, j * IMG_W, i * IMG_H);
	if ((*game).select_c % 9 == 0)
		mlx_put_image_to_window((*game).mlx, (*game).mlx_win,
			(*game).imgc00.xpm, j * IMG_W, i * IMG_H);
	(*game).select_c--;
}
