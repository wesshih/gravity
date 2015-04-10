#ifndef UTIL_SPACE_3_H
#define UTIL_SPACE_3_H

// This util file has vectors and matricies associated with 3 space
// I am specifically defining 3 space here, in hopes that further down
// the road i switch to 4 space and do real gravity

typedef struct vector3_struct {
  float x, y, z, t;
} *Vec3;

typedef struct matrix_3x3_struct {
  Vec3 c1, c2, c3;
} *M3x3;

// Vector functions
Vec3 Vec3_make(float x, float y, float z);
int Vec3_free(Vec3 v);
Vec3 Vec3_add(Vec3 v1, Vec3 v2);
Vec3 Vec3_sub(Vec3 v1, Vec3 v2);
float Vec3_dot(Vec3 v1, Vec3 v2);
Vec3 Vec3_cross(Vec3 v1, Vec3 v2);
Vec3 Vec3_scale(Vec3 v, float scalar);
Vec3 Vec3_norm(Vec3 v);
float Vec3_mag(Vec3 v);

// Matrix functions
M3x3 M3x3_make(Vec3 c1, Vec3 c2, Vec3 c3);
M3x3 M3x3_free(M3x3 m);


#endif
