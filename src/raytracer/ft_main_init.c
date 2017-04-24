#include "../../header/includes.h"

void        ft_main_init(t_global *g)
{
	g->my_scene = NULL;
	g->mine.materials = NULL;
	g->mine.spheres = NULL;
	g->mine.lights = NULL;
	g->my_scene = &g->mine;
}