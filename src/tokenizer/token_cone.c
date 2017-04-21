#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "../../header/includes.h"

void			cone_mat(int c_index, char *line, scene *sc)
{
	line = ft_strcln(line);
	sc->cone[c_index].material = ft_atoi(line);
	ft_putstr(" Material-cone: ");
	ft_putnbr(sc->cone[c_index].material);
}

void			cone_axis(int c_index, char *line, scene *sc)
{
	char		**line_split;
	int			i;

	i = 0;
	line = ft_strcln(line);
	line_split = ft_strsplit(line, ',');
	ft_putstr(line_split[0]);
	sc->cone[c_index].axis.x = ft_atof(line_split[0]);
	sc->cone[c_index].axis.y = ft_atof(line_split[1]);
	sc->cone[c_index].axis.z = ft_atof(line_split[2]);
	while (line_split[i] != NULL)
	{
		ft_putstr(" axis-cone: ");
		ft_putnbr(ft_atof(line_split[i]));
		i++;
	}
	ft_putchar('\n');
}

void			cone_apex(int c_index, char *line, scene *sc)
{
	char		**line_split;
	int			i;

	i = 0;
	line = ft_strcln(line);
	line_split = ft_strsplit(line, ',');
	ft_putstr(line_split[0]);
	sc->cone[c_index].apex.x = ft_atof(line_split[0]);
	sc->cone[c_index].apex.y = ft_atof(line_split[1]);
	sc->cone[c_index].apex.z = ft_atof(line_split[2]);
	while (line_split[i] != NULL)
	{
		ft_putstr(" apex-cone: ");
		ft_putnbr(ft_atof(line_split[i]));
		i++;
	}
	ft_putchar('\n');
}

void			cone_angle(int c_index, char *line, scene *sc)
{
	line = ft_strcln(line);
	sc->cone[c_index].material = ft_atof(line);
	ft_putstr(" ange-cone: ");
	ft_putnbr(sc->cone[c_index].material);
}
