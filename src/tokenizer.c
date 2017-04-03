#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

#include "../header/includes.h"

static void		detect_elem(int fd, char *line, scene *my_scene)
{
	while (line[0] != '}')
	{
		get_next_line(fd, &line);
		if (line[0] == '\t' && line[1] == 'm')
			token_material(line, my_scene);
		if (line[0] == '\t' && line[1] == 's')
			token_sphere(line, my_scene);
		if (line[0] == '\t' && line[1] == 'l')
			token_light(line, my_scene);
		if (line[0] == '\t' && line[1] == 'w')
			token_width(line, my_scene);
		if (line[0] == '\t' && line[1] == 'h')
			token_height(line, my_scene);
	}
	ft_putchar('\n');
}

int				tokenizer(char *file, scene *my_scene)
{
	int		fd;
	char	*line;
	char	**line2;

	line2 = NULL;
	if ((fd = open(file, O_RDONLY)) == -1)
	{
		ft_putstr("File not found.\n");
		return (-1);
	}
	while (get_next_line(fd, &line) != 0)
	{
		if (ft_strcmp(line, "Scene{") == 0)
			detect_elem(fd, line, my_scene);
		if (token_detect(fd, line, line2, my_scene) == -1)
			return (-1);
	}
	return (0);
}
