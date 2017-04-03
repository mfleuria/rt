#ifndef _SCENE_H_
#define _SCENE_H_

#include "rtv1.h"
#include "sphere.h"

/* Scene definition */
typedef struct{
        material *materials;
        sphere   *spheres;
        light    *lights;
        
        int      width, height;
        
        int num_spheres;
        int num_materials;
        int num_lights;
        
}scene;

#endif /* _SCENE_H_ */