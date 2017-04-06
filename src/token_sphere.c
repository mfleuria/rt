#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

#include "../header/includes.h"

void			sphere_pos(int s_index, char *line, scene *sc)
{
	int			i;
	char		**line_split;

	i = 0;
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

void			sphere_rad(int s_index, char *line, scene *sc)
{
	sc->spheres[s_index].radius = ft_atof(line);
	ft_putstr(" Radius: ");
	ft_putnbr(sc->spheres[s_index].radius);
}

void			sphere_mat(int s_index, char *line, scene *sc)
{
	sc->spheres[s_index].material = ft_atoi(line);
	ft_putstr(" Material: ");
	ft_putnbr(sc->spheres[s_index].material);
}
