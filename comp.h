#ifndef __COMP_H__
#define __COMP_H__

#include <stdint.h>
#include <math.h>

#define  INTREPOFFLOAT(f)   ( *(int32_t*)&(f) )
#define  INTREPOFDOUBLE(d)  ( *(int64_t*)&(d) )

#define  MAXULPS  5
#define  MAXULPSDOUBLE  5

uint64_t	abs64(int64_t x);
int			cmpDoubles(double a, double b);

#endif /* COMP_H__ */
