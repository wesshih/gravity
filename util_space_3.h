#ifndef UTIL_SPACE_3_H
#define UTIL_SPACE_3_H

// This util file has vectors and matricies associated with 3 space
// I am specifically defining 3 space here, in hopes that further down
// the road i switch to 4 space and do real gravity

typedef struct vector3_struct {
  float x, y, z;
} *Vec3;

typedef struct matrix_3x3_struct {
  Vec3  r1, r2, r3, c1, c2, c3;
} *M3x3;

// Vector only fns
Vec3 make_Vec3(float x, float y, float z);
float dot(Vec3 v1, Vec3 v2);
Vec3 cross(Vec3 v1, Vec3 v2);
//Vec3 Vec3_scale(Vec3 v, float scalar);
//Vec3 Vec3_norm(Vec3 v);
//float Vec3_mag(Vec3 v);

// Matrix only fns
M3x3 make_M3x3(Vec3 c1, Vec3 c2, Vec3 c3);
M3x3 make_M3x3(Vec3 r1, Vec3 r2, Vec3 r3);

// shared math fns
Vec3 add(Vec3 v1, Vec3 v2);
M3x3 add(M3x3 m1, M3x3 m2);
Vec3 sub(Vec3 v1, Vec3 v2);
M3x3 sub(M3x3 m1, M3x3 m2);
M3x3 mul(M3x3 m1, M3x3 m2);
Vec3 mul(Vec3 v1, M3x3 m2);
M3x3 transpose(M3x3 m);

Vec3 scale(Vec3 v, float scalar);
Vec3 norm(Vec3 v);
float mag(Vec3 v);

#endif
