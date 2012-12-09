#include "main.h"

void initSkyBox()
{
  glLoadIdentity();
  glOrtho(-1.0, 1.0, -1.0, 1.0, -2.0, 2.0);
     
  sky = gluNewQuadric();
  gluQuadricTexture( sky, GL_TRUE);
  skyTexture = LoadBitmap("images/sun.bmp");
}

void drawSkyBox()
{
	glEnable ( GL_TEXTURE_2D );
	glBindTexture ( GL_TEXTURE_2D, skyTexture);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glTranslatef(0,0,0);
	glRotated(180,1,0,0);
	gluSphere(sky,30,20,20);
	glPopMatrix();
	glDisable ( GL_TEXTURE_2D );
}