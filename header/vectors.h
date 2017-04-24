#ifndef VECTORS_H
# define VECTORS_H

typedef struct		s_vector
{
	double			x;
	double			y;
	double			z;
}					t_vector;

t_vector			vector_add(t_vector *v1, t_vector *v2);
t_vector			vector_sub(t_vector *v1, t_vector *v2);
double				vector_dot(t_vector *v1, t_vector *v2);
t_vector			vector_scale(double c, t_vector *v);
t_vector			vector_cross(t_vector *v1, t_vector *v2);

#endif
