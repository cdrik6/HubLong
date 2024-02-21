/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 00:37:24 by caguillo          #+#    #+#             */
/*   Updated: 2024/02/21 00:39:10 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	load_image(t_game *game)
{
	(*game).imgc00.xpm = mlx_xpm_file_to_image((*game).mlx, C00,
			&((*game).imgc00.w), &((*game).imgc00.h));
	(*game).imgc01.xpm = mlx_xpm_file_to_image((*game).mlx, C01,
			&((*game).imgc01.w), &((*game).imgc01.h));
	(*game).imgc02.xpm = mlx_xpm_file_to_image((*game).mlx, C02,
			&((*game).imgc02.w), &((*game).imgc02.h));
	(*game).imgc03.xpm = mlx_xpm_file_to_image((*game).mlx, C03,
			&((*game).imgc03.w), &((*game).imgc03.h));
	(*game).imgc04.xpm = mlx_xpm_file_to_image((*game).mlx, C04,
			&((*game).imgc04.w), &((*game).imgc04.h));
	(*game).imgc05.xpm = mlx_xpm_file_to_image((*game).mlx, C05,
			&((*game).imgc05.w), &((*game).imgc05.h));
	(*game).imgc06.xpm = mlx_xpm_file_to_image((*game).mlx, C06,
			&((*game).imgc06.w), &((*game).imgc06.h));
	(*game).imgc07.xpm = mlx_xpm_file_to_image((*game).mlx, C07,
			&((*game).imgc07.w), &((*game).imgc07.h));
	(*game).imgc08.xpm = mlx_xpm_file_to_image((*game).mlx, C08,
			&((*game).imgc08.w), &((*game).imgc08.h));
	(*game).img0.xpm = mlx_xpm_file_to_image((*game).mlx, FLOOR,
			&((*game).img0.w), &((*game).img0.h));
	(*game).img1.xpm = mlx_xpm_file_to_image((*game).mlx, WALL,
			&((*game).img1.w), &((*game).img1.h));
	load_image2(game);
}

void	load_image2(t_game *game)
{
	(*game).imge0.xpm = mlx_xpm_file_to_image((*game).mlx, EXIT0,
			&((*game).imge0.w), &((*game).imge0.h));
	(*game).imge1a.xpm = mlx_xpm_file_to_image((*game).mlx, EXIT1A,
			&((*game).imge1a.w), &((*game).imge1a.h));
	(*game).imge1b.xpm = mlx_xpm_file_to_image((*game).mlx, EXIT1B,
			&((*game).imge1b.w), &((*game).imge1b.h));
	(*game).imge1c.xpm = mlx_xpm_file_to_image((*game).mlx, EXIT1C,
			&((*game).imge1c.w), &((*game).imge1c.h));
	(*game).imge1d.xpm = mlx_xpm_file_to_image((*game).mlx, EXIT1D,
			&((*game).imge1d.w), &((*game).imge1d.h));
	(*game).imgpu.xpm = mlx_xpm_file_to_image((*game).mlx, P_UP,
			&((*game).imgpu.w), &((*game).imgpu.h));
	(*game).imgpd.xpm = mlx_xpm_file_to_image((*game).mlx, P_DOWN,
			&((*game).imgpd.w), &((*game).imgpd.h));
	(*game).imgpl.xpm = mlx_xpm_file_to_image((*game).mlx, P_LEFT,
			&((*game).imgpl.w), &((*game).imgpl.h));
	(*game).imgpr.xpm = mlx_xpm_file_to_image((*game).mlx, P_RIGHT,
			&((*game).imgpr.w), &((*game).imgpr.h));
	(*game).imgtr.xpm = mlx_xpm_file_to_image((*game).mlx, TIGR,
			&((*game).imgtr.w), &((*game).imgtr.h));
}

void	load_tab_image(t_game *game)
{
	(*game).tab_img[0] = (*game).imgc00.xpm;
	(*game).tab_img[1] = (*game).imgc01.xpm;
	(*game).tab_img[2] = (*game).imgc02.xpm;
	(*game).tab_img[3] = (*game).imgc03.xpm;
	(*game).tab_img[4] = (*game).imgc04.xpm;
	(*game).tab_img[5] = (*game).imgc05.xpm;
	(*game).tab_img[6] = (*game).imgc06.xpm;
	(*game).tab_img[7] = (*game).imgc07.xpm;
	(*game).tab_img[8] = (*game).imgc08.xpm;
	(*game).tab_img[9] = (*game).img0.xpm;
	(*game).tab_img[10] = (*game).img1.xpm;
	(*game).tab_img[11] = (*game).imge0.xpm;
	(*game).tab_img[12] = (*game).imge1a.xpm;
	(*game).tab_img[13] = (*game).imge1b.xpm;
	(*game).tab_img[14] = (*game).imge1c.xpm;
	(*game).tab_img[15] = (*game).imge1d.xpm;
	(*game).tab_img[16] = (*game).imgpu.xpm;
	(*game).tab_img[17] = (*game).imgpd.xpm;
	(*game).tab_img[18] = (*game).imgpl.xpm;
	(*game).tab_img[19] = (*game).imgpr.xpm;
	(*game).tab_img[20] = (*game).imgtr.xpm;
}

int	check_tab_image(t_game *game)
{
	int	i;
	int	is_null;

	is_null = 0;
	i = 0;
	while (i < IMG_NBR)
	{
		if (!(*game).tab_img[i])
			is_null++;
		i++;
	}
	return (is_null);
}

void	destroy_tab_image(t_game *game)
{
	int	i;

	i = 0;
	while (i < IMG_NBR)
	{
		if ((*game).tab_img[i])
			mlx_destroy_image((*game).mlx, (*game).tab_img[i]);
		i++;
	}
}
