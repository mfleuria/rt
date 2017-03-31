#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

#include "../header/includes.h"

static void		detect_light(int fd, char *line, char **line2, scene *myscene)
{
	static int	light_index = 0;
	while (line[0]!= '}')
	{
		get_next_line(fd, &line);
		if (line[0] == '\t' && line[1] == 'p')
			light_pos(light_index, line, line2, myscene);
		if (line[0] == '\t' && line[1] == 'c')
			light_col(light_index, line, line2, myscene);
	}
	light_index++;
	ft_putchar('\n');
}

static void		detect_sphere(int fd, char *line, char **line2, scene *myscene)
{
	static int	sphere_index = 0;

	while (line[0]!= '}')
	{
		get_next_line(fd, &line);
		if (line[0] == '\t' && line[1] == 'p')
			sphere_pos(sphere_index, line, line2, myscene);
		if (line[0] == '\t' && line[1] == 'r' && line[2] == 'a')
			sphere_rad(sphere_index, line, myscene);
		if (line[0] == '\t' && line[1] == 'm')
			sphere_mat(sphere_index, line, myscene);
	}
	sphere_index++;
	ft_putchar('\n');
}

static void		detect_material(int fd, char *line, char **line2, scene *myscene)
{
	static int	mat_index = 0;

	while (line[0] != '}')
	{
		get_next_line(fd, &line);
		if (line[0] == '\t' && line[1] == 'd' && line[2] == 'i')
			mat_diffuse(mat_index, line, line2, myscene);
		if (line[0] == '\t' && line[1] == 'r' && line[2] == 'e')
			mat_reflec(mat_index, line, myscene);
	}
	mat_index++;
	ft_putchar('\n');
}

static void		detect_elem(int fd, char *line, scene *myscene)
{
	while (line[0]!= '}')
	{
		get_next_line(fd, &line);
		if (line[0] == '\t' && line[1] == 'm')
			token_material(line, myscene);
		if (line[0] == '\t' && line[1] == 's')
			token_sphere(line,myscene);
		if (line[0] == '\t' && line[1] == 'l')
			token_light(line, myscene);
		if (line[0] == '\t' && line[1] == 'w')
			token_width(line, myscene);
		if (line[0] == '\t' && line[1] == 'h')
			token_height(line, myscene);
	}
	ft_putchar('\n');
}

int				tokenizer(char *file, scene *myscene)
{
	int		fd;
	char	*line;
	char 	**line2;

	line2 = NULL;
	if ((fd = open(file, O_RDONLY)) == -1)
	{
		ft_putstr("File not found.\n");
		return (-1);
	}
	while (get_next_line(fd, &line) != 0)
	{
		if(ft_strcmp(line, "Scene{") == 0)
			detect_elem(fd, line, myscene);
		if (ft_strcmp(line,"Material{") == 0)
			detect_material(fd, line, line2, myscene);
		if (strcmp(line,"Sphere{") == 0)
			detect_sphere(fd, line, line2, myscene);
		if (strcmp(line,"Light{") == 0) 
			detect_light(fd, line, line2, myscene);
	}
	return (0);
}