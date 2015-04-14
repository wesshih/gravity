#include "vector3.h"
#include <math.h>
#include <stdlib.h>

// makes V
struct vector3 * vector3_new(float x, float y, float z) {
  struct vector3 * v = (struct vector3 *)(malloc(sizeof(float)*3));
  if (v == NULL) return NULL;
  v->x = x;
  v->y = y;
  v->z = z;
  return v;
}

// add
struct vector3 * vector3_add(struct vector3 *v1, struct vector3 *v2) {
  if (v1 == NULL || v2 == NULL) return NULL;
  return vector3_new((v1->x + v2->x), (v1->y + v2->y), (v1->z + v2->z));
}

// subtract
struct vector3 * vector3_sub(struct vector3 *v1, struct vector3 *v2) {
  if (v1 == NULL || v2 == NULL) return NULL;
  return vector3_new((v1->x - v2->x), (v1->y - v2->y), (v1->z - v2->z));
}

// dot product
float vector3_dot(struct vector3 *v1, struct vector3 *v2) {
  if (v1 == NULL || v2 == NULL) return -1;
  return (v1->x*v2->x) + (v1->y*v2->y) + (v1->z*v2->z);
}

// cross product
struct vector3 * vector3_cross(struct vector3 *v1, struct vector3 *v2) {
  if (v1 == NULL || v2 == NULL) return NULL;
  float x = (v1->y*v2->z) - (v1->z*v2->y);
  float y = (v1->z*v2->x) - (v1->x*v2->z);
  float z = (v1->x*v2->y) - (v1->y*v2->x);
  return vector3_new(x, y, z);
}

// multiply by scalar
struct vector3 * vector3_scale(struct vector3 *v, float scalar) {
  if (v == NULL) return NULL;
  float x = v->x*scalar;
  float y = v->y*scalar;
  float z = v->z*scalar;
  return vector3_new(x, y, z);
}

// normalize vector
struct vector3 * vector3_norm(struct vector3 *v) {
  if (v == NULL) return NULL;
  return vector3_scale(v, 1/vector3_mag(v));
}

// return the magnitude
float vector3_mag(struct vector3 *v) {
  //return 1.0;
  return pow(pow(v->x, 2)+pow(v->y, 2)+pow(v->z,2), 0.5);
}
