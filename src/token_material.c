#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

#include "../header/includes.h"

void		mat_diffuse(int m_index, char *line, char **line2, scene *my_scene)
{
	int		i;

	i = 0;
	line = ft_strchr(line, '=');
	line++;
	line2 = ft_strsplit(line, ',');
	my_scene->materials[m_index].diffuse.red = ft_atof(line2[0]);
	my_scene->materials[m_index].diffuse.green = ft_atof(line2[1]);
	my_scene->materials[m_index].diffuse.blue = ft_atof(line2[2]);
	while (line2[i] != NULL)
	{
		ft_putstr(" Diffuse: ");
		ft_putfnbr(ft_atof(line2[i]));
		i++;
	}
}

void		mat_reflec(int m_index, char *line, scene *my_scene)
{
	line = ft_strchr(line, '=');
	line++;
	my_scene->materials[m_index].reflection = ft_atof(line);
	ft_putstr(" Reflection: ");
	ft_putfnbr(my_scene->materials[m_index].reflection);
}
