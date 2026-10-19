#ifndef CTRL_MATH_H_
#define CTRL_MATH_H_

#include <stdbool.h>
#include <math.h>
#include "adas_types.h"

#define MATH_EPSILON  (1e-6)
#define MATH_PI       3.14159265358979323846   // pi
#define MATH_PI_2     1.57079632679489661923   // pi/2
#define MATH_PI_4     0.785398163397448309616  // pi/4
#define MATH_1_PI     0.318309886183790671538  // 1/pi
#define MATH_2_PI     0.636619772367581343076  // 2/pi
#define MATH_2PI      (2*MATH_PI)              // 2pi

#define sq(x) ((x)*(x))

static inline bool CloseEnough(float f1, float f2)
{
    return fabsf(f1 - f2) < MATH_EPSILON;
}

static inline float GetDistance(float x0, float y0, float x1, float y1)
{
    return sqrtf(powf(x1 - x0, 2) + powf(y1 - y0, 2));
}

static inline float RadToDeg(float rad)
{
    return rad / MATH_PI * 180;
}

static inline float DegToRad(float deg)
{
    return deg / 180 * MATH_PI;
}

//change the angle to [0, 2*PI]
static inline float RoundAngle(float angle)
{
    double result = fmod(angle, MATH_2PI);
    return result < 0 ? (result + MATH_2PI) : result;
}

//Normalize angle to [-PI, PI).
static inline float NormalizeAngle(float angle)
{
    double a = fmod(angle + MATH_PI, MATH_2PI);
    if (a < 0.0)
    {
        a += MATH_2PI;
    }
    return a - MATH_PI;
}

static inline float Rotate180Angle(float angle)
{
    return RoundAngle(angle + MATH_PI);
}

#endif //CTRL_MATH_H_
