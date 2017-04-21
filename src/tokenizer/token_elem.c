#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "../../header/includes.h"

void			token_material(char *line, scene *my_scene)
{
	line = ft_strcln(line);
	my_scene->num_materials = ft_atoi(line);
	my_scene->materials =
		(material *)ft_memalloc(my_scene->num_materials * sizeof(material));
	ft_putstr("\nNumber of materials: ");
	ft_putnbr(my_scene->num_materials);
}

void			token_light(char *line, scene *my_scene)
{
	line = ft_strcln(line);
	my_scene->num_lights = ft_atoi(line);
	my_scene->lights =
		(light *)ft_memalloc(my_scene->num_lights * sizeof(light));
	ft_putstr("\nNumber of Lights: ");
	ft_putnbr(my_scene->num_lights);
}

void			token_width(char *line, scene *my_scene)
{
	line = ft_strcln(line);
	my_scene->width = ft_atoi(line);
	ft_putstr("\nImage width: ");
	ft_putnbr(my_scene->width);
}

void			token_height(char *line, scene *my_scene)
{
	line = ft_strcln(line);
	my_scene->height = ft_atoi(line);
	ft_putstr("\nImage height: ");
	ft_putnbr(my_scene->height);
}
