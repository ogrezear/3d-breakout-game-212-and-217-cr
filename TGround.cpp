#include "main.h"


TGround::TGround(void)
{
}

TGround::TGround(float radius)
{
	_radius=radius;
}

TGround::~TGround(void)
{
}

float TGround::GetRadius(void)
{
	return _radius;
}

void TGround::init()
{
  glLoadIdentity();
  //glOrtho(-1.0, 1.0, -1.0, 1.0, -2.0, 2.0);
     
  ground = gluNewQuadric();
  gluQuadricTexture( ground, GL_TRUE);
  groundTexture = LoadBitmap("images/floor2.bmp");
}

void TGround::draw(void)
{	
	glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,lightAmbient);
	
	glEnable ( GL_TEXTURE_2D );
	//glColor3d(255,255,0);
	glBindTexture ( GL_TEXTURE_2D, groundTexture);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glRotated(90,1,0,0);
	gluDisk(ground,0,_radius,360,360);
	/*glBegin(GL_POLYGON);
	for(int i=0;i<=360;i++)
	{
	angle = i*PI/180;
	glVertex3f(_radius*cos(angle),0,_radius*sin(angle));
	}
	glEnd();*/
	glRotated(-90,1,0,0);
	glPopMatrix();
	glDisable (GL_TEXTURE_2D);
	glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,lightAmbient);
}
