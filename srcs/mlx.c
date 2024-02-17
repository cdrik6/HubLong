/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 20:00:45 by caguillo          #+#    #+#             */
/*   Updated: 2024/02/17 02:49:55 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_game(t_game *game)
{
	destroy_image(game);
	mlx_destroy_window((*game).mlx, (*game).mlx_win);
	mlx_destroy_display((*game).mlx);
	free((*game).mlx);
	free_map((*game).map, (*game).rows);
	exit(0);
}

int	init_mlx(t_game *game)
{
	(*game).mlx = mlx_init();
	if (!(*game).mlx)
		return (error_msg(6), 0);
	if (check_size_map(game) == 1)
	{
		(*game).mlx_win = mlx_new_window((*game).mlx, (*game).cols * IMG_W,
				(*game).rows * IMG_H, "So Long");
		if (!(*game).mlx_win)
		{
			mlx_destroy_display((*game).mlx);
			free((*game).mlx);
			return (error_msg(8), 0);
		}
		image_loader(game);
		draw_init_map(game); /******************/
		(*game).mvt = 0;
		print_mvt(game);
		mlx_hook((*game).mlx_win, KeyPress, KeyPressMask, handle_input, game);
		mlx_hook((*game).mlx_win, DestroyNotify, NoEventMask, x_close, game);
		mlx_loop((*game).mlx);
	}
	return (0);
}

int	check_size_map(t_game *game)
{
	int	screen_w;
	int	screen_h;

	mlx_get_screen_size((*game).mlx, &screen_w, &screen_h);
	if ((*game).cols * IMG_W > screen_w || (*game).rows * IMG_H > screen_h)
	{
		error_msg(7);
		mlx_destroy_display((*game).mlx);
		free((*game).mlx);
		return (0);
		// free_map((*game).map, (*game).rows);
		// exit(0);
	}
	return (1);
}

void	draw_init_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < (*game).rows)
	{
		j = 0;
		while (j < (*game).cols)
		{
			// printf("i%d / j%d\n", i, j);
			init_image_on_map(game, i, j);
			j++;
		}
		i++;
	}
}

void	image_loader(t_game *game)
{
	load_image(game);
	load_tab_image(game);
	if (check_tab_image(game) != 0)
	{
		error_msg(9);
		destroy_tab_image(game);
		mlx_destroy_window((*game).mlx, (*game).mlx_win);
		mlx_destroy_display((*game).mlx);
		free((*game).mlx);
		free_map((*game).map, (*game).rows);
		exit(0);
	}
}

void	load_image(t_game *game)
{
	(*game).img0.xpm = mlx_xpm_file_to_image((*game).mlx, FLOOR,
			&((*game).img0.w), &((*game).img0.h));
	(*game).img1.xpm = mlx_xpm_file_to_image((*game).mlx, WALL,
			&((*game).img1.w), &((*game).img1.h));
	(*game).imgC00.xpm = mlx_xpm_file_to_image((*game).mlx, C00,
			&((*game).imgC00.w), &((*game).imgC00.h));
	(*game).imgC01.xpm = mlx_xpm_file_to_image((*game).mlx, C01,
			&((*game).imgC01.w), &((*game).imgC01.h));
	(*game).imgC02.xpm = mlx_xpm_file_to_image((*game).mlx, C02,
			&((*game).imgC02.w), &((*game).imgC02.h));
	(*game).imgC03.xpm = mlx_xpm_file_to_image((*game).mlx, C03,
			&((*game).imgC03.w), &((*game).imgC03.h));
	(*game).imgE0.xpm = mlx_xpm_file_to_image((*game).mlx, EXIT0,
			&((*game).imgE0.w), &((*game).imgE0.h));
	(*game).imgE1.xpm = mlx_xpm_file_to_image((*game).mlx, EXIT1,
			&((*game).imgE1.w), &((*game).imgE1.h));
	(*game).imgPu.xpm = mlx_xpm_file_to_image((*game).mlx, P_UP,
			&((*game).imgPu.w), &((*game).imgPu.h));
	(*game).imgPd.xpm = mlx_xpm_file_to_image((*game).mlx, P_DOWN,
			&((*game).imgPd.w), &((*game).imgPd.h));
	(*game).imgPl.xpm = mlx_xpm_file_to_image((*game).mlx, P_LEFT,
			&((*game).imgPl.w), &((*game).imgPl.h));
	(*game).imgPr.xpm = mlx_xpm_file_to_image((*game).mlx, P_RIGHT,
			&((*game).imgPr.w), &((*game).imgPr.h));
}

