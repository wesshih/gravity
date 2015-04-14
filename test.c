#include <stdio.h>
#include "util_space_3.h"

int main(int argc, char **argv) {
  printf("Vector Testing\n");

  Vec3 v1 = Vec3_make(1, 0, 0);
  Vec3 v2 = Vec3_make(0, 1, 0);

  Vec3 r1 = Vec3_add(v1, v2);
  Vec3 r2 = Vec3_cross(v1, v2);
  r1 = Vec3_add(r1, r2);

  printf("v1:\tx:%f\ty:%f\tz:%f\n", v1->x, v1->y, v1->z);
  printf("v2:\tx:%f\ty:%f\tz:%f\n", v2->x, v2->y, v2->z);
  printf("r1:\tx:%f\ty:%f\tz:%f\n", r1->x, r1->y, r1->z);
  printf("r2:\tx:%f\ty:%f\tz:%f\n", r2->x, r2->y, r2->z);

  return 0;
}
