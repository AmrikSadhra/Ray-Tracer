//
// Created by Amrik on 23/11/2016.
//

#ifndef RAY_TRACER_OPERATORS_H
#define RAY_TRACER_OPERATORS_H

#include <stdbool.h>

/* ---- Structures ----- */
typedef struct vector {
    float x,y,z;
} vector;

typedef struct ray {
    vector start;
    vector dir;
} ray;

typedef struct sphere {
    vector origin;
    float radius;
    int material;
} sphere;

typedef struct{
    float r, g, b;
}colour;

typedef struct{
    vector pos;
    colour intensity;
} light;

typedef struct{
    colour diffuse;
    float reflection;
} material;

/* ---- Constructors ----- */
vector vectorConstructor(float x, float y, float z);
ray rayConstructor(vector start, vector dir);
sphere sphereConstructor(vector origin, float radius, int material);

/* ---- Vector Operators ----- */
float vectorDot(vector vec1, vector vec2);
vector vectorSub(vector vec1, vector vec2);
vector vectorScale(float c, vector *v);
vector vectorAdd(vector *vec1, vector *vec2);

bool intersectRaySphere(ray *r, sphere *s, float *t);

#endif //RAY_TRACER_OPERATORS_H