void	load_tab_image(t_game *game)
{
	(*game).tab_img[0] = (*game).img0.xpm;
	(*game).tab_img[1] = (*game).img1.xpm;
	(*game).tab_img[2] = (*game).imgC00.xpm;
	(*game).tab_img[3] = (*game).imgC01.xpm;
	(*game).tab_img[4] = (*game).imgC02.xpm;
	(*game).tab_img[5] = (*game).imgC03.xpm;
	(*game).tab_img[6] = (*game).imgE0.xpm;
	(*game).tab_img[7] = (*game).imgE1.xpm;
	(*game).tab_img[8] = (*game).imgPu.xpm;
	(*game).tab_img[9] = (*game).imgPd.xpm;
	(*game).tab_img[10] = (*game).imgPl.xpm;
	(*game).tab_img[11] = (*game).imgPr.xpm;
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

void	destroy_image(t_game *game)
{
	mlx_destroy_image((*game).mlx, (*game).img0.xpm);
	mlx_destroy_image((*game).mlx, (*game).img1.xpm);
	mlx_destroy_image((*game).mlx, (*game).imgC00.xpm);
	mlx_destroy_image((*game).mlx, (*game).imgC01.xpm);
	mlx_destroy_image((*game).mlx, (*game).imgC02.xpm);
	mlx_destroy_image((*game).mlx, (*game).imgC03.xpm);
	mlx_destroy_image((*game).mlx, (*game).imgE0.xpm);
	mlx_destroy_image((*game).mlx, (*game).imgE1.xpm);
	mlx_destroy_image((*game).mlx, (*game).imgPu.xpm);
	mlx_destroy_image((*game).mlx, (*game).imgPd.xpm);
	mlx_destroy_image((*game).mlx, (*game).imgPr.xpm);
	mlx_destroy_image((*game).mlx, (*game).imgPl.xpm);
}

void	init_image_on_map(t_game *game, int i, int j)
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

void	init_C_image_on_map(t_game *game, int i, int j)
{
	if ((*game).temp_c % 4 == 1)
		mlx_put_image_to_window((*game).mlx, (*game).mlx_win,
			(*game).imgC01.xpm, j * IMG_W, i * IMG_H);
	if ((*game).temp_c % 4 == 2)
		mlx_put_image_to_window((*game).mlx, (*game).mlx_win,
			(*game).imgC02.xpm, j * IMG_W, i * IMG_H);
	if ((*game).temp_c % 4 == 3)
		mlx_put_image_to_window((*game).mlx, (*game).mlx_win,
			(*game).imgC03.xpm, j * IMG_W, i * IMG_H);
	if ((*game).temp_c % 4 == 0)
		mlx_put_image_to_window((*game).mlx, (*game).mlx_win,
			(*game).imgC00.xpm, j * IMG_W, i * IMG_H);
	(*game).temp_c--;
}

int	handle_input(int keysym, t_game *game)
{
	// printf("%d\n", keysym);
	if (keysym == KEY_ESC || keysym == KEY_Q)
		free_game(game);
	if (keysym == KEY_UP || keysym == KEY_W)
		move(game, -1, 0, (*game).imgPu.xpm);
	if (keysym == KEY_DOWN || keysym == KEY_S)
		move(game, 1, 0, (*game).imgPd.xpm);
	if (keysym == KEY_LEFT || keysym == KEY_A)
		move(game, 0, -1, (*game).imgPl.xpm);
	if (keysym == KEY_RIGHT || keysym == KEY_D)
		move(game, 0, 1, (*game).imgPr.xpm);
	return (0);
}

int	x_close(t_game *game)
{
	free_game(game);
	return (0);
}

void	move(t_game *game, int k, int m, void *xpm)
{
	int	i;
	int	j;

	i = (*game).player.i + k;
	j = (*game).player.j + m;
	if ((*game).map[i][j] == 'C')
		open_exit(game);
	if ((*game).map[i][j] == 'E' && (*game).open == 1)
	{
		(*game).map[(*game).player.i][(*game).player.j] = '0';
		replace_image(game, (*game).player.i, (*game).player.j, xpm);
		(*game).player.i = i;
		(*game).player.j = j;
		(*game).mvt++;
		print_mvt(game);
		game_win(game);
	}
	else if ((*game).map[i][j] != '1' && (*game).map[i][j] != 'E')
	{
		(*game).map[(*game).player.i][(*game).player.j] = '0';
		replace_image(game, (*game).player.i, (*game).player.j, xpm);
		(*game).player.i = i;
		(*game).player.j = j;
		(*game).mvt++;
		print_mvt(game);
		(*game).map[(*game).player.i][(*game).player.j] = 'P';
		replace_image(game, (*game).player.i, (*game).player.j, xpm);
	}
	else
		replace_image(game, (*game).player.i, (*game).player.j, xpm);
}

void	open_exit(t_game *game)
{
	(*game).nbr_c--;
	if ((*game).nbr_c == 0)
	{
		(*game).open = 1;
		mlx_put_image_to_window((*game).mlx, (*game).mlx_win, (*game).imgE0.xpm,
			(*game).exit.j * IMG_W, (*game).exit.i * IMG_H);
	}
}

void	game_win(t_game *game)
{
	ft_putstr_fd("Welcome at 42!\n", 1);
	ft_putstr_fd("To got in the school you needed ", 1);
	ft_putnbr_fd((*game).mvt, 1);
	ft_putstr_fd(" movements... so long !\n", 1);
	free_game(game);
}

void	replace_image(t_game *game, int i, int j, void *xpm)
{
	if ((*game).map[i][j] == '0')
		mlx_put_image_to_window((*game).mlx, (*game).mlx_win, (*game).img0.xpm,
			j * IMG_W, i * IMG_H);
	if ((*game).map[i][j] == 'P')
		mlx_put_image_to_window((*game).mlx, (*game).mlx_win, xpm, j * IMG_W, i
			* IMG_H);
}

void	print_mvt(t_game *game)
{
	char	*nbr;
	char	*str;

	nbr = ft_itoa((*game).mvt);
	str = lib_strjoin("Movements: ", nbr);
	mlx_put_image_to_window((*game).mlx, (*game).mlx_win, (*game).img1.xpm, 0
		* IMG_W, 0 * IMG_H);
	mlx_put_image_to_window((*game).mlx, (*game).mlx_win, (*game).img1.xpm, 1
		* IMG_W, 0 * IMG_H);
	mlx_put_image_to_window((*game).mlx, (*game).mlx_win, (*game).img1.xpm, 2
		* IMG_W, 0 * IMG_H);
	mlx_string_put((*game).mlx, (*game).mlx_win, 0, IMG_H / 2, 0xFFFFFF, str);
	free(nbr);
	free(str);
}
