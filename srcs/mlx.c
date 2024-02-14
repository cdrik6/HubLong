/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 20:00:45 by caguillo          #+#    #+#             */
/*   Updated: 2024/02/15 00:26:17 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_game(t_game *game);

int	init_mlx(t_game *game)
{
	(*game).mlx = mlx_init();
	if ((*game).mlx == NULL)
		return (0); /************/
	(*game).mlx_win = mlx_new_window((*game).mlx, (*game).cols * IMG_W,
			(*game).rows * IMG_H, "So Long");
	if ((*game).mlx_win == NULL)
	{
		free_game(game);
		return (0); /***************/
	}
	load_image(game);
	draw_init_map(game);
	// mlx_key_hook((*game).mlx_win, handle_input, game);
	// mlx_hook((*game).mlx_win, 2, 1L<<0, handle_input, game);
	mlx_hook((*game).mlx_win, KeyPress, KeyPressMask, handle_input, game);
	mlx_hook((*game).mlx_win, 17, 0, cross_close, game);
	// mlx_loop_hook((*game).mlx, change_color, game);
	//
	// (*game).img.img = mlx_new_image((*game).mlx, 400, 400);
	// (*game).img.addr = mlx_get_data_addr((*game).img.img, &(*game).img.bpp,
	// 		&(*game).img.line_len, &(*game).img.endian);
	//
	// mlx_key_hook((*game).mlx_win, f, game);
	mlx_loop((*game).mlx);
	return (0);
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

/********************** load issue, could be NULL **********************/
void	load_image(t_game *game)
{
	(*game).img0.xpm = mlx_xpm_file_to_image((*game).mlx, FLOOR,
			&((*game).img0.w), &((*game).img0.h));
	(*game).img1.xpm = mlx_xpm_file_to_image((*game).mlx, WALL,
			&((*game).img1.w), &((*game).img1.h));
	(*game).imgC.xpm = mlx_xpm_file_to_image((*game).mlx, COLL,
			&((*game).imgC.w), &((*game).imgC.h));
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

void	destroy_image(t_game *game)
{
	mlx_destroy_image((*game).mlx, (*game).img0.xpm);
	mlx_destroy_image((*game).mlx, (*game).img1.xpm);
	mlx_destroy_image((*game).mlx, (*game).imgC.xpm);
	mlx_destroy_image((*game).mlx, (*game).imgE0.xpm);
	mlx_destroy_image((*game).mlx, (*game).imgE1.xpm);
	mlx_destroy_image((*game).mlx, (*game).imgPu.xpm);
	mlx_destroy_image((*game).mlx, (*game).imgPd.xpm);
	mlx_destroy_image((*game).mlx, (*game).imgPr.xpm);
	mlx_destroy_image((*game).mlx, (*game).imgPl.xpm);
}

void	init_image_on_map(t_game *game, int i, int j)
{
	if ((*game).map[i][j] == '1')
		mlx_put_image_to_window((*game).mlx, (*game).mlx_win, (*game).img1.xpm,
			j * IMG_W, i * IMG_H);
	if ((*game).map[i][j] == '0')
		mlx_put_image_to_window((*game).mlx, (*game).mlx_win, (*game).img0.xpm,
			j * IMG_W, i * IMG_H);
	if ((*game).map[i][j] == 'C')
		mlx_put_image_to_window((*game).mlx, (*game).mlx_win, (*game).imgC.xpm,
			j * IMG_W, i * IMG_H);
	if ((*game).map[i][j] == 'E')
		mlx_put_image_to_window((*game).mlx, (*game).mlx_win, (*game).imgE1.xpm,
			j * IMG_W, i * IMG_H);
	(*game).open = 0;
	// if ((*game).map[i][j] == 'E' && (*game).nbr_c == 0)
	// 	mlx_put_image_to_window((*game).mlx, (*game).mlx_win, (*game).imgE0.xpm,
	// 		j * IMG_W, i * IMG_H);
	if ((*game).map[i][j] == 'P')
		mlx_put_image_to_window((*game).mlx, (*game).mlx_win, (*game).imgPr.xpm,
			j * IMG_W, i * IMG_H);
}

void	free_game(t_game *game)
{
	destroy_image(game);
	mlx_destroy_window((*game).mlx, (*game).mlx_win);
	mlx_destroy_display((*game).mlx);
	free((*game).mlx);
	free_map((*game).map, (*game).rows);
	exit(0);
}

int	handle_input(int keysym, t_game *game)
{
	printf("%d\n", keysym);
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

int	cross_close(t_game *game)
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
	{
		(*game).nbr_c++;
		// open_exit(game);
	}
	if ((*game).map[i][j] == 'E' && (*game).open == 1)
	{
		// before
		(*game).map[(*game).player.i][(*game).player.j] = '0';
		replace_image(game, (*game).player.i, (*game).player.j, xpm);
		// after
		(*game).player.i = i;
		(*game).player.j = j;
		(*game).map[(*game).player.i][(*game).player.j] = 'P';
		replace_image(game, (*game).player.i, (*game).player.j, xpm); //***/
																		// game_win(game);
	}
	else if ((*game).map[i][j] != '1' && (*game).map[i][j] != 'E')
	{
		// before
		(*game).map[(*game).player.i][(*game).player.j] = '0';
		replace_image(game, (*game).player.i, (*game).player.j, xpm);
		// after
		(*game).player.i = i;
		(*game).player.j = j;
		(*game).map[(*game).player.i][(*game).player.j] = 'P';
		replace_image(game, (*game).player.i, (*game).player.j, xpm);
	}
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

/*
void	color_screen(t_game *game, int color)
{
	for (int y = 0; y < 400; ++y)
	{
		for (int x = 0; x < 400; ++x)
		{
			// mlx_pixel_put((*game).mlx, (*game).mlx_win, x, y, color);
			my_mlx_pixel_put(&(*game).img, x, y, color);
		}
	}
}

int	encode_rgb(byte red, byte green, byte blue)
{
	return (red << 16 | green << 8 | blue);
}

int	f(int keysym, t_game *game)
{
	if (keysym == XK_r)
		color_screen(game, encode_rgb(255, 0, 0));
	else if (keysym == XK_g)
		color_screen(game, encode_rgb(0, 255, 0));
	else if (keysym == XK_b)
		color_screen(game, encode_rgb(0, 0, 255));
	else if (keysym == XK_Escape)
		exit(1);
	mlx_put_image_to_window((*game).mlx, (*game).mlx_win, (*game).img.img, 0,
		0);
	return (0);
}


void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = (*data).addr + (y * (*data).line_len + x * ((*data).bpp / 8));
	*(unsigned int *)dst = color;
}
*/

/*
int	change_color(t_game *game)
{
	mlx_string_put((*game).mlx, (*game).mlx_win, 150, 150, (*game).color,
		"FUCK");
	if ((*game).color == 0xFF0000)
		(*game).color = 0x00FF00;
	else if ((*game).color == 0x00FF00)
		(*game).color = 0x0000FF;
	else
		(*game).color = 0xFF0000;
	return (0);
}

int	f(int keysym, t_game *game)
{
	if (keysym == XK_r)
		color_screen(game, encode_rgb(255, 0, 0));
	if (keysym == XK_g)
		color_screen(game, encode_rgb(0, 255, 0));
	if (keysym == XK_b)
		color_screen(game, encode_rgb(0, 0, 255));
	return (0);
}

*/