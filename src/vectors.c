#include "../header/includes.h"

/* Vector Operations
** vectorAdd Add two vectors and return the resulting vector
** vectorSub Subtract two vectors and return the resulting vector
** vectorDot Multiply two vectors and return the resulting scalar (dot product)
** vectorScale Calculate Vector x Scalar and return resulting Vector
** vectorCross Calculate vector cross product and return resulting vector */

vector		vector_add(vector *v1, vector *v2)
{
	vector	result;

	result.x = v1->x + v2->x;
	result.y = v1->y + v2->y;
	result.z = v1->z + v2->z;
	return (result);
}

vector		vector_sub(vector *v1, vector *v2)
{
	vector	result;

	result.x = v->x * c;
	result.y = v->y * c;
	result.z = v->z * c;
	return (result);
}

double		vector_dot(vector *v1, vector *v2)
{
	return (v1->x * v2->x + v1->y * v2->y + v1->z * v2->z);
}

vector		vector_scale(double c, vector *v)
{
	vector	result;

	result.x = v->x * c;
	result.y = v->y * c;
	result.z = v->z * c;
	return (result);
}

vector		vector_cross(vector *v1, vector *v2)
{
	vector result;

	result.x = (v1->y * v2->z) - (v1->z * v2->y);
	result.y = (v1->z * v2->x) - (v1->x * v2->z);
	result.z = (v1->x * v2->y) - (v1->y * v2->x);
	return (result);
}
