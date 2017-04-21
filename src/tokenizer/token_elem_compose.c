#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "../../header/includes.h"

void			token_sphere(char *line, scene *my_scene)
{
	line = ft_strcln(line);
	my_scene->num_spheres = ft_atoi(line);
	my_scene->spheres =
		(sphere *)ft_memalloc(my_scene->num_spheres * sizeof(sphere));
	ft_putstr("\nNumber of Spheres: ");
	ft_putnbr(my_scene->num_spheres);
}

void			token_plan(char *line, scene *my_scene)
{
	line = ft_strcln(line);
	my_scene->num_plan = ft_atoi(line);
	my_scene->plan =
		(t_plan *)ft_memalloc(my_scene->num_plan * sizeof(t_plan));
	ft_putstr("\nNumber of Plan: ");
	ft_putnbr(my_scene->num_plan);
}

void			token_cyl(char *line, scene *my_scene)
{
	line = ft_strcln(line);
	my_scene->num_cylindre = ft_atoi(line);
	my_scene->cylindre =
		(t_cylindre *)ft_memalloc(my_scene->num_cylindre * sizeof(t_cylindre));
	ft_putstr("\nNumber of cylindre: ");
	ft_putnbr(my_scene->num_cylindre);
}

void			token_cone(char *line, scene *my_scene)
{
	line = ft_strcln(line);
	my_scene->num_cone = ft_atoi(line);
	my_scene->cone =
		(t_cone *)ft_memalloc(my_scene->num_cone * sizeof(t_cone));
	ft_putstr("\nNumber of cone: ");
	ft_putnbr(my_scene->num_cone);
}
