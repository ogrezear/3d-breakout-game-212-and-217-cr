#include "main.h"
#include "myMath.h"


Tbrick::Tbrick(void)
{
}

Tbrick::Tbrick(double angle, double radius, double outRadius,double row)
{
	_angle=deg2rad(angle);
	_radius=radius;
	_height=0.2;
	_outRadius=outRadius;
	_row=row;
	Tbrick::makeBrick();
}

Tbrick::~Tbrick(void)
{
}

void Tbrick::makeBrick()
{
	double deg20;//20 degree angle to be converted to radians
	deg20=deg2rad(20);
	int i;
	//generate lower front points
	for(i=0;i<4;i++){
		_points[i]._x=_radius*cos(_angle+i*deg20);
		_points[i]._z=_radius*sin(_angle+i*deg20);
		_points[i]._y=_row*_height;
		}
	//generate lower back
	for(i=7;i>=4;i--){
		_points[i]._x=_points[i-4]._x*(_outRadius/_radius);
		_points[i]._z=_points[i-4]._z*(_outRadius/_radius);
		_points[i]._y=_row*_height;
	}
	//generate upper points(front and back)
	for(i=8;i<=15;i++){
		_points[i]._x=_points[i-8]._x;
		_points[i]._z=_points[i-8]._z;
		_points[i]._y=_points[i-8]._y+_height;
	}
}

void Tbrick::draw()
{
//draw the front face
glBegin(GL_QUAD_STRIP);
for(int i=0;i<=3;i++){
if(i==3) glNormal3f(_normal[2].X(), _normal[2].Y(), _normal[2].Z());
else{ _normal[i] = ((_points[i+8] - _points[i])*(_points[i+1] - _points[i])).unit();
glNormal3f(_normal[i]._x, _normal[i]._y, _normal[i]._z);}
// Construct a quad

glVertex3f(_points[i].X(), _points[i].Y(), _points[i].Z());
glVertex3f(_points[i+8].X(), _points[i+8].Y(), _points[i+8].Z());
}
glEnd();

//draw the back face
glBegin(GL_QUAD_STRIP);
for(int i=4;i<=7;i++){
if(i==7) glNormal3f(_normal[6].X(), _normal[6].Y(), _normal[6].Z());
else{ _normal[i] = ((_points[i+8] - _points[i])*(_points[i+1] - _points[i])).unit();
glNormal3f(_normal[i]._x, _normal[i]._y, _normal[i]._z);}
//construct a quad
glVertex3f(_points[i].X(), _points[i].Y(), _points[i].Z());
glVertex3f(_points[i+8].X(), _points[i+8].Y(), _points[i+8].Z());
}
glEnd();

//draw the top face
glBegin(GL_QUAD_STRIP);
for(int i=8;i<=11;i++){
if(i==11) glNormal3f(_normal[10].X(), _normal[10].Y(), _normal[10].Z());
else{ _normal[i] = ((_points[i+4] - _points[i])*(_points[i+1] - _points[i])).unit();
glNormal3f(_normal[i]._x, _normal[i]._y, _normal[i]._z);}
//construct a quad
glVertex3f(_points[i].X(), _points[i].Y(), _points[i].Z());
glVertex3f(_points[i+4].X(), _points[i+4].Y(), _points[i+4].Z());
}
glEnd();

//draw the side faces
glBegin(GL_QUAD_STRIP);
_normal[7] = ((_points[8] - _points[0])*(_points[4] - _points[0])).unit();
glNormal3f(_normal[7]._x, _normal[7]._y, _normal[7]._z);
glVertex3f(_points[0].X(), _points[0].Y(), _points[0].Z());
glVertex3f(_points[4].X(), _points[4].Y(), _points[4].Z());
glNormal3f(_normal[7]._x, _normal[7]._y, _normal[7]._z);
glVertex3f(_points[8].X(), _points[8].Y(), _points[8].Z());
glVertex3f(_points[12].X(), _points[12].Y(), _points[12].Z());
glEnd();

glBegin(GL_QUAD_STRIP);
_normal[3] = ((_points[11] - _points[3])*(_points[7] - _points[3])).unit();
glNormal3f(_normal[3]._x, _normal[3]._y, _normal[3]._z);
glVertex3f(_points[3].X(), _points[3].Y(), _points[3].Z());
glVertex3f(_points[7].X(), _points[7].Y(), _points[7].Z());
glNormal3f(_normal[3]._x, _normal[3]._y, _normal[3]._z);
glVertex3f(_points[11].X(), _points[11].Y(), _points[11].Z());
glVertex3f(_points[15].X(), _points[15].Y(), _points[15].Z());
glEnd();

}