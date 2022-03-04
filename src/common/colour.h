#ifndef COLOUR_H
#define COLOUR_H

#include "vec3.h"
#include <iostream>

void write_colour(std::ostream &out, colour pixel_colour)
{
    out << static_cast<int>(255.999 * pixel_colour[0]) << ' '
        << static_cast<int>(255.999 * pixel_colour[1]) << ' '
        << static_cast<int>(255.999 * pixel_colour[2]) << '\n';
}

#endif COLOUR_H