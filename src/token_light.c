#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

#include "../header/includes.h"

void			light_pos(int l_index, char *line, scene *sc)
{
	int			i;
	char		**line_split;

	i = 0;
	line_split = NULL;
	line_split = ft_strsplit(line, ',');
	sc->lights[l_index].pos.x = ft_atof(line_split[0]);
	sc->lights[l_index].pos.y = ft_atof(line_split[1]);
	sc->lights[l_index].pos.z = ft_atof(line_split[2]);
	while (line_split[i] != NULL)
	{
		ft_putstr(" Position");
		ft_putnbr(i);
		ft_putstr(": ");
		ft_putnbr(ft_atof(line_split[i]));
		i++;
	}
}

void			light_col(int l_index, char *line, scene *sc)
{
	int			i;
	char		**line_split;
	
	i = 0;
	line_split = NULL;
	line_split = ft_strsplit(line, ',');
	sc->lights[l_index].intensity.red = ft_atof(line_split[0]);
	sc->lights[l_index].intensity.green = ft_atof(line_split[1]);
	sc->lights[l_index].intensity.blue = ft_atof(line_split[2]);
	while (line_split[i] != NULL)
	{
		ft_putstr(" Colour: ");
		ft_putnbr(ft_atof(line_split[i]));
		i++;
	}
}
