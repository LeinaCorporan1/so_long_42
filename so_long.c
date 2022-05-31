#include "so_long.h"
// #include	"mlx_int.h"

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	// void	*try;

	mlx = mlx_init();
	if (mlx == NULL)
		return (0);
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	if (mlx_win == NULL)
		return (0);
	// try = mlx_xpm_file_to_image(mlx,PLAYER,48,48);
	// mlx_put_image_to_window(mlx,win,)
	mlx_loop(mlx);
}
