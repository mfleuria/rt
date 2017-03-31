#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

#include "../header/includes.h"

void			light_pos(int l_index, char *line, char **line2, scene *sc)
{
	int			i;

	i = 0;
	line = ft_strchr(line, '=');
	line++;
	line2 = ft_strsplit(line, ',');
	sc->lights[l_index].pos.x = ft_atof(line2[0]);
	sc->lights[l_index].pos.y = ft_atof(line2[1]);
	sc->lights[l_index].pos.z = ft_atof(line2[2]);
	while (line2[i] != NULL)
	{
		ft_putstr(" Position: ");
		ft_putnbr(ft_atof(line2[i]));
		i++;
	}
}

void			light_col(int l_index, char *line, char **line2, scene *sc)
{
	int			i;

	i = 0;
	line = ft_strchr(line, '=');
	line++;
	line2 = ft_strsplit(line, ',');
	sc->lights[l_index].intensity.red = ft_atof(line2[0]);
	sc->lights[l_index].intensity.green = ft_atof(line2[1]);
	sc->lights[l_index].intensity.blue = ft_atof(line2[2]);
	while (line2[i] != NULL)
	{
		ft_putstr(" Colour: ");
		ft_putnbr(ft_atof(line2[i]));
		i++;
	}
}
