#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "../../header/includes.h"

/*
** token_detect dispatche les elements du fichier
** au differentes fonctions permettant la recuperation
** des donnees pour chaque element
*/

/*
** detect_light detecte l'element light
*/

static int		detect_light(int fd, char *line, scene *sc)
{
	static int	light_index = 0;
	char		**line_split;

	line_split = NULL;
	if (light_index < sc->num_lights)
	{
		while (line[0] != '}')
		{
			get_next_line(fd, &line);
			line_split = ft_strsplit(line, ' ');
			if (ft_len_tab(line_split) == 3)
			{
				if (ft_strchrstr(line_split[0], "position") == 0)
					light_pos(light_index, line_split[2], sc);
				if (ft_strchrstr(line_split[0], "colour") == 0)
					light_col(light_index, line_split[2], sc);
			}
			else if (line_split[0][0] != '}')
				return (-1);
		}
	}
	else
		return (-1);
	light_index++;
	return (0);
}

/*
** detect_mat detecte l'element Material
*/

static int		detect_mat(int fd, char *line, scene *sc)
{
	static int	mat_index = 0;
	char		**line_split;

	line_split = NULL;
	if (mat_index < sc->num_materials)
	{
		while (line[0] != '}')
		{
			get_next_line(fd, &line);
			line_split = ft_strsplit(line, ' ');
			if (ft_len_tab(line_split) == 3)
			{
				if (ft_strchrstr(line_split[0], "diffuse") == 0)
					mat_diffuse(mat_index, line_split[2], sc);
				if (ft_strchrstr(line_split[0], "reflection") == 0)
					mat_reflec(mat_index, line_split[2], sc);
			}
			else if (line_split[0][0] != '}')
				return (-1);
		}
	}
	else
		return (-1);
	mat_index++;
	return (0);
}

static int		token_detect_elem(int fd, char *line, scene *sc)
{
	if (ft_strcmp(line, "Material{") == 0)
		if (detect_mat(fd, line, sc) == -1)
			return (-1);
	if (strcmp(line, "Light{") == 0)
		if (detect_light(fd, line, sc) == -1)
			return (-1);
	if (strcmp(line, "Sphere{") == 0)
		if (detect_sphere(fd, line, sc) == -1)
			return (-1);
	if (strcmp(line, "Plan{") == 0)
		if (detect_plan(fd, line, sc) == -1)
			return (-1);
	if (strcmp(line, "Cylindre{") == 0)
		if (detect_cyl(fd, line, sc) == -1)
			return (-1);
	if (strcmp(line, "Cone{") == 0)
		if (detect_cone(fd, line, sc) == -1)
			return (-1);
	return (0);
}

/*
** token_detect permet de switsh entre les differantes
** fonction de detection d'elements
*/

int				token_detect(int fd, char *line, scene *sc)
{
	int			flag;

	flag = 0;
	if (token_detect_elem(fd, line, sc) == -1)
	{
		ft_putendl("\nerror header elem");
		return (-1);
	}
	return (0);
}
