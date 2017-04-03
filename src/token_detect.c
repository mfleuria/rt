#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

#include "../header/includes.h"

static int		detect_light(int fd, char *line, char **line2, scene *my_scene)
{
	static int	light_index = 0;

	while (line[0] != '}')
	{
		get_next_line(fd, &line);
		if (line[0] == '\t' && line[1] == 'p')
			light_pos(light_index, line, line2, my_scene);
		if (line[0] == '\t' && line[1] == 'c')
			light_col(light_index, line, line2, my_scene);
	}
	light_index++;
	ft_putchar('\n');
	if (light_index > my_scene->num_lights)
		return (-1);
	return (0);
}

static int		detect_sphere(int fd, char *line, char **line2, scene *my_scene)
{
	static int	sphere_index = 0;

	while (line[0] != '}')
	{
		get_next_line(fd, &line);
		if (line[0] == '\t' && line[1] == 'p')
			sphere_pos(sphere_index, line, line2, my_scene);
		if (line[0] == '\t' && line[1] == 'r' && line[2] == 'a')
			sphere_rad(sphere_index, line, my_scene);
		if (line[0] == '\t' && line[1] == 'm')
			sphere_mat(sphere_index, line, my_scene);
	}
	sphere_index++;
	ft_putchar('\n');
	if (sphere_index > my_scene->num_spheres)
		return (-1);
	return (0);
}

static int		detect_mat(int fd, char *line, char **line2, scene *my_scene)
{
	static int	mat_index = 0;

	while (line[0] != '}')
	{
		get_next_line(fd, &line);
		if (line[0] == '\t' && line[1] == 'd' && line[2] == 'i')
			mat_diffuse(mat_index, line, line2, my_scene);
		if (line[0] == '\t' && line[1] == 'r' && line[2] == 'e')
			mat_reflec(mat_index, line, my_scene);
	}
	mat_index++;
	ft_putchar('\n');
	if (mat_index > my_scene->num_materials)
		return (-1);
	return (0);
}

int				token_detect(int fd, char *line, char **line2, scene *my_scene)
{
	
	if (ft_strcmp(line, "Material{") == 0)
		if (detect_mat(fd, line, line2, my_scene) == -1)
		{
			ft_putstr("error file normalized material.\n");
			return (-1);
		}
	if (strcmp(line, "Sphere{") == 0)
		if (detect_sphere(fd, line, line2, my_scene) == -1)
		{
			ft_putstr("error file normalized sphere.\n");
			return (-1);
		}
	if (strcmp(line, "Light{") == 0)
		if (detect_light(fd, line, line2, my_scene) == -1)
		{
			ft_putstr("error file normalized light.\n");
			return (-1);
		}
	return (0);
}