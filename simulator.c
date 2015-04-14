#include <stdio.h>
#include <stdlib.h>
#include "vector3.h"
#include "particle.h"
#include "util.h"

#define MAX_TIME 500
#define NUM_PARTICLES 2

int main(int argc, char **argv) {
  printf("Vector Testing\n");

  struct vector3 *v1 = vector3_new(1, 0, 0);
  struct vector3 *v2 = vector3_new(0, 1, 0);

  struct vector3 *r1 = vector3_add(v1, v2);
  struct vector3 *r2 = vector3_cross(v1, v2);
  r1 = vector3_add(r1, r2);

  printf("v1:\tx:%f\ty:%f\tz:%f\n", v1->x, v1->y, v1->z);
  printf("v2:\tx:%f\ty:%f\tz:%f\n", v2->x, v2->y, v2->z);
  printf("r1:\tx:%f\ty:%f\tz:%f\n", r1->x, r1->y, r1->z);
  printf("r2:\tx:%f\ty:%f\tz:%f\n", r2->x, r2->y, r2->z);


  int p_num;
  struct particle **ps = (struct particle **)malloc(sizeof(struct particle *) * NUM_PARTICLES);
  if (ps == NULL) printf("good god wtf, ps is null\n");
  else {
    for (p_num = 0; p_num < NUM_PARTICLES; p_num++) {
      ps[p_num] = particle_new(1,1,vector3_new(0,0,0),vector3_new(0,0,0));
    }
  }

  ps[0]->position->x = 1;
  ps[0]->velocity->x = 0.33;

  printf("Starting 'Simulation'\n");
  printf("Initial state:\n");
  for (p_num = 0; p_num < NUM_PARTICLES; p_num++) {
    printf("\tp2: pos(%f,%f,%f), vel(%f,%f,%f)\n", ps[p_num]->position->x, ps[p_num]->position->y, ps[p_num]->position->z, ps[p_num]->velocity->x, ps[p_num]->velocity->y, ps[p_num]->velocity->z);
  }


  int t;
  for (t = 0; t < MAX_TIME; t++) {
    for (p_num = 0; p_num < NUM_PARTICLES; p_num++) {
      struct particle *cur_part = ps[p_num];
      cur_part->position = vector3_add(cur_part->position, cur_part->velocity);
    }
  }

  printf("Terminal state:\n");
  for (p_num = 0; p_num < NUM_PARTICLES; p_num++) {
    printf("\tp2: pos(%f,%f,%f), vel(%f,%f,%f)\n", ps[p_num]->position->x, ps[p_num]->position->y, ps[p_num]->position->z, ps[p_num]->velocity->x, ps[p_num]->velocity->y, ps[p_num]->velocity->z);
  }
  
  struct particle *p0 = particle_new(1, 1, vector3_new(0,0,0), vector3_new(0,1,0));
  struct particle *p1 = particle_new(1, 1, vector3_new(2,0,0), vector3_new(0,0,0));
 
  printf("GRAVITY TEST\n");
  printf("p0: pos(%f,%f,%f), vel(%f,%f,%f)\n", p0->position->x, p0->position->y, p0->position->z, p0->velocity->x, p0->velocity->y, p0->velocity->z);
  printf("p1: pos(%f,%f,%f), vel(%f,%f,%f)\n", p1->position->x, p1->position->y, p1->position->z, p1->velocity->x, p1->velocity->y, p1->velocity->z);

  struct vector3 *g01 = calc_force_grav(p0, p1);
  printf("g01:(%f,%f,%f)\n", g01->x, g01->y, g01->z);
  struct vector3 *a01 = calc_accel(p0, g01);
  p0->velocity = calc_velocity(a01, p0->velocity);
  p0->position = vector3_add(p0->position, p0->velocity);
  printf("p0: pos(%f,%f,%f), vel(%f,%f,%f)\n", p0->position->x, p0->position->y, p0->position->z, p0->velocity->x, p0->velocity->y, p0->velocity->z);
  printf("p1: pos(%f,%f,%f), vel(%f,%f,%f)\n", p1->position->x, p1->position->y, p1->position->z, p1->velocity->x, p1->velocity->y, p1->velocity->z);

  
  g01 = calc_force_grav(p0, p1);
  printf("g01:(%f,%f,%f)\n", g01->x, g01->y, g01->z);
  a01 = calc_accel(p0, g01);
  p0->velocity = calc_velocity(a01, p0->velocity);
  p0->position = vector3_add(p0->position, p0->velocity);
  printf("p0: pos(%f,%f,%f), vel(%f,%f,%f)\n", p0->position->x, p0->position->y, p0->position->z, p0->velocity->x, p0->velocity->y, p0->velocity->z);
  printf("p1: pos(%f,%f,%f), vel(%f,%f,%f)\n", p1->position->x, p1->position->y, p1->position->z, p1->velocity->x, p1->velocity->y, p1->velocity->z);

  g01 = calc_force_grav(p0, p1);
  printf("g01:(%f,%f,%f)\n", g01->x, g01->y, g01->z);
  a01 = calc_accel(p0, g01);
  p0->velocity = calc_velocity(a01, p0->velocity);
  p0->position = vector3_add(p0->position, p0->velocity);
  printf("p0: pos(%f,%f,%f), vel(%f,%f,%f)\n", p0->position->x, p0->position->y, p0->position->z, p0->velocity->x, p0->velocity->y, p0->velocity->z);
  printf("p1: pos(%f,%f,%f), vel(%f,%f,%f)\n", p1->position->x, p1->position->y, p1->position->z, p1->velocity->x, p1->velocity->y, p1->velocity->z);


  g01 = calc_force_grav(p0, p1);
  printf("g01:(%f,%f,%f)\n", g01->x, g01->y, g01->z);
  a01 = calc_accel(p0, g01);
  p0->velocity = calc_velocity(a01, p0->velocity);
  p0->position = vector3_add(p0->position, p0->velocity);
  printf("p0: pos(%f,%f,%f), vel(%f,%f,%f)\n", p0->position->x, p0->position->y, p0->position->z, p0->velocity->x, p0->velocity->y, p0->velocity->z);
  printf("p1: pos(%f,%f,%f), vel(%f,%f,%f)\n", p1->position->x, p1->position->y, p1->position->z, p1->velocity->x, p1->velocity->y, p1->velocity->z);


  g01 = calc_force_grav(p0, p1);
  printf("g01:(%f,%f,%f)\n", g01->x, g01->y, g01->z);
  a01 = calc_accel(p0, g01);
  p0->velocity = calc_velocity(a01, p0->velocity);
  p0->position = vector3_add(p0->position, p0->velocity);
  printf("p0: pos(%f,%f,%f), vel(%f,%f,%f)\n", p0->position->x, p0->position->y, p0->position->z, p0->velocity->x, p0->velocity->y, p0->velocity->z);
  printf("p1: pos(%f,%f,%f), vel(%f,%f,%f)\n", p1->position->x, p1->position->y, p1->position->z, p1->velocity->x, p1->velocity->y, p1->velocity->z);
  printf("radius %f\n", calc_radius(p0, p1));

  return 0;
}
