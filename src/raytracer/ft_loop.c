#include "../../header/includes.h"

void                ft_loop_init(t_global *g)
{
	g->t = 20000.0f;
	g->current_sphere = -1;
    g->i = 0;
}

void            ft_loop_sphere(t_global *g)
{
    if(intersect_ray_sphere(&g->r, &g->my_scene->spheres[g->i], &g->t))
    	g->current_sphere = g->i;
}

void            ft_loop_vec(t_global *g)
{
    g->scaled = vector_scale(g->t, &g->r.dir);
	g->new_start = vector_add(&g->r.start, &g->scaled);

	/* Find the normal for this new vector at the point of intersection */
	g->n = vector_sub(&g->new_start, &g->my_scene->spheres[g->current_sphere].pos);
	g->temp = vector_dot(&g->n, &g->n);
}

void            ft_loop_normal(t_global *g)
{
    g->temp = 1.0f / sqrtf(g->temp);
	g->n = vector_scale(g->temp, &g->n);

	/* Find the material to determine the colour */
	g->current_mat = g->my_scene->materials[g->my_scene->spheres[g->current_sphere].material];
}

void			ft_loop_reflexion(t_global *g)
{
				/* Iterate over the reflection */
	g->coef *= g->current_mat.reflection;

	/* The reflected ray start and direction */
	g->r.start = g->new_start;
	g->reflect = 2.0f * vector_dot(&g->r.dir, &g->n);
	g->tmp = vector_scale(g->reflect, &g->n);
	g->r.dir = vector_sub(&g->r.dir, &g->tmp);

	g->level++;
}