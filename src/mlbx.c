#include "../header/includes.h"

/* my_key_funct repere les touche du claviers.
** keycode 53 represente la touche echape (pour fermer la fenetre) */

int		my_key_funct(int keycode, t_env *e)
{
	if (keycode == 53)
	{
		mlx_destroy_image(e->mlx, e->img);
		mlx_destroy_window(e->mlx, e->win);
		exit(1);
	}
	return (0);
}

void	init_mlx(t_env *e, scene *my_scene)
{
	e->mlx = mlx_init();
	if (!e->mlx)
	{
		ft_putstr("error: mlx_init");
		exit(1);
	}
	e->win = mlx_new_window(e->mlx, my_scene->width, my_scene->height, "RTv1");
	e->img = mlx_new_image(e->mlx, my_scene->width, my_scene->height);
	e->data = mlx_get_data_addr(e->img, &(e)->bpp, \
		&(e)->size_line, &(e)->endian);
}
