#include "../header/includes.h"

int		my_key_funct(int keycode, t_env *e) // fonction qui prend les touches du claviers
{
	if (keycode == 53) // echape : ferme la fenetre
	{
		mlx_destroy_image(e->mlx, e->img);
		mlx_destroy_window(e->mlx, e->win);
		exit(1);
	}
	return (0);
}

void		init_mlx(t_env *e, scene *myScene)
{
	e->mlx = mlx_init();
	if (!e->mlx)
	{
		ft_putstr("error: mlx_init");
		exit(1);
	}
	e->win = mlx_new_window(e->mlx, myScene->width, myScene->height, "RTv1");
	e->img = mlx_new_image(e->mlx, myScene->width, myScene->height);
	e->data = mlx_get_data_addr(e->img, &(e)->bpp, \
		&(e)->size_line, &(e)->endian);
}