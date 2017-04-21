#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "../../header/includes.h"

void		mat_diffuse(int m_index, char *line, scene *my_scene)
{
	int		i;
	char	**line_split;

	i = 0;
	line = ft_strcln(line);
	line_split = NULL;
	line_split = ft_strsplit(line, ',');
	ft_putendl(line_split[0]);
	ft_putendl(line_split[1]);
	ft_putendl(line_split[2]);
	my_scene->materials[m_index].diffuse.red = ft_atof(line_split[0]);
	my_scene->materials[m_index].diffuse.green = ft_atof(line_split[1]);
	my_scene->materials[m_index].diffuse.blue = ft_atof(line_split[2]);
	while (line_split[i] != NULL)
	{
		ft_putstr(" Diffuse: ");
		ft_putfnbr(ft_atof(line_split[i]));
		i++;
	}
}

void		mat_reflec(int m_index, char *line, scene *my_scene)
{
	line = ft_strcln(line);
	my_scene->materials[m_index].reflection = ft_atof(line);
	ft_putstr(" Reflection: ");
	ft_putfnbr(my_scene->materials[m_index].reflection);
}
