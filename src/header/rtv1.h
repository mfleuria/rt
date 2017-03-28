#ifndef RTV1_H
# define RTV1_H

# include "vectors.h"
# include "colour.h"

/* Material Definition */
typedef struct
{
	colour diffuse;
	float reflection;
}	material;

/* Lightsource definition */
typedef struct
{
	vector pos;
	colour intensity;
}	light;

/* The ray */
typedef struct
{
        vector start;
        vector dir;
}	ray;

#endif