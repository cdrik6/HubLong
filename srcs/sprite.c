/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 17:40:25 by caguillo          #+#    #+#             */
/*   Updated: 2024/02/20 00:52:45 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// int clock_gettime(clockid_t clk_id, struct timespec *tp);
// struct timespec {
//     time_t tv_sec;  /* seconds */
//     long   tv_nsec; /* nanoseconds */ 1 000 000 000
// };

// int		timer(int delay, int divider);

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
	if (get_diff_ms(t1, (*game).t0) < 500 || (*game).open == 1)
		return (0);
	else
	{
		(*game).t0 = t1;
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

int	sprite_tig(t_game *game)
{
	nsec	t1;

	clock_gettime(CLOCK_MONOTONIC, &t1);
	if (get_diff_ms(t1, (*game).t0) < 500 || (*game).open == 1)
		return (0);
	else
	{
		(*game).t0 = t1;
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



void	init_tig_on_map(t_game *game, int i, int j)
{
	//(*game).open = 0;
	if ((*game).map[i][j] == '1')
		mlx_put_image_to_window((*game).mlx, (*game).mlx_win, (*game).img1.xpm,
			j * IMG_W, i * IMG_H);
	if ((*game).map[i][j] == '0')
		mlx_put_image_to_window((*game).mlx, (*game).mlx_win, (*game).img0.xpm,
			j * IMG_W, i * IMG_H);
	if ((*game).map[i][j] == 'E')
		mlx_put_image_to_window((*game).mlx, (*game).mlx_win, (*game).imgE1.xpm,
			j * IMG_W, i * IMG_H);
	if ((*game).map[i][j] == 'P')
		mlx_put_image_to_window((*game).mlx, (*game).mlx_win, (*game).imgPu.xpm,
			j * IMG_W, i * IMG_H);
	if ((*game).map[i][j] == 'C')
		init_C_image_on_map(game, i, j);
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