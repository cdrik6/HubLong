/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 17:40:25 by caguillo          #+#    #+#             */
/*   Updated: 2024/02/19 18:56:43 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <bits/time.h>

// int clock_gettime(clockid_t clk_id, struct timespec *tp);
// struct timespec {
//     time_t tv_sec;  /* seconds */
//     long   tv_nsec; /* nanoseconds */ 1 000 000 000
// };

// int		timer(int delay, int divider);

int	sprite_exit(t_game *game)
{
	nsec	end;
	int		diff_ms;
	int		diff_s;

	clock_gettime(CLOCK_MONOTONIC, &end);
	diff_ms = (end.tv_nsec - (*game).start.tv_nsec) / 100000;
	diff_s = (end.tv_sec - (*game).start.tv_sec);
	if (diff_s == 0 || diff_ms < 1000 )
	{
		printf("r %ld\n", (end.tv_nsec - (*game).start.tv_nsec));
		return (0);
	}
		
	else
	{
		printf("diff %ld\n", (end.tv_nsec - (*game).start.tv_nsec));
		// clock_gettime(CLOCK_MONOTONIC, &(*game).start);
		(*game).start.tv_nsec = end.tv_nsec;
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
	return (0);
}
// printf("s %ld\n", (*game).start.tv_nsec);
// printf("e %ld\n", end.tv_nsec);
// printf("diff %ld\n", (end.tv_nsec - (*game).start.tv_nsec));
// diff = (end.tv_nsec - (*game).start.tv_nsec) / 1000000;

// millis
// int	timer(int delay, t_game *game)
// {
// 	struct timespec	end;
// 	int				diff;

// 	// struct timespec	start;
// 	clock_gettime(CLOCK_MONOTONIC, &end);
// 	diff = (end.tv_nsec - (*game).start.tv_nsec) / 1000000;
// 	while (diff < delay)
// 		clock_gettime(CLOCK_MONOTONIC, &end);
// 	(*game).start.tv_nsec return (1);
// }

// mlx_clear_window((*game).mlx, (*game).mlx_win);
// mlx_string_put((*game).mlx, (*game).mlx_win, (*game).x, 16, 0xFFFFFF,
// 	"Animating!");
/*
clock_t	t0;

	t0 = clock();
	while (clock() - t0 < 0.25)

*/