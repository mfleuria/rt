#ifndef _GLOBAL_H_
#define _GLOBAL_H_

typedef struct      s_global
{
    int             argc;
    char            **argv;
    char            *file_name;
    ray             r;
    t_env           e;
    scene           *my_scene; //penser a l'initialiser a NULL au debut
	scene           mine;
	int             x;
    int             y;
    t_colour        color; //ligne 32 a 34 dans ray_trace2.c
    int             level;
    float           coef;
    float           t;
    int             current_sphere;
    unsigned int    i;
    vector          scaled;
    vector          new_start;
    vector          n;
    float           temp;
    material        current_mat;
    unsigned int    j;
    light           current_light;
    vector          dist;
    ray             light_ray;
    float           lambert;
    float           reflect;
    int             nb_sphere;
    vector          tmp;
}                   t_global;

#endif