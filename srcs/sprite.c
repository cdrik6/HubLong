/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 17:40:25 by caguillo          #+#    #+#             */
/*   Updated: 2024/02/20 03:35:52 by caguillo         ###   ########.fr       */
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
		else
		{
			mlx_put_image_to_window((*game).mlx, (*game).mlx_win,
				(*game).imgE1c.xpm, (*game).exit.j * IMG_W, (*game).exit.i
				* IMG_H);
			(*game).exit_frame = 0;
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
				(*game).imgE1a.xpm, (*game).exit.j * IMG_W, (*game).exit.i
				* IMG_H);
			(*game).exit_frame = 1;
		}
		else
		{
			(*game).exit_frame = 0;
			mlx_put_image_to_window((*game).mlx, (*game).mlx_win,
				(*game).imgE1b.xpm, (*game).exit.j * IMG_W, (*game).exit.i
				* IMG_H);
		}
	}
	return (0);
}

void	nbr_tig_on_map(t_game *game)
{
	int	count;
	int	i;
	int	j;

	count = 0;
	i = 0;
	while (i < (*game).rows)
	{
		j = 0;
		while (j < (*game).cols)
		{
			if ((*game).map[i][j] == '0')
				count++;
			j++;
		}
		i++;
	}
	if (count < 5)
		(*game).nbr_tig = 0;
	else if (count < 25)
		(*game).nbr_tig = 1;
	else
		(*game).nbr_tig = 2;
}

void	init_tig_on_map(t_game *game)
{
	int	i;
	int	j;

	srand(time(0));
	i = rand() % (*game).rows;
	j = rand() % (*game).cols;
	if ((*game).map[i][j] == '0')
		mlx_put_image_to_window((*game).mlx, (*game).mlx_win, (*game).imgTr.xpm,
			j * IMG_W, i * IMG_H);
	else if 
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