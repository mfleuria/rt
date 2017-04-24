#include "../../header/includes.h"

void        ft_ray_init(t_global *g, int x, int y)
{
    g->level = 0;
    g->coef = 1.0;
	g->r.start.x = x;
	g->r.start.y = y;
	g->r.start.z = -2000;
	g->r.dir.x = 0;
	g->r.dir.y = 0;
	g->r.dir.z = 1;

}