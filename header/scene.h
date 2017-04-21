#ifndef _SCENE_H_
#define _SCENE_H_

#include "rtv1.h"
#include "sphere.h"
#include "plan.h"
#include "cylindre.h"
#include "cone.h"

/* Scene definition */
typedef struct{
	material	*materials;
	sphere		*spheres;
	t_plan		*plan;
	t_cylindre	*cylindre;
	t_cone		*cone;
	light		*lights;
	int			width, height;
	int			num_spheres;
	int			num_plan;
	int			num_cylindre;
	int			num_cone;
	int			num_materials;
	int			num_lights;
}				scene;

#endif /* _SCENE_H_ */