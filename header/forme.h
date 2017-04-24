#ifndef FORME_H
# define FORME_H

# include "includes.h"

typedef struct		s_sphere
{
	t_vector		pos;
	double			radius;
	int				material;
}					t_sphere;

typedef struct		s_cone
{
	int				material;
	t_vector		axis;
	t_vector		apex;
	float			angle;
}					t_cone;

typedef struct		s_cylindre
{
	int				material;
	t_vector		axis;
	t_vector		pos;
	float			radius;
}					t_cylindre;

typedef struct		s_plan
{
	int				material;
	t_vector		normal;
	float			offset;
}					t_plan;

t_bool				intersect_ray_sphere(t_ray *r, t_sphere *s, float *t);
t_bool				intersect_ray_cone(t_ray *r, t_cone *c, float *t);
t_bool				intersect_ray_cylindre(t_ray *r, t_cylindre *c, float *t);

#endif
