//
// Created by Amrik on 23/11/2016.
//

#include <stdlib.h>
#include <math.h>
#include "Operators.h"

/*---- Constructor ----*/
ray *_rayConstructor(vector start, vector dir) {
    ray *myRay;

    myRay = malloc(sizeof(ray));
    myRay->start = start;
    myRay->dir = dir;

    return myRay;
}

sphere *_sphereConstructor(vector origin, float radius) {
    sphere *mySphere;

    mySphere = malloc(sizeof(ray));
    mySphere->origin = origin;
    mySphere->radius = radius;

    return mySphere;
}

vector *_vectorConstructor(float x, float y, float z) {
    vector *myVector;

    myVector = malloc(sizeof(vector));
    myVector->x = x;
    myVector->y = y;
    myVector->z = z;

    return myVector;
}

ray rayConstructor(vector start, vector dir) {
    ray myRay;

    myRay.start = start;
    myRay.dir = dir;

    return myRay;
}

sphere sphereConstructor(vector origin, float radius, int material) {
    sphere mySphere;

    mySphere.origin = origin;
    mySphere.radius = radius;
    mySphere.material = material;

    return mySphere;
}

vector vectorConstructor(float x, float y, float z) {
    vector myVector;

    myVector.x = x;
    myVector.y = y;
    myVector.z = z;

    return myVector;
}

bool intersectRaySphere(ray *r, sphere *s,  float *t) {
    //d.d
    float A = vectorDot(r->dir, r->dir);

    //Calculate (Po-C) distance (origin of ray and center of sphere)
    vector dist = vectorSub(r->start, s->origin);

    //2d.(Po-C)
    float B = 2 * vectorDot(r->dir, dist);

    //(Po-C)^2-r^2
    float C = vectorDot(dist, dist) - (s->radius * s->radius);

    //Calculate Discriminant
    float discrim = (B * B) - (4 * A * C);

    if(discrim < 0) return false;
    else return true;

   /* float discrim_root = sqrtf(discrim);
    float t0 = -B + discrim_root / (2);
    float t1 = -B - discrim_root / (2);*/

    //Get Closest solution
    //if(t0 > t1) t0 = t1;

  /*  *//* Verify t0 larger than 0 and less than the original t *//*
    if((t0 > 0.001f) && (t0 < *t)){
        *t = t0;
        return true;
    }else return false;*/
}

float vectorDot(vector vec1, vector vec2) {
    return (vec1.x * vec2.x) + (vec1.y * vec2.y) + (vec1.z * vec2.z);
}

vector vectorSub(vector vec1, vector vec2) {
    return vectorConstructor(vec1.x - vec2.x, vec1.y - vec2.y, vec1.z - vec2.z);
}


vector vectorAdd(vector *vec1, vector *vec2){
    return vectorConstructor(vec1->x + vec2->x, vec1->y + vec2->y, vec1->z + vec2->z);
}
/* Calculate Vector x Scalar and return resulting Vector*/
vector vectorScale(float c, vector *v){
    vector result = {v->x * c, v->y * c, v->z * c };
    return result;
}


