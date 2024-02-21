#include "../minilibx-linux/mlx.h"
#include <X11/X.h>
#include <X11/keysym.h>
#include <stdio.h>

typedef struct s_toto
{   
	void	*xpm;
	int		x;
	int		y;
	int		w;
	int		h;

}			t_toto;
int			render_next_frame(t_toto *img);

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_toto	img;

	img = (t_toto){0};
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 200, 200, "Anim");
	img.xpm = mlx_xpm_file_to_image(mlx, "images/floor.xpm", &img.w, &img.h);
	img.x = 0;
	img.y = 100;
	mlx_loop_hook(mlx, render_next_frame, &img);
	mlx_loop(mlx);
}

int	render_next_frame(t_toto *img)
{
	printf("toto\n");
	(*img).x++;
}
