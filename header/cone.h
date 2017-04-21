#ifndef _CONE_H_
#define _CONE_H_

//#include "vectors.h"

/* cone Primitive definition */

typedef struct		s_cone
{
	int				material;
	vector			axis;
	vector			apex;
	float			angle;
}			t_cone;

#endif /* _CONE_H_ */