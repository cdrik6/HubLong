/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 17:40:25 by caguillo          #+#    #+#             */
/*   Updated: 2024/02/20 23:19:12 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	animation(t_game *game)
{
	sprite_exit(game);
	if ((*game).nbr_tig == 1)
		anim_tig(game);
	return (0);
}

// int clock_gettime(clockid_t clk_id, struct timespec *tp);
// struct timespec {
//     time_t tv_sec;  /* seconds */
//     long   tv_nsec; /* nanoseconds */ 1 000 000 000
// };
int	get_diff_ms(t_nsec nano, t_nsec t0)
{
	int	ms;

	ms = (nano.tv_nsec - t0.tv_nsec) / 1000000;
	ms = (nano.tv_sec - t0.tv_sec) * 1000 + ms;
	return (ms);
}

int	sprite_exit(t_game *game)
{
	t_nsec	t1;

	clock_gettime(CLOCK_MONOTONIC, &t1);
	if (get_diff_ms(t1, (*game).t0) < 200 || (*game).open == 1)
		return (0);
	else
	{
		(*game).t0 = t1;
		if ((*game).exit_frame == 0)
			put_frame(game, (*game).imge1a.xpm);
		else if ((*game).exit_frame == 1)
			put_frame(game, (*game).imge1b.xpm);
		else if ((*game).exit_frame == 2)
			put_frame(game, (*game).imge1c.xpm);
		else
			put_frame(game, (*game).imge1d.xpm);
	}
	return (0);
}

void	put_frame(t_game *game, void *xpm)
{
	mlx_put_image_to_window((*game).mlx, (*game).mlx_win, xpm, (*game).exit.j
		* IMG_W, (*game).exit.i * IMG_H);
	(*game).exit_frame++;
	(*game).exit_frame = (*game).exit_frame % 4;
}
