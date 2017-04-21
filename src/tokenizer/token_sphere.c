#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "../../header/includes.h"

/*
** token_sphrer recupere les donnees relative
** au spheres (position, rayon, material)
*/

/*
** sphere_pos stock dans la structure scene
**la position en X, Y, Z d'une sphere
*/

void			sphere_pos(int s_index, char *line, scene *sc)
{
	int			i;
	char		**line_split;

	i = 0;
	line = ft_strcln(line);
	line_split = NULL;
	line_split = ft_strsplit(line, ',');
	sc->spheres[s_index].pos.x = ft_atof(line_split[0]);
	sc->spheres[s_index].pos.y = ft_atof(line_split[1]);
	sc->spheres[s_index].pos.z = ft_atof(line_split[2]);
	while (line_split[i] != NULL)
	{
		ft_putstr(" Position: ");
		ft_putnbr(ft_atof(line_split[i]));
		i++;
	}
}

/*
** sphere_rad stock dans la structure scene le radius d'une sphere
*/

void			sphere_rad(int s_index, char *line, scene *sc)
{
	line = ft_strcln(line);
	sc->spheres[s_index].radius = ft_atof(line);
	ft_putstr(" Radius: ");
	ft_putnbr(sc->spheres[s_index].radius);
}

/*
** sphere_mat stock dans la structure scene le material d'une sphere
*/

void			sphere_mat(int s_index, char *line, scene *sc)
{
	line = ft_strcln(line);
	sc->spheres[s_index].material = ft_atoi(line);
	ft_putstr(" Material: ");
	ft_putnbr(sc->spheres[s_index].material);
}
