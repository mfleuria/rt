#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

#include "../../header/includes.h"

static int		cone_compose(int cone_index, char **line_split, scene *my_scene)
{
	if (ft_len_tab(line_split) == 3)
	{
		if (ft_strchrstr(line_split[0], "material") == 0)
			cone_mat(cone_index, line_split[2], my_scene);
		if (ft_strchrstr(line_split[0], "axis") == 0)
			cone_axis(cone_index, line_split[2], my_scene);
		if (ft_strchrstr(line_split[0], "apex") == 0)
			cone_apex(cone_index, line_split[2], my_scene);
		if (ft_strchrstr(line_split[0], "angle") == 0)
			cone_angle(cone_index, line_split[2], my_scene);
	}
	else if (line_split[0][0] != '}')
		return (-1);
	return (0);
}

int				detect_cone(int fd, char *line, scene *my_scene)
{
	static int	cone_index = 0;
	char		**line_split;

	line_split = NULL;
	if (cone_index < my_scene->num_cone)
	{
		while (line[0] != '}')
		{
			get_next_line(fd, &line);
			line_split = ft_strsplit(line, ' ');
			if (cone_compose(cone_index, line_split, my_scene) == -1)
				return (-1);
		}
	}
	else
		return (-1);
	cone_index++;
	return (0);
}
