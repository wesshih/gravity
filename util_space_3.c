#include "util_space_3.h"
#include <math.h>
#include <stdlib.h>


//M3x3 make_M3x3(Vec3 r1, Vec3 r2, Vec3 r3);
//
//// shared math fns
//Vec3 add(Vec3 v1, Vec3 v2);
//M3x3 add(M3x3 m1, M3x3 m2);
//Vec3 sub(Vec3 v1, Vec3 v2);
//M3x3 sub(M3x3 m1, M3x3 m2);
//M3x3 mul(M3x3 m1, M3x3 m2);
//Vec3 mul(Vec3 v1, M3x3 m2);
//M3x3 transpose(M3x3 m);
//
//// maybe leave these in
//Vec3 scale(Vec3 v, float scalar);
//Vec3 norm(Vec3 v);
//float mag(Vec3 v);

// makes Vec
Vec3 make_Vec3(float x, float y, float z) {
  Vec3 v = (Vec3)(malloc(sizeof(Vec3));
  if (v == NULL) return NULL;
  v->x = x;
  v->y = y;
  v->z = z;
  return v;
}

M3x3 make_M3x3(Vec3T c1, Vec3T c2, Vec3T c3) {
  M3x3 m = (M3x3)malloc(sizeof(M3x3));
  if (m == NULL) return NULL;
  m->c1 = c1;
  m->c2 = c2;
  m->c3 = c3;
  m->r1 = make_Vec3(c1->x, c2->x, c3->x);
  m->r2 = make_Vec3(c1->y, c2->y, c3->y);
  m->r3 = make_Vec3(c1->z, c2->z, c3->z);
  return m;
}

Vec3 add(Vec3 v1, Vec3 v2) {
  if (v1 == NULL || v2 == NULL) return NULL;
  float x = v1->x + v2->x;
  float y = v1->y + v2->y;
  float z = v1->z + v2->z;
  return make_Vec3(x, y, z);
}

M3x3 add(M3x3 m1, M3x3 m2) {
  if (m1 == NULL || m2 == NULL) return NULL;
  Vec3 c1 = add(m1->c1, m2->c1);
  Vec3 c2 = add(m1->c2, m2->c2);
  Vec3 c3 = add(m1->c3, m2->c3);
  return make_M3x3(c1, c2, c3);
}

Vec3 Vec3_sub(Vec3 v1, Vec3 v2) {
  if (v1 == NULL || v2 == NULL) return NULL;
  float x = v1->x - v2->x;
  float y = v1->y - v2->y;
  float z = v1->z - v2->z;
  return make_Vec3(x, y, z);
}

M3x3 sub(M3x3 m1, M3x3 m2) {
  if (m1 == NULL || m2 == NULL) return NULL;
  Vec3 c1 = sub(m1->c1, m2->c1);
  Vec3 c2 = sub(m1->c2, m2->c2);
  Vec3 c3 = sub(m1->c3, m2->c3);
  return make_M3x3(c1, c2, c3);
}

// dot product
float dot(Vec3 v1, Vec3 v2) {
  if (v1 == NULL || v2 == NULL) return -1;
  return (v1->x*v2->x) + (v1->y*v2->y) + (v1->z*v2->z);
}

// cross product
Vec3 cross(Vec3 v1, Vec3 v2) {
  if (v1 == NULL || v2 == NULL) return NULL;
  float x = (v1->y*v2->z) - (v1->z*v2->y);
  float y = (v1->z*v2->x) - (v1->x*v2->z);
  float z = (v1->x*v2->y) - (v1->y*v2->x);
  return make_Vec3(x, y, z);
}

M3x3 mul(M3x3 m1, M3x3 m2) {
  if (m1 == NULL || m2 == NULL) return NULL;
  //Vec3 c1 = make_Vec3
  return NULL;//make_M3x3(c1, c2, c3);
}

// multiply by scalar
Vec3 scale(Vec3 v, float scalar) {
  if (v == NULL) return NULL;
  float x = v->x*scalar;
  float y = v->y*scalar;
  float z = v->z*scalar;
  return make_Vec3(x, y, z);
}

// normalize vector
Vec3 norm(Vec3 v) {
  if (v == NULL) return NULL;
  return make_Vec3(v, 1/mag(v));
}

// return the magnitude
float mag(Vec3 v) {
  return 1.0;
  //return pow(pow(v->x, 2)+pow(v->y, 2)+pow(v->z,2), 0.5);
}
