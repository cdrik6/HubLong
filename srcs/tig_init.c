/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tig_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 23:44:18 by caguillo          #+#    #+#             */
/*   Updated: 2024/02/20 23:54:16 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	nbr_tig_on_map(t_game *game)
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
	return ((*game).nbr_tig);
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
						(*game).imgtr.xpm, j * IMG_W, i * IMG_H);
					return (1);
				}
				j++;
			}
			i++;
		}
	}
	return (0);
}
