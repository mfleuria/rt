#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

#include "../header/includes.h"

void		mat_diffuse(int mat_index, char *line, char **line2, scene *myscene)
{
	int		i;

	i = 0;
	line = ft_strchr(line, '=');
	line++;
	line2 = ft_strsplit(line, ',');
	myscene->materials[mat_index].diffuse.red = ft_atof(line2[0]);
	myscene->materials[mat_index].diffuse.green = ft_atof(line2[1]);
	myscene->materials[mat_index].diffuse.blue = ft_atof(line2[2]);
	while (line2[i] != NULL)
	{
		ft_putstr(" Diffuse: ");
		ft_putfnbr(ft_atof(line2[i]));
		i++;
	}
}

void		mat_reflec(int mat_index, char *line, scene *myscene)
{
	line = ft_strchr(line, '=');
	line++;
	myscene->materials[mat_index].reflection = ft_atof(line);
	ft_putstr(" Reflection: ");
	ft_putfnbr(myscene->materials[mat_index].reflection);
}
