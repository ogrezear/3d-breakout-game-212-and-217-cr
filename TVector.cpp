#include "main.h"


TVector::TVector(void)
{
	_x=0;
	_y=0;
	_z=0;
	}
TVector::TVector(double x, double y, double z)
{
	_x=x;
	_y=y;
	_z=z;
}

TVector::~TVector(void)
{
}
TVector TVector::unit()
{
	double x,y,z;
	double mag;
	mag=magnitude(); // get the vector magnitude
	x=_x/mag; // normalize each component
	y=_y/mag;
	z=_z/mag;
	return TVector(x,y,z); //return a TVector type item
}
double TVector::magnitude()
{
	return sqrt(pow(_x,2)+pow(_y,2)+pow(_z,2)); //directly return the calculated magnitude without storing it
}
void TVector::invert()
{
	//invert each component
	_x=-_x;
	_y=-_y;
	_z=-_z;
}
void TVector::print()
{
	cout<<_x<<" "<<_y<<" "<<_z<<endl; //print each component of the vector
	//this function is used for testing purposes
}
TVector TVector::add(TVector v1, TVector v2)
{
	double x,y,z;
	//add each component from the 2 vectors
	x=v1._x+v2._x;
	y=v1._y+v2._y;
	z=v1._z+v2._z;
	return TVector(x,y,z); //return TVector type item
}
TVector TVector::subtract(TVector v1, TVector v2)
{
	//subtract each component from the 2 vectors
	double x,y,z;
	x=v1._x-v2._x;
	y=v1._y-v2._y;
	z=v1._z-v2._z;
	return TVector(x,y,z);
}
double TVector::dotProduct(TVector v1, TVector v2)
{
	double result;
	result=v1._x*v2._x+v1._y*v2._y+v1._z*v2._z; //calculate result and the return
	return result;
}
double TVector::dotProduct(TVector v1, TVector v2,double angle)
{
	angle=angle*PI/180; // Transform the angle in radians
	return v1.magnitude()*v2.magnitude()*cos(angle);
}
double TVector::getAngle(TVector v1,TVector v2)
{
	double angle;
	angle=acos(TVector::dotProduct(v1.unit(),v2.unit())); //calculate the angle in radians
	angle=angle*180/PI; // transform the angle in degrees
	return angle;
}
TVector TVector::crossProductP(TVector v1, TVector v2)
{
	double x,y,z;
	//calculate each component
	x=abs(v1._y)*abs(v2._z)-abs(v1._z)*abs(v2._y);
	y=abs(v1._z)*abs(v2._x)-abs(v1._x)*abs(v2._z);
	z=abs(v1._x)*abs(v2._y)-abs(v1._y)*abs(v2._x);
	return TVector(x,y,z);
}
TVector TVector::crossProduct(TVector v1, TVector v2)
{
	double x,y,z;
	//calculate each component
	x=v1._y*v2._z-v1._z*v2._y;
	y=v1._z*v2._x-v1._x*v2._z;
	z=v1._x*v2._y-v1._y*v2._x;
	return TVector(x,y,z);
}
TVector TVector::multiply(TVector v1, double s)
{
	TVector v2;
	//multiply each component with a scalar
	v2._x=v1._x*s;
	v2._y=v1._y*s;
	v2._z=v1._z*s;
	return v2;
}
double TVector::scalarTripleProduct(TVector v1, TVector v2, TVector v3)
{
	double stp;
	//calculate the dot product between a vector and the cross product of the other 2 vectors
	stp=dotProduct(v1,crossProduct(v2,v3));
	return stp;
}
TVector TVector::normalCalc(TVector v1,TVector v2,TVector v3)
{ 
TVector n;
n=((v1-v3)*(v2 - v3)).unit();
return n;
}