#ifndef MATHS_H
#define MATHS_H
#include <stdint.h>
/***********Add to config file header************/
/*
//Maths Library
#define MATHS_MAJOR	0
#define MATHS_MINOR	1
#define MATHS_PATCH	0
*/

/***************Add to config file***************/
/*
#ifndef MATHS_LIBRARY
	#error "You need to include the Maths library for this code to compile"
#endif
 */

/************* Semantic Versioning***************/
#define MATHS_LIBRARY

/*************   Magic  Numbers   ***************/
/*************    Enumeration     ***************/
/*************    Structures      ***************/
/***********State Machine Definitions************/
/*************Function  Prototypes***************/
/**
 * Using y = mx + b, this function interpolates a point between two other points\
	This function uses integer arithmetic to avoid floating point numbers, it has an autocorrecting feature so that it doesn't lose resolution (16 384, apparently longs don't like non-shifting aritmetic)
 * @param x1 First x coordinate
 * @param x2 Second x coordinate
 * @param y1 First y coordinate
 * @param y2 Second y coordinate
 * @param x The X location that we want to know the value of Y
 * @return The Y that corresponds to the given X
 */
int Interpolate_Point(int x1, int x2, int y1, int y2, int x);

/**
 * Using y = mx + b, this function allows interpolation AND extrapolation of a point compared to two other points\
	This function uses integer arithmetic to avoid floating point numbers, it has an autocorrecting feature so that it doesn't lose resolution
 * @param x1 First x coordinate
 * @param x2 Second x coordinate
 * @param y1 First y coordinate
 * @param y2 Second y coordinate
 * @param x The X location that we want to know the value of Y
 * @return The Y that corresponds to the given X
 */
int Extrapolate_Point(int x1, int x2, int y1, int y2, int x);

int8_t Solve_Quadratic(float A, float B, float C, float *PlusX, float *MinusX);

#endif
