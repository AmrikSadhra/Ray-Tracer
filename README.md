#### PPM File format

1. Create 2D array of RGB Values and blit directly to file
2. Pass pointer to savePPM function
3. Write to array using Raytracer
4. Struct for RGB, typedef as colour


#### RayTracing Algorithm

```C
  for(HEIGHT){
    for(WIDTH){
      do for every ray:
        - Find closest ray/sphere intersection:
          - Iterate over every sphere

        - Check if we reach a lightsource from this point
          - Iterate over every lightsource
          - Find right colour

        - Either go with reflected ray or go to next pixel
    }
  }
```

### Lamberts Cosine Law

Radiant intensity observed from an ideal diffusely reflecting surface or ideal diffuse radiator is directly proportional to the cosine of the angle phi between the direction of the incident light and the surface normal.

##### Lambertian Reflectance

The property that defines an ideal "matte", the apparent intensity of the material is the same regardless of the angle of the observer to the surface normal.
In this model, light will be reflected equally in all directions from the point where the light hits the object.

```C
- For each lightsource that can be reached:
     * Calculate Lambert dot product with material reflection
     * Calculate each colour component, consisting of:
      - Lambert dot product result
      - Per colour intensity of the incoming light
```
