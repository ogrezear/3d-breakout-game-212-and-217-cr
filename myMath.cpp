#include "myMath.h"
double deg2rad(double angle)
{
	angle=(angle*PI)/180;
	return angle;
}

double rad2deg(double angle)
{
	angle=(angle*180)/PI;
	return angle;
}
