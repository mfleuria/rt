#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

#include "../../header/includes.h"

static int		plan_compose(int plan_index, char **line_split, scene *my_scene)
{
	if (ft_len_tab(line_split) == 3)
	{
		if (ft_strchrstr(line_split[0], "material") == 0)
			plan_mat(plan_index, line_split[2], my_scene);
		if (ft_strchrstr(line_split[0], "normal") == 0)
			plan_normal(plan_index, line_split[2], my_scene);
		if (ft_strchrstr(line_split[0], "offset") == 0)
			plan_offset(plan_index, line_split[2], my_scene);
	}
	else if (line_split[0][0] != '}')
		return (-1);
	return (0);
}

int				detect_plan(int fd, char *line, scene *my_scene)
{
	static int	plan_index = 0;
	char		**line_split;

	line_split = NULL;
	if (plan_index < my_scene->num_plan)
	{
		while (line[0] != '}')
		{
			get_next_line(fd, &line);
			line_split = ft_strsplit(line, ' ');
			if (plan_compose(plan_index, line_split, my_scene) == -1)
				return (-1);
		}
	}
	else
		return (-1);
	plan_index++;
	return (0);
}
