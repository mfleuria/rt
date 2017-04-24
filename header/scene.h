#ifndef SCENE_H
# define SCENE_H

# include "includes.h"

typedef struct		s_scene
{
	t_material		*materials;
	t_sphere		*spheres;
	t_plan			*plan;
	t_cylindre		*cylindre;
	t_cone			*cone;
	t_light			*lights;
	int				width;
	int				height;
	int				num_spheres;
	int				num_plan;
	int				num_cylindre;
	int				num_cone;
	int				num_materials;
	int				num_lights;
}					t_scene;

#endif
