#ifndef PARTICLE_H
#define PARTICLE_H

#include "vector3.h"

// The particle will pretty much just have a mass and radius
// TODO: maybe particle should keep track of position and velocity?
struct particle{
  float mass, radius;
  struct vector3 *position, *velocity;
};
// hopefully it doesn't come back to haunt me that im too lazy to write out Particle and Particle_Ptr...



struct particle * particle_new(float mass, float radius, struct vector3 *position, struct vector3 *velocity);

#endif
