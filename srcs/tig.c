/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tig.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 19:30:16 by caguillo          #+#    #+#             */
/*   Updated: 2024/02/20 21:46:07 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	anim_tig(t_game *game)
{
	nsec	t1;

	clock_gettime(CLOCK_MONOTONIC, &t1);
	if (get_diff_ms(t1, (*game).t_tig) < 1000)
		return (0);
	else
	{
		(*game).t_tig = t1;
		srand(time(0));
		handle_tig(game);
	}
	return (1);
}

int	handle_tig(t_game *game)
{
	int	k;

	k = rand() % 5;	
	if (k == 0)
		move_tig(game, -1, 0, (*game).imgTr.xpm);
	if (k == 1)
		move_tig(game, 1, 0, (*game).imgTr.xpm);
	if (k == 2)
		move_tig(game, 0, -1, (*game).imgTr.xpm);
	if (k == 3)
		move_tig(game, 0, 1, (*game).imgTr.xpm);
	if (k == 4)
		move_tig(game, 3, 3, (*game).imgTr.xpm);
	return (0);
}

void	move_tig(t_game *game, int k, int m, void *xpm)
{
	int	i;
	int	j;

	i = (*game).tig.i + k;
	j = (*game).tig.j + m;
	if (i < (*game).rows && j < (*game).cols)
	{
		if ((*game).map[i][j] == 'P')
			game_lose(game);
		if ((*game).map[i][j] == '0')
		{
			mlx_put_image_to_window((*game).mlx, (*game).mlx_win,
				(*game).img0.xpm, (*game).tig.j * IMG_W, (*game).tig.i * IMG_H);
			(*game).tig.i = i;
			(*game).tig.j = j;
			mlx_put_image_to_window((*game).mlx, (*game).mlx_win, xpm,
				(*game).tig.j * IMG_W, (*game).tig.i * IMG_H);
		}
		else
			handle_tig(game);
	}
	else
		handle_tig(game);
}

void	game_lose(t_game *game)
{
	ft_putstr_fd("So long!\n", 1);
	free_game(game);
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
	if (count < 25)
		(*game).nbr_tig = 0;
	else
		(*game).nbr_tig = 1;
}

int	put_tig_on_center(t_game *game)
{
	(*game).tig.i = (*game).rows / 2;
	(*game).tig.j = (*game).cols / 2;
	if ((*game).map[(*game).tig.i][(*game).tig.j] != '0')
		return (0);
	return (1);
}

int	init_tig_on_map(t_game *game)
{
	int	i;
	int	j;

	if (put_tig_on_center(game) == 0)
	{
		i = 0;
		while (i < (*game).rows)
		{
			j = 0;
			while (j < (*game).cols)
			{
				if ((*game).map[i][j] == '0')
				{
					(*game).tig.i = i;
					(*game).tig.j = j;
					mlx_put_image_to_window((*game).mlx, (*game).mlx_win,
						(*game).imgTr.xpm, j * IMG_W, i * IMG_H);
					return (1);
				}
				j++;
			}
			i++;
		}
	}
	return (0);
}

// srand(time(0));
// i = rand() % (*game).rows;
// j = rand() % (*game).cols;
// time_t	t;
// srand((unsigned)time(&t));

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