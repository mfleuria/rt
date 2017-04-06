#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

#include "../header/includes.h"

static int		detect_light(int fd, char *line, scene *my_scene)
{
	static int	light_index = 0;
	char		**line_split;

	line_split = NULL;
	while (line[0] != '}')
	{
		get_next_line(fd, &line);
		line_split = ft_strsplit(line, ' ');
		if (ft_len_tab(line_split) == 3)
		{
			if (ft_strchrstr(line_split[0], "position") == 0)
				light_pos(light_index, line_split[2], my_scene);
			if (ft_strchrstr(line_split[0], "colour") == 0)
				light_col(light_index, line_split[2], my_scene);
		}
		else if (line_split[0][0] != '}')
			return (-1);
	}
	light_index++;
	ft_putchar('\n');
	if (light_index > my_scene->num_lights)
		return (-1);
	return (0);
}

static int		detect_sphere(int fd, char *line, scene *my_scene)
{
	static int	sphere_index = 0;
	char		**line_split;

	line_split = NULL;
	while (line[0] != '}')
	{
		get_next_line(fd, &line);
		line_split = ft_strsplit(line, ' ');
		if (ft_len_tab(line_split) == 3)
		{
			if (ft_strchrstr(line_split[0], "position") == 0)
				sphere_pos(sphere_index, line_split[2], my_scene);
			if (ft_strchrstr(line_split[0], "radius") == 0)
				sphere_rad(sphere_index, line_split[2], my_scene);
			if (ft_strchrstr(line_split[0], "material") == 0)
				sphere_mat(sphere_index, line_split[2], my_scene);
		}
		else if (line_split[0][0] != '}')
			return (-1);
	}
	sphere_index++;
	ft_putchar('\n');
	if (sphere_index > my_scene->num_spheres)
		return (-1);
	return (0);
}

static int		detect_mat(int fd, char *line, scene *my_scene)
{
	static int	mat_index = 0;
	char		**line_split;

	line_split = NULL;
	while (line[0] != '}')
	{
		get_next_line(fd, &line);
		line_split = ft_strsplit(line, ' ');
		if (ft_len_tab(line_split) == 3)
		{
			if (ft_strchrstr(line_split[0], "diffuse") == 0)
				mat_diffuse(mat_index, line_split[2], my_scene);
			if (ft_strchrstr(line_split[0], "reflection") == 0)
				mat_reflec(mat_index, line_split[2], my_scene);
		}
		else if (line_split[0][0] != '}')
			return (-1);
	}
	mat_index++;
	ft_putchar('\n');
	if (mat_index > my_scene->num_materials)
		return (-1);
	return (0);
}

int				token_detect(int fd, char *line, scene *my_scene)
{
	if (ft_strcmp(line, "Material{") == 0)
		if (detect_mat(fd, line, my_scene) == -1)
		{
			ft_putstr("\nerror file normalized material.\n");
			return (-1);
		}
	if (strcmp(line, "Sphere{") == 0)
		if (detect_sphere(fd, line, my_scene) == -1)
		{
			ft_putstr("\nerror file normalized sphere.\n");
			return (-1);
		}
	if (strcmp(line, "Light{") == 0)
	{
		if (detect_light(fd, line, my_scene) == -1)
		{
			ft_putstr("\nerror file normalized light.\n");
			return (-1);
		}
	}
	return (0);
}
