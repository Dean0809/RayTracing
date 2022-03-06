#ifndef CAMERA_H
#define CAMERA_H

#include "rtweekend.h"

class camera
{
private:
    point3 origin;
    point3 lowerLeftCorner;
    vec3 horizontal;
    vec3 vertical;
public:
    camera()
    {
        // Image
        auto aspectRatio = 16.0f / 9.0f;
        // Camera
        auto viewportHeight = 2.0f;
        auto viewportWidth = aspectRatio * viewportHeight;
        auto focal_length = 1.0f;

        origin = point3(0.0f, 0.0f, 0.0f);
        horizontal = vec3(viewportWidth, 0.0f, 0.0f);
        vertical = vec3(0.0f, viewportHeight, 0.0f);
        lowerLeftCorner = origin - horizontal / 2 - vertical / 2 - vec3(0, 0, focal_length);
    }

    ray get_ray(float u, float v) const
    {
        return ray(origin, lowerLeftCorner + u * horizontal + v * vertical - origin);
    }
};

#endif