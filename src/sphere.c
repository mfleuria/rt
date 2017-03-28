#include "../header/includes.h"

/* Check if the ray and sphere intersect
**
** A = d.d, the vector dot product of the direction
**
** We need a vector representing the distance between the start of
** the ray and the position of the circle.
** This is the term dist
**
** dist = (p0 - c)
** B = 2d.(p0 - c)
** C = (p0 - c).(p0 - c) - r^2
**
** If the discriminant is negative, there are no real roots.
** Return false in that case as the ray misses the sphere.
** Return true in all other cases (can be one or two intersections)
** t represents the distance between the start of the ray and
** the point on the sphere where it intersects.
**
** We want the closest one between t0 and t1
** Verify the closest one (t0) larger than 0 and less than the original t */

static bool	ft_check_closer(float discr, float b, float *t, bool retval)
{
	bool	retval;
	float	sqrtdiscr;
	float	t0;
	float	t1;

	sqrtdiscr = sqrtf(discr);
	t0 = (-b + sqrtdiscr) / 2;
	t1 = (-b - sqrtdiscr) / 2;
	if (t0 > t1)
		t0 = t1;
	if ((t0 > 0.001f) && (t0 < *t))
	{
		*t = t0;
		retval = TRUE;
	}
	else
		retval = FALSE;
	return (retval);
}

bool		intersect_ray_sphere(ray *r, sphere *s, float *t)
{
	vector	dist;
	float	a;
	float	b;
	float	c;
	float	discr;

	retval = FALSE;
	dist = vectorSub(&r->start, &s->pos);
	a = vectorDot(&r->dir, &r->dir);
	b = 2 * vectorDot(&r->dir, &dist);
	c = vectorDot(&dist, &dist) - (s->radius * s->radius);
	discr = b * b - 4 * a * c;
	if (discr < 0)
		return (FALSE);
	return (ft_check_closer(discr, b, t));
}
