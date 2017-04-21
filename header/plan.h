#ifndef _PLAN_H_
#define _PLAN_H_

//#include "vectors.h"

/* plan Primitive definition */


typedef struct		s_plan
{
	int				material;
	vector			normal;
	float			offset;
}					t_plan;

#endif /* _PLAN_H_ */