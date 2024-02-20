/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 17:40:25 by caguillo          #+#    #+#             */
/*   Updated: 2024/02/20 19:30:48 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// int clock_gettime(clockid_t clk_id, struct timespec *tp);
// struct timespec {
//     time_t tv_sec;  /* seconds */
//     long   tv_nsec; /* nanoseconds */ 1 000 000 000
// };

// int		timer(int delay, int divider);

int	animation(t_game *game)
{
	sprite_exit(game);
	if ((*game).nbr_tig == 1)
		anim_tig(game);
	return (0);
}

int	get_diff_ms(nsec nano, nsec t0)
{
	int	ms;

	// printf("nano %ld\n", nano.tv_nsec);
	// printf("t0 %ld\n", t0.tv_nsec);
	// printf("sec %ld\n", nano.tv_sec);
	// printf("t0 sec %ld\n", t0.tv_sec);
	ms = (nano.tv_nsec - t0.tv_nsec) / 1000000;
	// printf("ms %d\n", ms);
	ms = (nano.tv_sec - t0.tv_sec) * 1000 + ms;
	// printf("ms %d\n", ms);
	return (ms);
}

int	sprite_exit(t_game *game)
{
	nsec	t1;

	clock_gettime(CLOCK_MONOTONIC, &t1);
	if (get_diff_ms(t1, (*game).t0) < 200 || (*game).open == 1)
		return (0);
	else
	{
		(*game).t0 = t1;
		if ((*game).exit_frame == 0)
		{
			mlx_put_image_to_window((*game).mlx, (*game).mlx_win,
				(*game).imgE1a.xpm, (*game).exit.j * IMG_W, (*game).exit.i
				* IMG_H);
			(*game).exit_frame = 1;
		}
		else if ((*game).exit_frame == 1)
		{
			mlx_put_image_to_window((*game).mlx, (*game).mlx_win,
				(*game).imgE1b.xpm, (*game).exit.j * IMG_W, (*game).exit.i
				* IMG_H);
			(*game).exit_frame = 2;
		}
		else if ((*game).exit_frame == 2)
		{
			mlx_put_image_to_window((*game).mlx, (*game).mlx_win,
				(*game).imgE1c.xpm, (*game).exit.j * IMG_W, (*game).exit.i
				* IMG_H);
			(*game).exit_frame = 3;
		}
		else
		{
			mlx_put_image_to_window((*game).mlx, (*game).mlx_win,
				(*game).imgE1d.xpm, (*game).exit.j * IMG_W, (*game).exit.i
				* IMG_H);
			(*game).exit_frame = 0;
		}
	}
	return (0);
}

