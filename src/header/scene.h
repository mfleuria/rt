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
        
        int numSpheres;
        int numMaterials;
        int numLights;
        
}scene;

#endif /* _SCENE_H_ */