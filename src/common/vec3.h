#ifndef VEC3_H
#define VEC3_H

#include <cmath>
#include <iostream>
#include <iomanip>

class vec3
{
public:
    // the coordinates
    float x, y, z;

    // constructors
    vec3(): x(0.f), y(0.f), z(0.f) {}
    vec3(float X, float Y, float Z): x(X), y(Y), z(Z) {}
    vec3(const vec3 &other): x(other.x), y(other.y), z(other.z) {}

    // eqaulity operator
    bool operator ==(const vec3 &other) const 
    { 
        return ((x == other.x) && (y == other.y) && (z == other.z));
    }

    // addition operator
    vec3 operator +(const vec3 &other) const
    {
        vec3 result(x + other.x, y + other.y, z + other.z);
        return result;
    }

    // subtraction operator
    vec3 operator -(const vec3 &other) const
    {
        vec3 result(x - other.x, y - other.y, z - other.z);
        return result;
    }

    // subtraction operator
    vec3 operator -() const
    {
        vec3 result(-x, -y, -z);
        return result;
    }
    // multiplication operator
    vec3 operator *(float factor) const
    {
        vec3 result(x * factor, y * factor, z * factor);
        return result;
    }

    // division operator
    vec3 operator /(float factor) const
    {
        vec3 result(x / factor, y / factor, z / factor);
        return result;
    }

    vec3 operator +=(const vec3 &other) const
    {
        vec3 result(x + other.x, y + other.y, z + other.z);
        return result;
    }

    vec3 operator -=(const vec3 &other) const
    {
        vec3 result(x - other.x, y - other.y, z - other.z);
        return result;
    }

    // dot product routine
    float dot(const vec3 &other) const
    {
        float result = x * other.x + y * other.y + z * other.z;
        return result;
    }

    // cross product routine
    vec3 cross(const vec3 &other) const
    {
        vec3 result(y * other.z - z * other.y, z * other.x - x * other.z, x * other.y - y * other.x );
        return result;
    }

    // routine to find the length
    float length() const
    {
        return sqrt(x * x + y * y + z * z);
    }

    // normalisation routine
    vec3 normalize() const
    {
        float len = length();
        vec3 result(x / len, y / len, z / len);
        return result;
    }

    // operator that allows us to use array indexing instead of variable names
    float &operator [] (const int index)
    {
        switch (index)
        {
        case 0:
            return x;
        case 1:
            return y;
        case 2:
            return z;
        default:
            return x;
        }
    }

    const float &operator [] (const int index) const
    {
        switch (index)
        {
        case 0:
            return x;
        case 1:
            return y;
        case 2:
            return z;
        default:
            return x;
        }
    }
};

// mutiplication operator
vec3 operator *(float factor, const vec3 &right)
{
    return right * factor;
}

// stream input
std::istream & operator >> (std::istream &inStream, vec3 &value)
{
    inStream >> value.x >> value.y >> value.z;
    return inStream;
}

// stream output
std::ostream & operator << (std::ostream &outStream, const vec3 &value)
{
    outStream << std::setprecision(4) <<  value.x << " " << std::setprecision(4) << value.y << " " << std::setprecision(4) << value.z;
    return outStream;
}

using point3 = vec3;
using colour = vec3;

#endif