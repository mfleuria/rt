#include "../../header/includes.h"

void		ft_mlx_init(t_env *e, scene *my_scene)
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

void		ft_mlx_push(t_global *g)
{
	mlx_put_image_to_window(g->e.mlx, g->e.win, g->e.img, 0, 0);/* on envoi l'image dans la fenetre */
	mlx_hook(g->e.win, 2, 3, my_key_funct, (void *)&g->e); // on recupe les events
	mlx_loop(g->e.mlx);
}