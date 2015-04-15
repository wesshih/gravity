#ifndef READ_PART_H
#define READ_PART_H

#include <stdio.h>
#include "particle.h"
#include "vector3.h"


// deals with reading in .part files
// given a file.part it returns a pointer to an array of particles
struct particle ** read_part(char *filename, int *p_num) {

  if (filename == NULL) return NULL; // must have a file to open
  FILE *fp;
  fp = fopen(filename, "r");
  if (fp == NULL) return NULL; // could not open file

  char part_file[4]; // default buffer size of 64?
  fscanf(fp, "%c", &part_file[0]);
  fscanf(fp, "%c", &part_file[1]);
  fscanf(fp, "%c", &part_file[2]);
  fscanf(fp, "%c", &part_file[3]);
  if (part_file[0] != 'P' || part_file[1] != 'A' || part_file[2] != 'R' || part_file[3] != 'T') {
    printf("This is not a part file. Returning NULL\n");
    return NULL;
  }

  // we now are sure we are reading from a part file. hopefully it is formatted properly
  int num_part, i;
  fscanf(fp, "%d", &num_part);
  printf("there are %d number of particles in file\n", num_part);

  // create this array of particle pointers
  struct particle **ps = (struct particle **)malloc(sizeof(struct particle *)*num_part);

  for (i = 0; i < num_part; i++) {
    unsigned long m;
    double r, px, py, pz, vx, vy, vz;
    fscanf(fp, "%lu %lf %lf %lf %lf %lf %lf %lf", &m, &r, &px, &py, &pz, &vx, &vy, &vz);
    printf("part %d -> m:%lu r:%lf px:%lf py:%lf pz:%lf vx:%lf vy:%lf vz:%lf\n", i, m, r, px, py, pz, vx, vy, vz);
    ps[i] = particle_new(m, r, vector3_new(px, py, pz), vector3_new(vx, vy, vz));
  }
  *p_num = num_part;
  return ps;
}

#endif
