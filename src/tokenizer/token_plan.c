#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "../../header/includes.h"

void			plan_normal(int p_index, char *line, scene *sc)
{
	char		**line_split;
	int			i;

	i = 0;
	line = ft_strcln(line);
	line_split = ft_strsplit(line, ',');
	sc->plan[p_index].normal.x = ft_atof(line_split[0]);
	sc->plan[p_index].normal.y = ft_atof(line_split[1]);
	sc->plan[p_index].normal.z = ft_atof(line_split[2]);
	while (line_split[i] != NULL)
	{
		ft_putstr(" Normal: ");
		ft_putnbr(ft_atof(line_split[i]));
		i++;
	}
}

void			plan_offset(int p_index, char *line, scene *sc)
{
	line = ft_strcln(line);
	sc->plan[p_index].offset = ft_atof(line);
}

void			plan_mat(int p_index, char *line, scene *sc)
{
	line = ft_strcln(line);
	sc->plan[p_index].material = ft_atoi(line);
	ft_putstr(" Material: ");
	ft_putnbr(sc->plan[p_index].material);
}
