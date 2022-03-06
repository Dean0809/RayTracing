#ifndef COLOUR_H
#define COLOUR_H

#include "rtweekend.h"
#include <iostream>

void write_colour(std::ostream &out, colour pixel_colour, int samples_per_pixel)
{
    auto r = pixel_colour[0];
    auto g = pixel_colour[1];
    auto b = pixel_colour[2];

    // Divide the color by the number of samples.
    auto scale = 1.0 / samples_per_pixel;
    r *= scale;
    g *= scale;
    b *= scale;

    out << static_cast<int>(255.999 * clamp(r, 0.0, 0.999)) << ' '
        << static_cast<int>(255.999 * clamp(g, 0.0, 0.999)) << ' '
        << static_cast<int>(255.999 * clamp(b, 0.0, 0.999)) << '\n';
}

#endif COLOUR_H