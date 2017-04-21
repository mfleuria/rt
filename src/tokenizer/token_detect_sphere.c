#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

#include "../../header/includes.h"

static int		sphere_compose(int sphere_index, char **line_split, scene *sc)
{
	if (ft_len_tab(line_split) == 3)
	{
		if (ft_strchrstr(line_split[0], "position") == 0)
			sphere_pos(sphere_index, line_split[2], sc);
		if (ft_strchrstr(line_split[0], "radius") == 0)
			sphere_rad(sphere_index, line_split[2], sc);
		if (ft_strchrstr(line_split[0], "material") == 0)
			sphere_mat(sphere_index, line_split[2], sc);
	}
	else if (line_split[0][0] != '}')
		return (-1);
	return (0);
}

int				detect_sphere(int fd, char *line, scene *sc)
{
	static int	sphere_index = 0;
	char		**line_split;

	line_split = NULL;
	if (sphere_index < sc->num_spheres)
	{
		while (line[0] != '}')
		{
			get_next_line(fd, &line);
			line_split = ft_strsplit(line, ' ');
			if (sphere_compose(sphere_index, line_split, sc) == -1)
				return (-1);
		}
	}
	else
		return (-1);
	sphere_index++;
	return (0);
}
