#include "vector_3.h"
#include <math.h>
#include <stdlib.h>

// makes V
Vec3 Vec3_make(float x, float y, float z) {
  Vec3 v = (Vec3)(malloc(sizeof(float)*3));
  if (v == NULL) return NULL;
  v->x = x;
  v->y = y;
  v->z = z;
  return v;
}

// frees v
int Vec3_free(Vec3 v) {
  free(v);
  if (v != NULL) return -1;
  return 0;
}

// will test if res is a valid vector, if so then will be overwritten
// if res is NULL then it will make it
Vec3 Vec3_add(Vec3 v1, Vec3 v2) {
  if (v1 == NULL || v2 == NULL) return NULL;
  float x = v1->x + v2->x;
  float y = v1->y + v2->y;
  float z = v1->z + v2->z;
  return Vec3_make(x, y, z);
}

// subtract
Vec3 Vec3_sub(Vec3 v1, Vec3 v2) {
  if (v1 == NULL || v2 == NULL) return NULL;
  float x = v1->x - v2->x;
  float y = v1->y - v2->y;
  float z = v1->z - v2->z;
  return Vec3_make(x, y, z);
}

// dot product
float Vec3_dot(Vec3 v1, Vec3 v2) {
  if (v1 == NULL || v2 == NULL) return -1;
  return (v1->x*v2->x) + (v1->y*v2->y) + (v1->z*v2->z);
}

// cross product
Vec3 Vec3_cross(Vec3 v1, Vec3 v2) {
  if (v1 == NULL || v2 == NULL) return NULL;
  float x = (v1->y*v2->z) - (v1->z*v2->y);
  float y = (v1->z*v2->x) - (v1->x*v2->z);
  float z = (v1->x*v2->y) - (v1->y*v2->x);
  return Vec3_make(x, y, z);
}

// multiply by scalar
Vec3 Vec3_scale(Vec3 v, float scalar) {
  if (v == NULL) return NULL;
  float x = v->x*scalar;
  float y = v->y*scalar;
  float z = v->z*scalar;
  return Vec3_make(x, y, z);
}

// normalize vector
Vec3 Vec3_norm(Vec3 v) {
  if (v == NULL) return NULL;
  return Vec3_scale(v, 1/Vec3_mag(v));
}

// return the magnitude
float Vec3_mag(Vec3 v) {
  return 1.0;
  //return pow(pow(v->x, 2)+pow(v->y, 2)+pow(v->z,2), 0.5);
}
