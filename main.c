#include <stdio.h>
#include <math.h>
#include "Operators.h"
#include "FileHandling.h"

#define WIDTH  800
#define HEIGHT 500


int main(int argc, char *argv[]){
    //Image buffer
    unsigned char img[3*WIDTH*HEIGHT];

    sphere s;
    ray r;

    int x,y;

    /* Intersect ray/sphere or not */
    bool hit;

    /* Position the sphere */
    s.origin.x = 500;
    s.origin.y = 200;
    s.origin.z = 100;

    /* Sphere radius */
    s.radius = 100;

    /* Direction of the ray */
    r.dir.x = 0;
    r.dir.y = 0;
    r.dir.z = 1;

    /* Start position of the ray */
    r.start.z = 0;

    /* Iterate over 'screen' */
    for(y=0;y<HEIGHT;y++){
        /* Set the y-coordinate of the start position of the ray */
        r.start.y = y;
        for(x=0;x<WIDTH;x++){
            /* Set the x-coordinate of the start position of the ray */
            r.start.x = x;

            float t = 100;
            /* Check if the ray hits sphere */
            hit = intersectRaySphere(&r, &s, &t);
            if(hit){
                img[(x + y*WIDTH)*3 + 0] = 0;
                img[(x + y*WIDTH)*3 + 1] = 255;
                img[(x + y*WIDTH)*3 + 2] = 0;
            }else{
                img[(x + y*WIDTH)*3 + 0] = 0;
                img[(x + y*WIDTH)*3 + 1] = 0;
                img[(x + y*WIDTH)*3 + 2] = 0;
            }
        }
    }

    saveppm("image.ppm", img, WIDTH, HEIGHT);

    return 0;
}