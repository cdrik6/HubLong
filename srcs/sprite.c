/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 17:40:25 by caguillo          #+#    #+#             */
/*   Updated: 2024/02/17 19:58:05 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	sprite_exit(t_game *game)
{
	
	mlx_string_put(data->mlx_ptr, data->win_ptr, data->x, 100, 0xFFFFFF, "Animating!");

	printf("toto\n");
	usleep(500000);
	mlx_put_image_to_window((*game).mlx, (*game).mlx_win, (*game).imgE1.xpm,
		(*game).exit.j * IMG_W, (*game).exit.i * IMG_H);
	usleep(500000);
	mlx_put_image_to_window((*game).mlx, (*game).mlx_win, (*game).imgE1x.xpm,
		(*game).exit.j * IMG_W, (*game).exit.i * IMG_H);
	return (0);
}
