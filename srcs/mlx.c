/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 20:00:45 by caguillo          #+#    #+#             */
/*   Updated: 2024/02/11 22:10:38 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_mlx(t_game *game)
{
	(*game).mlx = mlx_init();
	(*game).mlx_win = mlx_new_window((*game).mlx, 1920, 1080, "Hello world!");
	mlx_loop((*game).mlx);
}
