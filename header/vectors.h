#ifndef _VECTORS_H_
#define _VECTORS_H_

/* The vector structure */
typedef struct{
        double x, y, z;
}vector;


/* Function Prototypes */

/* Add two vectors and return the resulting vector */
vector vector_add(vector *v1, vector *v2);
/* Subtract two vectors and return the resulting vector */
vector vector_sub(vector *v1, vector *v2);
/* Multiply two vectors and return the resulting scalar (dot product) */
double vector_dot(vector *v1, vector *v2);
/* Calculate Vector x Scalar */ 
vector vector_scale(double c, vector *v);
/* Calculate Vector cross product */
vector vector_cross(vector *v1, vector *v2);

#endif /* _VECTORS_H_ */
