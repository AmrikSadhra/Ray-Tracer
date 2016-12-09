#include <stdio.h>
#include <math.h>
#include <windef.h>
#include "Operators.h"
#include "FileHandling.h"

#define WIDTH  800
#define HEIGHT 500

int main() {
    /*int radius = 10;
    vector sphereOrigin = vectorConstructor(20, 20, 20);
    sphere s = sphereConstructor(sphereOrigin, radius, 0);

    vector rayOrigin = vectorConstructor(0, 0, 0);
    vector rayDirec = vectorConstructor(0, 0, 1);
    ray r = rayConstructor(rayOrigin, rayDirec);*/


    ray r;

    material materials[3];
    materials[0].diffuse.r = 1;
    materials[0].diffuse.g = 0;
    materials[0].diffuse.b = 0;
    materials[0].reflection = 0.2;

    materials[1].diffuse.r = 0;
    materials[1].diffuse.g = 1;
    materials[1].diffuse.b = 0;
    materials[1].reflection = 0.5;

    materials[2].diffuse.r = 0;
    materials[2].diffuse.g = 0;
    materials[2].diffuse.b = 1;
    materials[2].reflection = 0.9;

    sphere spheres[3];
    spheres[0].origin.x = 200;
    spheres[0].origin.y = 300;
    spheres[0].origin.z = 0;
    spheres[0].radius = 100;
    spheres[0].material = 0;

    spheres[1].origin.x = 400;
    spheres[1].origin.y = 400;
    spheres[1].origin.z = 0;
    spheres[1].radius = 100;
    spheres[1].material = 1;

    spheres[2].origin.x = 500;
    spheres[2].origin.y = 140;
    spheres[2].origin.z = 0;
    spheres[2].radius = 100;
    spheres[2].material = 2;

    light lights[3];

    lights[0].pos.x = 0;
    lights[0].pos.y = 240;
    lights[0].pos.z = -100;
    lights[0].intensity.r = 1;
    lights[0].intensity.g = 1;
    lights[0].intensity.b = 1;

    lights[1].pos.x = 3200;
    lights[1].pos.y = 3000;
    lights[1].pos.z = -1000;
    lights[1].intensity.r = 0.6;
    lights[1].intensity.g = 0.7;
    lights[1].intensity.b = 1;

    lights[2].pos.x = 600;
    lights[2].pos.y = 0;
    lights[2].pos.z = -100;
    lights[2].intensity.r = 0.3;
    lights[2].intensity.g = 0.5;
    lights[2].intensity.b = 1;

    /* Will contain the raw image */
    unsigned char img[3 * WIDTH * HEIGHT];
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {

            float red = 0;
            float green = 0;
            float blue = 0;

            int level = 0;
            float coef = 1.0;

            r.start.x = x;
            r.start.y = y;
            r.start.z = -2000;

            r.dir.x = 0;
            r.dir.y = 0;
            r.dir.z = 1;
        }
    }

    saveppm("image.ppm", img, 800, 500);

    return 0;
}