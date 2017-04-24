#include "../../header/includes.h"

void        ft_loop_light_init(t_global *g)
{
    g->current_light = g->my_scene->lights[g->j];
	g->dist = vector_sub(&g->current_light.pos, &g->new_start);
}

int			ft_loop_shadow_init(t_global *g, int k)
{
	g->light_ray.start = g->new_start;
	g->light_ray.dir = vector_scale((1/g->t), &g->dist);
    k = 0;
	return (k);
}
	
void    	ft_lambert(t_global *g)
{
	/* Lambert diffusion */
	g->lambert = vector_dot(&g->light_ray.dir, &g->n) * g->coef; 
	g->color.red += g->lambert * g->current_light.intensity.red * g->current_mat.diffuse.red;
	g->color.green += g->lambert * g->current_light.intensity.green * g->current_mat.diffuse.green;
	g->color.blue += g->lambert * g->current_light.intensity.blue * g->current_mat.diffuse.blue;
}