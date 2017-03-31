#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "../header/includes.h"

void			token_material(char *line, scene *myscene)
{
	line = ft_strchr(line, '=');
	line++;
	myscene->numMaterials = ft_atoi(line);
	myscene->materials =
		(material *)ft_memalloc(myscene->numMaterials * sizeof(material));
	ft_putstr("\nNumber of materials:");
	ft_putnbr(myscene->numMaterials);
}

void			token_sphere(char *line, scene *myscene)
{
	line = ft_strchr(line, '=');
	line++;
	myscene->numSpheres = ft_atoi(line);
	myscene->spheres =
		(sphere *)ft_memalloc(myscene->numSpheres * sizeof(sphere));
	ft_putstr("\nNumber of Spheres: ");
	ft_putnbr(myscene->numSpheres);
}

void			token_light(char *line, scene *myscene)
{
	line = ft_strchr(line, '=');
	line++;
	myscene->numLights = ft_atoi(line);
	myscene->lights = (light *)ft_memalloc(myscene->numLights * sizeof(light));
	ft_putstr("\nNumber of Lights: ");
	ft_putnbr(myscene->numLights);
}

void			token_width(char *line, scene *myscene)
{
	line = ft_strchr(line, '=');
	line++;
	myscene->width = ft_atoi(line);
	ft_putstr("\nImage width: ");
	ft_putnbr(myscene->width);
}

void			token_height(char *line, scene *myscene)
{
	line = ft_strchr(line, '=');
	line++;
	myscene->height = ft_atoi(line);
	ft_putstr("\nImage height: ");
	ft_putnbr(myscene->height);
}
