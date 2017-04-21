#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

#include "../../header/includes.h"

static int		scene_compose(char **line_split, scene *my_scene)
{
	if (ft_len_tab(line_split) == 3)
	{
		if (ft_strchrstr(line_split[0], "materials") == 0)
			token_material(line_split[2], my_scene);
		else if (ft_strchrstr(line_split[0], "spheres") == 0)
			token_sphere(line_split[2], my_scene);
		else if (ft_strchrstr(line_split[0], "lights") == 0)
			token_light(line_split[2], my_scene);
		else if (ft_strchrstr(line_split[0], "width") == 0)
			token_width(line_split[2], my_scene);
		else if (ft_strchrstr(line_split[0], "height") == 0)
			token_height(line_split[2], my_scene);
		else if (ft_strchrstr(line_split[0], "plan") == 0)
			token_plan(line_split[2], my_scene);
		else if (ft_strchrstr(line_split[0], "cylindre") == 0)
			token_cyl(line_split[2], my_scene);
		else if (ft_strchrstr(line_split[0], "cone") == 0)
			token_cone(line_split[2], my_scene);
	}
	else if (line_split[0][0] != '}')
		return (-1);
	return (0);
}

static int		detect_elem_scene(int fd, char *line, scene *my_scene)
{
	char		**line_split;

	line_split = NULL;
	while (line[0] != '}')
	{
		get_next_line(fd, &line);
		line_split = ft_strsplit(line, ' ');
		if (scene_compose(line_split, my_scene) == -1)
			return (-1);
	}
	ft_putchar('\n');
	return (0);
}

static void		init_tokenizer(scene *my_scene)
{
	my_scene->num_lights = 0;
	my_scene->num_spheres = 0;
	my_scene->num_materials = 0;
	my_scene->num_plan = 0;
	my_scene->num_cylindre = 0;
	my_scene->num_cone = 0;
}

int				tokenizer(char *file, scene *my_scene)
{
	int		fd;
	char	*line;
	char	**line2;

	line2 = NULL;
	init_tokenizer(my_scene);
	if ((fd = open(file, O_RDONLY)) == -1)
	{
		ft_putstr("File not found.\n");
		return (-1);
	}
	while (get_next_line(fd, &line) != 0)
	{
		if (ft_strcmp(line, "Scene{") == 0)
			if (detect_elem_scene(fd, line, my_scene) == -1)
			{
				ft_putstr("error space file.\n");
				return (-1);
			}
		if (token_detect(fd, line, my_scene) == -1)
			return (-1);
	}
	ft_putstr("fichier OK \n");
	return (0);
}
