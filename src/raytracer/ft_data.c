#include "../../header/includes.h"

void        ft_data_push(t_global *g)
{
    /* ici on colorie dans la data */
	g->e.data[(g->x * 4) + (g->y * g->e.size_line) + 0] = (unsigned char)min(g->color.red * 255.0f, 255.0f);
	g->e.data[(g->x * 4) + (g->y * g->e.size_line) + 1] = (unsigned char)min(g->color.green * 255.0f, 255.0f);
	g->e.data[(g->x * 4) + (g->y * g->e.size_line) + 2] = (unsigned char)min(g->color.blue * 255.0f, 255.0f);
	g->e.data[(g->x * 4) + (g->y * g->e.size_line) + 3] = 0;
}