#ifndef MATRIX_3X3
#define MATRIX_3X3

typedef struct matrix_3x3_struct {
  Vec3 c1, c2, c3;
} *M3x3;

M3x3 M3x3_make(Vec3 c1, Vec3 c2, Vec3 c3);
M3x3 M3x3_free(M3x3 m);


#endif
