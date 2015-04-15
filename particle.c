#include <stdlib.h>
#include "particle.h"

struct particle * particle_new(unsigned long mass, double radius, struct vector3 *position, struct vector3 *velocity) {
  struct particle *p = (struct particle *)malloc(sizeof(struct particle));
  if (p == NULL) return NULL;
  p->mass = mass;
  p->radius = radius;
  p->position = position;
  p->velocity = velocity;
  return p;
}
