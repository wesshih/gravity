#ifndef PARTICLE_H
#define PARTICLE_H

#include "vector3.h"

// The particle will pretty much just have a mass and radius
// TODO: maybe particle should keep track of position and velocity?
struct particle{
  unsigned long mass;
  double radius;
  struct vector3 *position, *velocity;
};



struct particle * particle_new(unsigned long mass, double radius, struct vector3 *position, struct vector3 *velocity);

#endif
