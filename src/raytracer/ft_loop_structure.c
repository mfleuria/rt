#include "../../header/includes.h"

static void	ft_loop_shadow(t_global *g)
{
	bool 	in_shadow;
	int 	k;

	in_shadow = FALSE;
	k = 0;
	k = ft_loop_shadow_init(g, k);
	while (k < g->nb_sphere)
    {
	    if (intersect_ray_sphere(&g->light_ray, &g->my_scene->spheres[k], &g->t))
        {
	        in_shadow = TRUE;
			break;
		}
	}
	if (in_shadow)
		ft_lambert(g);
}

static void	ft_loop_light(t_global *g)
{
		ft_loop_light_init(g);
		if (!(vector_dot(&g->n, &g->dist) <= 0.0f))
		{
			g->t = sqrtf(vector_dot(&g->dist,&g->dist));
			if (!(g->t <= 0.0f))
			{
				ft_loop_shadow(g);
			}
		}
}

int			ft_loop(t_global *g)
{
	ft_loop_init(g);
	while (g->i < g->nb_sphere)
	{
		ft_loop_sphere(g);
		g->i++;
	}
	if (g->current_sphere == -1)
		return (1);
	ft_loop_vec(g);
	if (g->temp == 0)
		return (1);
	ft_loop_normal(g);
	g->j = 0;
	while (g->j < 3)
	{
		ft_loop_light(g);
		g->j++;
	}
	ft_loop_reflexion(g);
	return (0);
}
