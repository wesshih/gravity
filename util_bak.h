#ifndef UTIL_H
#define UTIL_H

#include "particle.h"
#include "vector3.h"

// this seemed like an easy way to have big G temporarily
//#define G (6.674/100000000000)
#define G 1

struct vector3 * calc_force_grav(struct particle *p1, struct particle *p2);
float calc_radius(struct particle *p1, struct particle *p2);

#endif
