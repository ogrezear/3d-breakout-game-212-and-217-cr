#include "main.h"

//Camera 1
void setCamera1()
{
	//Set the camera position
		gluLookAt(0, 23, 3, 
		  0, 0, 0,
		  0.0, 1.0, 0.0);

}

//Camera 3

void setCamera3()
{
	gluLookAt(ball.GetX()*1.5,ball.GetY()*3 , ball.GetZ()*1.5, 
		  ball.GetSpeed().X(), ball.GetSpeed().Y(), ball.GetSpeed().Z(),
		  0.0, 1.0, 0.0);
}

//Camera 2
void moveLeft()
{
	if(xp>=radius || xp<=-radius){ speedL=speedR;
	                             speedR=-speedR;
								 side=-side;
	                            }
	xp+=speedL;
	if(xp>=radius) xp=radius;
	else if(xp<=-radius) xp=-radius;
	zp=side*sqrt(pow(radius,2)-pow(xp,2));
}

void moveRight()
{
	
	if(xp>=radius || xp<=-radius){ speedR=speedL;
	                             speedL=-speedL;
								 side=-side;
	                            }
	xp+=speedR;
	if(xp>=radius) xp=radius;
	else if(xp<=-radius) xp=-radius;
    zp=side*sqrt(pow(radius,2)-pow(xp,2));
}

void moveUp(float speed)
{
	yp+=speed;
}

void zoom(float size)
{
	if(xp*(radius+size)/radius<43 && zp*(radius+size)/radius<44)
	{
	xp=xp*(radius+size)/radius;
	zp=zp*(radius+size)/radius;
	radius+=size;
	}
}

void setCamera2()
{
	//set the camera
	gluLookAt(xp,yp,zp,
	      0,0,0,
		  0.0,1.0,0.0);
}


