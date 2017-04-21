#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

#include "../../header/includes.h"

static int		cyl_compose(int cyl_index, char **line_split, scene *my_scene)
{
	if (ft_len_tab(line_split) == 3)
	{
		if (ft_strchrstr(line_split[0], "material") == 0)
			cyl_mat(cyl_index, line_split[2], my_scene);
		if (ft_strchrstr(line_split[0], "axis") == 0)
			cyl_axis(cyl_index, line_split[2], my_scene);
		if (ft_strchrstr(line_split[0], "position") == 0)
			cyl_pos(cyl_index, line_split[2], my_scene);
		if (ft_strchrstr(line_split[0], "radius") == 0)
			cyl_radius(cyl_index, line_split[2], my_scene);
	}
	else if (line_split[0][0] != '}')
		return (-1);
	return (0);
}

int				detect_cyl(int fd, char *line, scene *my_scene)
{
	static int	cyl_index = 0;
	char		**line_split;

	line_split = NULL;
	if (cyl_index < my_scene->num_cylindre)
	{
		while (line[0] != '}')
		{
			get_next_line(fd, &line);
			line_split = ft_strsplit(line, ' ');
			if (cyl_compose(cyl_index, line_split, my_scene))
				return (-1);
		}
	}
	else
		return (-1);
	cyl_index++;
	return (0);
}
