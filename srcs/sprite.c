/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 17:40:25 by caguillo          #+#    #+#             */
/*   Updated: 2024/02/19 03:05:26 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// int clock_gettime(clockid_t clk_id, struct timespec *tp);
// struct timespec {
//     time_t tv_sec;  /* seconds */
//     long   tv_nsec; /* nanoseconds */ 1 000 000 000
// };

// int		timer(int delay, int divider);

int	sprite_exit(t_game *game)
{
	struct timespec	end;
	int				diff;

	clock_gettime(CLOCK_MONOTONIC, &end);
	// printf("s %ld\n", (*game).start.tv_nsec);
	// printf("e %ld\n", end.tv_nsec);
	// printf("diff %ld\n", (end.tv_nsec - (*game).start.tv_nsec));
	// diff = (end.tv_nsec - (*game).start.tv_nsec) / 1000000;
	diff = (end.tv_nsec - (*game).start.tv_nsec) / 1000000;
	(*game).start = end;
	if ((diff) == 1)
	{
		if ((*game).exit_frame == 0)
		{
			mlx_put_image_to_window((*game).mlx, (*game).mlx_win,
				(*game).imgE1x.xpm, (*game).exit.j * IMG_W, (*game).exit.i
				* IMG_H);
			(*game).exit_frame = 1;
		}
		else
		{
			(*game).exit_frame = 0;
			mlx_put_image_to_window((*game).mlx, (*game).mlx_win,
				(*game).imgE1.xpm, (*game).exit.j * IMG_W, (*game).exit.i
				* IMG_H);
		}
	}
	// if (timer(1, 1) == 1)
	// 	mlx_put_image_to_window((*game).mlx, (*game).mlx_win,
	// 		(*game).imgE1x.xpm, (*game).exit.j * IMG_W, (*game).exit.i * IMG_H);
	// if (timer(1, 1) == 1)
	// 	mlx_put_image_to_window((*game).mlx, (*game).mlx_win, (*game).imgE1.xpm,
	// 		(*game).exit.j * IMG_W, (*game).exit.i * IMG_H);
	return (0);
}

// int	timer(int delay, int divider)
// {
// 	struct timespec	start;
// 	struct timespec	end;

// 	clock_gettime(CLOCK_MONOTONIC, &start);
// 	while (end.tv_sec - start.tv_sec < delay / divider)
// 		clock_gettime(CLOCK_MONOTONIC, &end);
// 	return (1);
// }

// mlx_clear_window((*game).mlx, (*game).mlx_win);
// mlx_string_put((*game).mlx, (*game).mlx_win, (*game).x, 16, 0xFFFFFF,
// 	"Animating!");
/*
clock_t	t0;

	t0 = clock();
	while (clock() - t0 < 0.25)

*/