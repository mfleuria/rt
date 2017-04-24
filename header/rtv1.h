#ifndef RTV1_H
# define RTV1_H

# include "includes.h"

typedef struct		s_material
{
	t_color			diffuse;
	float			reflection;
}					t_material;

typedef struct		s_light
{
	t_vector		pos;
	t_color			intensity;
}					t_light;

typedef struct		s_ray
{
	t_vector		start;
	t_vector		dir;
}					t_ray;

#endif
