#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

#include "../header/includes.h"

void			sphere_pos(int s_index, char *line, char **line2, scene *sc)
{
	int			i;

	i = 0;
	line = ft_strchr(line, '=');
	line++;
	line2 = ft_strsplit(line, ',');
	sc->spheres[s_index].pos.x = ft_atof(line2[0]);
	sc->spheres[s_index].pos.y = ft_atof(line2[1]);
	sc->spheres[s_index].pos.z = ft_atof(line2[2]);
	while (line2[i] != NULL)
	{
		ft_putstr(" Position: ");
		ft_putnbr(ft_atof(line2[i]));
		i++;
	}
}

void			sphere_rad(int s_index, char *line, scene *sc)
{
	line = ft_strchr(line, '=');
	line++;
	sc->spheres[s_index].radius = ft_atof(line);
	ft_putstr(" Radius: ");
	ft_putnbr(sc->spheres[s_index].radius);
}

void			sphere_mat(int s_index, char *line, scene *sc)
{
	line = ft_strchr(line, '=');
	line++;
	sc->spheres[s_index].material = ft_atoi(line);
	ft_putstr(" Material: ");
	ft_putnbr(sc->spheres[s_index].material);
}
