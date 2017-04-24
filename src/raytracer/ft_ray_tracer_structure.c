#include "../../header/includes.h"

void		ft_raytracer(t_global *g)
{
	int		x;
	int		y;
	int		secu;

	secu = 0;
	ft_main_init(g);
	if (g->argc != 2)
		ft_error(1);
	if (tokenizer(g->file_name, g->my_scene) == -1)
		ft_error(2);
	ft_mlx_init(&g->e, g->my_scene);
	y = 0;
	while (y < g->my_scene->height)
	{
		x = 0;
		while (x < g->my_scene->width)
		{
			ft_color_init(g);
			ft_ray_init(g, x, y);
			ft_loop(g);
			while ((g->coef > 0.0f) && (g->level < 15) && secu == 0)
				secu = ft_loop(g);
			ft_data_push(g);
			x++;
			secu = 0;
		}
		y++;
	}
	ft_mlx_push(g);
}