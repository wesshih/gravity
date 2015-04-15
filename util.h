#include <stdlib.h>
#ifndef UTIL_H
#define UTIL_H

#include <math.h>
#include "vector3.h"
#include "particle.h"

// this seemed like an easy way to have big G temporarily
#define G (6.674/100000000000)
//#define G .01

// declarations
struct vector3 * calc_force_grav(struct particle *p1, struct particle *p2);
double calc_radius(struct particle *p1, struct particle *p2);

// this returns a vector 3 that points from p1 to p2, with magnitude of the force felt
// this calculates the force on p1 by p2
struct vector3 * calc_force_grav(struct particle *p1, struct particle *p2) {
  if (p1 == NULL || p2 == NULL) return NULL; //never should calculate 0, so error code

  double numer = G * p1->mass * p2->mass;
  double denom = pow(calc_radius(p1, p2), 2);
  return vector3_scale(vector3_norm(vector3_sub(p2->position, p1->position)),(numer/denom));
}

double calc_radius(struct particle *p1, struct particle *p2) {
  if (p1 == NULL || p2 == NULL) return -1; //never should calculate -1, so error code

  double dx2 = pow(p1->position->x - p2->position->x, 2);
  double dy2 = pow(p1->position->y - p2->position->y, 2);
  double dz2 = pow(p1->position->z - p2->position->z, 2);
  return pow(dx2+dy2+dz2,0.5);
}


struct vector3 * calc_accel(struct particle *p, struct vector3 *force) {
  if (force == NULL) return NULL;
  return vector3_scale(force, 1/(p->mass)); 
}

struct vector3 * calc_velocity(struct vector3 *accel, struct vector3 *old_vel) {
  if (accel == NULL || old_vel == NULL) return NULL;
  return vector3_add(old_vel, accel);
}


#endif
