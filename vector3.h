#ifndef VECTOR3_H
#define VECTOR3_H

struct vector3 {
  double x, y, z;
};

struct vector3 * vector3_new(double x, double y, double z);
struct vector3 * vector3_add(struct vector3 *v1, struct vector3 *v2);
struct vector3 * vector3_sub(struct vector3 *v1, struct vector3 *v2);
double vector3_dot(struct vector3 *v1, struct vector3 *v2);
struct vector3 * vector3_cross(struct vector3 *v1, struct vector3 *v2);
struct vector3 * vector3_scale(struct vector3 *v, double scalar);
struct vector3 * vector3_norm(struct vector3 *v);
double vector3_mag(struct vector3 *v);

#endif
