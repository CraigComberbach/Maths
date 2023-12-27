#include <math.h>
#include "Maths.h"

//Using y = mx + b, this function interpolates a point between two other points
//y is the interpolated value, m is the slope, b is the offset and x is the known value along the x axis
//Slope of a line is equal to rise over run, or m = (y1-y2) / (x1-x2)
//Offset of a line is found by rearranging y=mx+b into b=y-mx (I use x1 and y1 as the X and Y values)
//This function uses integer arithmetic to avoid floating point numbers, it has an autocorrecting feature so that it doesn't lose resolution (16 384, apparently longs don't like non-shifting aritmetic)
int Interpolate_Point(int x1, int x2, int y1, int y2, int x)
{
	int y; //Interpolated value

	//Extrapolate the points - We will range check to make sure it is an interpolation
	y = Extrapolate_Point(x1, x2, y1, y2, x);

	//Range check the interpolated value
	if((y > y1) && (y > y2))//Above both in the range
	{
		//Replace with the bigger of the two variables
		if(y1 > y2)
			y = y1;
		else
			y = y2;
	}
	else if((y < y1) && (y < y2))//Below both in the range
	{
		//Replace with the lower of the two variables
		if(y1 < y2)
			y = y1;
		else
			y = y2;
	}

	return (int)y; //Return the interpolated point
}

//Using y = mx + b, this function allows interpolation AND extrapolation of a point compared to two other points
//y is the inter/extrapolated value, m is the slope, b is the offset and x is the known value along the x axis
//Slope of a line is equal to rise over run, or m = (y1-y2) / (x1-x2)
//Offset of a line is found by rearranging y=mx+b into b=y-mx (I use x1 and y1 as the X and Y values, though x2/y2 would work just as well)
//This function uses integer arithmetic to avoid floating point numbers, it has an autocorrecting feature so that it doesn't lose resolution (*/ 16384)
int Extrapolate_Point(int x1, int x2, int y1, int y2, int x)
{
	long y; //Extrapolated value
	long m; //Slope of the line between the two points
	long b; //Offset of the line between the two points

	//Calculate Slope?
//	m = ((y1 - y2) * 16384) / (x1 - x2);
	m = y1 - y2;
	m *= 16384;
	m /= x1 - x2;

	//Calculate the Offset?
//	b = y1 - (m * x1) / 16384;
	b = m * x1;
	b /= 16384;
	b = y1 - b;

	//Interpolate?
//	y = (m * x) / 16384 + b;
	y = m * x;
	y /= 16384;
	y += b;

	//Since we are allowing extrapolation, we can't do any range checks on this
	return (int)y; //Return the polated point
}

int8_t Solve_Quadratic(float A, float B, float C, float *PlusX, float *MinusX)
{
    int8_t NumberOfRealRoots = 0;;
    float Descriminant;

    Descriminant = B * B - 4 * A * C;

    if(Descriminant < 0)
    {
        NumberOfRealRoots = 0;
    }
    else
    {
        *PlusX = (float)sqrt(Descriminant);

        *PlusX = (-B + *PlusX) / (2 * A);
        *MinusX = (-B - *PlusX) / (2 * A);

        if(D > 0)
        {
            NumberOfRealRoots = 2;
        }
        else
        {
            *MinusX = *PlusX;
            NumberOfRealRoots = 1;
        }
    }

    return NumberOfRealRoots;
}
