#ifndef _DEF_H_
#define _DEF_H_

#include <math.h>

#define PIOVER180 0.017453292519943295769236907684886
#define PI        3.141592653589793238462643383279502

#define min(a,b) (((a) < (b)) ? (a) : (b))
#define max(a,b) (((a) > (b)) ? (a) : (b))
#define invsqrtf(x) (1.0f / sqrtf(x))

# define RES_X 1920                       // = Résolution horizontale
# define RES_Y 1080                       // = Résolution verticale
# define MAX_X 639                        // = RES_X-1
# define MAX_Y 479

#define TRUE  1
#define FALSE 0

typedef unsigned char bool;

#endif /* _DEF_H_ */