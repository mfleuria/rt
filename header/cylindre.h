#ifndef _CYLINDRE_H_
#define _CYLINDRE_H_

//#include "vectors.h"

/* cylindre Primitive definition */

typedef struct		s_cylindre
{
	int				material;
	vector			axis;
	vector			pos;
	float			radius;
}					t_cylindre;

#endif /* _CYLINDRE_H_ */