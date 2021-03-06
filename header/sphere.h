#ifndef _SPHERE_H_
#define _SPHERE_H_

//#include "vectors.h"

/* Sphere Primitive definition */
typedef struct
{
        vector pos;
        double radius;
        int material;
}					sphere;

bool intersect_ray_sphere(ray *r, sphere *s, float *t);


#endif /* _SPHERE_H_ */
