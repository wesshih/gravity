#ifndef VECTOR3_H
#define VECTOR3_H

struct vector3 {
  float x, y, z;
};

struct vector3 * vector3_new(float x, float y, float z);
struct vector3 * vector3_add(struct vector3 *v1, struct vector3 *v2);
struct vector3 * vector3_sub(struct vector3 *v1, struct vector3 *v2);
float vector3_dot(struct vector3 *v1, struct vector3 *v2);
struct vector3 * vector3_cross(struct vector3 *v1, struct vector3 *v2);
struct vector3 * vector3_scale(struct vector3 *v, float scalar);
struct vector3 * vector3_norm(struct vector3 *v);
float vector3_mag(struct vector3 *v);

#endif
