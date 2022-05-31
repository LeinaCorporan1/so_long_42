#include <stdlib.h>
#include "so_long.h"

int main(void)
{
	void	*mlx_ptr;

	mlx_ptr = mlx_init();
	if (mlx_ptr == NULl)
		return 0;
	mlx_destroy_display(mlx_ptr);
	free(mlx_ptr);
}