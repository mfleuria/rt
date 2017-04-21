#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

#include "../../header/includes.h"

void		cyl_mat(int c_index, char *line, scene *sc)
{
	line = ft_strcln(line);
	sc->cylindre[c_index].material = ft_atoi(line);
	ft_putstr(" Material-cyl: ");
	ft_putnbr(sc->cylindre[c_index].material);
}

void		cyl_axis(int c_index, char *line, scene *sc)
{
	char		**line_split;
	int			i;

	i = 0;
	line = ft_strcln(line);
	line_split = ft_strsplit(line, ',');
	ft_putstr(line_split[0]);
	sc->cylindre[c_index].axis.x = ft_atof(line_split[0]);
	sc->cylindre[c_index].axis.y = ft_atof(line_split[1]);
	sc->cylindre[c_index].axis.z = ft_atof(line_split[2]);
	while (line_split[i] != NULL)
	{
		ft_putstr(" axis-cyl: ");
		ft_putnbr(ft_atof(line_split[i]));
		i++;
	}
	ft_putchar('\n');
}

void		cyl_pos(int c_index, char *line, scene *sc)
{
	char		**line_split;
	int			i;

	i = 0;
	line = ft_strcln(line);
	line_split = ft_strsplit(line, ',');
	sc->cylindre[c_index].pos.x = ft_atof(line_split[0]);
	sc->cylindre[c_index].pos.y = ft_atof(line_split[1]);
	sc->cylindre[c_index].pos.z = ft_atof(line_split[2]);
	while (line_split[i] != NULL)
	{
		ft_putstr(" pos-cyl: ");
		ft_putnbr(ft_atof(line_split[i]));
		i++;
	}
	ft_putchar('\n');
}

void		cyl_radius(int c_index, char *line, scene *sc)
{
	line = ft_strcln(line);
	sc->cylindre[c_index].radius = ft_atof(line);
	ft_putstr(" Radius-cyl: ");
	ft_putnbr(sc->cylindre[c_index].radius);
	ft_putchar('\n');
}
