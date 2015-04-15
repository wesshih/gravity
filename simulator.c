#include <stdio.h>
#include <stdlib.h>
#include "vector3.h"
#include "particle.h"
#include "util.h"
#include "read_part.h"

#define MAX_TIME 2
#define NUM_PARTICLES 2

int main(int argc, char **argv) {

  if (argc < 2) {
    printf("enter particle file\n");
    return -1;
  }
  char *filename = argv[1];
  int p_num, i, j;
  struct particle **ps = read_part(filename, &p_num);
  if (ps == NULL) {
    printf("good god wtf, ps is null, reading file failed\n");
    return -1;
  }

  printf("Starting 'Simulation'\n");
  printf("Initial state:\n");
  for (i = 0; i < p_num; i++) {
    printf("\tp%d: pos(%f,%f,%f), vel(%f,%f,%f)\n", i, ps[i]->position->x, ps[i]->position->y, ps[i]->position->z, ps[i]->velocity->x, ps[i]->velocity->y, ps[i]->velocity->z);
  }

  int t;
  for (t = 0; t < MAX_TIME; t++) {
    for (i = 0; i < p_num; i++) {
      for (j = 0; j < p_num; j++) {
        if (i == j) continue;
        struct vector3 *g_ij = calc_force_grav(ps[i], ps[j]);
	struct vector3 *a_ij = calc_accel(ps[i], g_ij);
	ps[i]->velocity = calc_velocity(a_ij, ps[i]->velocity);
        printf("grav: (%f, %f, %f)\n", g_ij->x, g_ij->y, g_ij->z);
        printf("acel: (%f, %f, %f)\n", a_ij->x, a_ij->y, a_ij->z);
      }
    }
    for (i = 0; i < p_num; i++) {
      struct particle *cur_part = ps[i];
      cur_part->position = vector3_add(cur_part->position, cur_part->velocity);
    }
  }

  printf("Terminal state:\n");
  for (i = 0; i < p_num; i++) {
    printf("\tp%d: pos(%f,%f,%f), vel(%f,%f,%f)\n", i, ps[i]->position->x, ps[i]->position->y, ps[i]->position->z, ps[i]->velocity->x, ps[i]->velocity->y, ps[i]->velocity->z);
  }
  
  //struct particle *p0 = particle_new(1, 1, vector3_new(0,0,0), vector3_new(0,1,0));
  //struct particle *p1 = particle_new(1, 1, vector3_new(2,0,0), vector3_new(0,0,0));
 
  //printf("GRAVITY TEST\n");
  //printf("p0: pos(%f,%f,%f), vel(%f,%f,%f)\n", p0->position->x, p0->position->y, p0->position->z, p0->velocity->x, p0->velocity->y, p0->velocity->z);
  //printf("p1: pos(%f,%f,%f), vel(%f,%f,%f)\n", p1->position->x, p1->position->y, p1->position->z, p1->velocity->x, p1->velocity->y, p1->velocity->z);

  //struct vector3 *g01 = calc_force_grav(p0, p1);
  //printf("g01:(%f,%f,%f)\n", g01->x, g01->y, g01->z);
  //struct vector3 *a01 = calc_accel(p0, g01);
  //p0->velocity = calc_velocity(a01, p0->velocity);
  //p0->position = vector3_add(p0->position, p0->velocity);
  //printf("p0: pos(%f,%f,%f), vel(%f,%f,%f)\n", p0->position->x, p0->position->y, p0->position->z, p0->velocity->x, p0->velocity->y, p0->velocity->z);
  //printf("p1: pos(%f,%f,%f), vel(%f,%f,%f)\n", p1->position->x, p1->position->y, p1->position->z, p1->velocity->x, p1->velocity->y, p1->velocity->z);

  //
  //g01 = calc_force_grav(p0, p1);
  //printf("g01:(%f,%f,%f)\n", g01->x, g01->y, g01->z);
  //a01 = calc_accel(p0, g01);
  //p0->velocity = calc_velocity(a01, p0->velocity);
  //p0->position = vector3_add(p0->position, p0->velocity);
  //printf("p0: pos(%f,%f,%f), vel(%f,%f,%f)\n", p0->position->x, p0->position->y, p0->position->z, p0->velocity->x, p0->velocity->y, p0->velocity->z);
  //printf("p1: pos(%f,%f,%f), vel(%f,%f,%f)\n", p1->position->x, p1->position->y, p1->position->z, p1->velocity->x, p1->velocity->y, p1->velocity->z);

  //g01 = calc_force_grav(p0, p1);
  //printf("g01:(%f,%f,%f)\n", g01->x, g01->y, g01->z);
  //a01 = calc_accel(p0, g01);
  //p0->velocity = calc_velocity(a01, p0->velocity);
  //p0->position = vector3_add(p0->position, p0->velocity);
  //printf("p0: pos(%f,%f,%f), vel(%f,%f,%f)\n", p0->position->x, p0->position->y, p0->position->z, p0->velocity->x, p0->velocity->y, p0->velocity->z);
  //printf("p1: pos(%f,%f,%f), vel(%f,%f,%f)\n", p1->position->x, p1->position->y, p1->position->z, p1->velocity->x, p1->velocity->y, p1->velocity->z);


  //g01 = calc_force_grav(p0, p1);
  //printf("g01:(%f,%f,%f)\n", g01->x, g01->y, g01->z);
  //a01 = calc_accel(p0, g01);
  //p0->velocity = calc_velocity(a01, p0->velocity);
  //p0->position = vector3_add(p0->position, p0->velocity);
  //printf("p0: pos(%f,%f,%f), vel(%f,%f,%f)\n", p0->position->x, p0->position->y, p0->position->z, p0->velocity->x, p0->velocity->y, p0->velocity->z);
  //printf("p1: pos(%f,%f,%f), vel(%f,%f,%f)\n", p1->position->x, p1->position->y, p1->position->z, p1->velocity->x, p1->velocity->y, p1->velocity->z);


  //g01 = calc_force_grav(p0, p1);
  //printf("g01:(%f,%f,%f)\n", g01->x, g01->y, g01->z);
  //a01 = calc_accel(p0, g01);
  //p0->velocity = calc_velocity(a01, p0->velocity);
  //p0->position = vector3_add(p0->position, p0->velocity);
  //printf("p0: pos(%f,%f,%f), vel(%f,%f,%f)\n", p0->position->x, p0->position->y, p0->position->z, p0->velocity->x, p0->velocity->y, p0->velocity->z);
  //printf("p1: pos(%f,%f,%f), vel(%f,%f,%f)\n", p1->position->x, p1->position->y, p1->position->z, p1->velocity->x, p1->velocity->y, p1->velocity->z);
  //printf("radius %f\n", calc_radius(p0, p1));


  return 0;
}
