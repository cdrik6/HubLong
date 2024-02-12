/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx tuto.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 20:00:45 by caguillo          #+#    #+#             */
/*   Updated: 2024/02/12 22:54:55 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}			t_data;

typedef unsigned char	byte;

void					my_mlx_pixel_put(t_data *data, int x, int y, int color);
int						handle_input(int keysym, t_game *game);
// int			change_color(t_game *game);
void					color_screen(t_game *game, int color);
int						encode_rgb(byte red, byte green, byte blue);
int						f(int keysym, t_game *game);

int	init_mlx(t_game *game)
{
	(*game).mlx = mlx_init();
	if ((*game).mlx == NULL)
		return (0);
	(*game).mlx_win = mlx_new_window((*game).mlx, 400, 400, "Hello world!");
	if ((*game).mlx_win == NULL)
	{
		mlx_destroy_window((*game).mlx, (*game).mlx_win);
		mlx_destroy_display((*game).mlx);
		free((*game).mlx);
		return (0);
	}
	//(*game).color = 0xFF0000;
	// mlx_key_hook((*game).mlx_win, handle_input, game);
	// mlx_key_hook((*game).mlx_win, f, game);
	// mlx_loop_hook((*game).mlx, change_color, game);
	//
	(*game).img.img = mlx_new_image((*game).mlx, 400, 400);
	(*game).img.addr = mlx_get_data_addr((*game).img.img, &(*game).img.bpp, &(*game).img.line_len, &(*game).img.endian);
	//
	mlx_key_hook((*game).mlx_win, f, game);
	mlx_loop((*game).mlx);
	return (0);
}

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
	mlx_put_image_to_window((*game).mlx, (*game).mlx_win, (*game).img.img, 0, 0);
	return (0);
}

int	handle_input(int keysym, t_game *game)
{
	if (keysym == XK_Escape)
	{
		printf("%d\n", keysym);
		mlx_destroy_window((*game).mlx, (*game).mlx_win);
		mlx_destroy_display((*game).mlx);
		free((*game).mlx);
		free_map((*game).map, (*game).rows);
		exit(1);
	}
	printf("%d\n", keysym);
	sleep(2);
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = (*data).addr + (y * (*data).line_len + x * ((*data).bpp / 8));
	*(unsigned int *)dst = color;
}

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