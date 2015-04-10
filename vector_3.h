#ifndef VECTOR_3_H
#define VECTOR_3_H

typedef struct vector3_struct {
  float x, y, z, t;
} *Vec3;

Vec3 Vec3_make(float x, float y, float z);
int Vec3_free(Vec3 v);
Vec3 Vec3_add(Vec3 v1, Vec3 v2);
Vec3 Vec3_sub(Vec3 v1, Vec3 v2);
float Vec3_dot(Vec3 v1, Vec3 v2);
Vec3 Vec3_cross(Vec3 v1, Vec3 v2);
Vec3 Vec3_scale(Vec3 v, float scalar);
Vec3 Vec3_norm(Vec3 v);
float Vec3_mag(Vec3 v);

#endif
