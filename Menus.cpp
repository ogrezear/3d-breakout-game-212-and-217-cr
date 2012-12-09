#include "main.h"




Menus::Menus(void)
{
}

Menus::~Menus(void)
{
}

void Menus::init()
{
  glLoadIdentity();
  glOrtho(-1.0, 1.0, -1.0, 1.0, -2.0, 2.0);
     
  sphere = gluNewQuadric();
  gluQuadricTexture( sphere, GL_TRUE);
}

void Menus::spin()
{
	spins+=5;
	spins=spins%360;
}


void Menus::draw()
{
	text menuLine;
	int spin1=70,spin2=110,spin3=75,spin4=75; 
	GLfloat ambient[] = {0.5,0.5,0.5,1.0};
	GLfloat no_ambient[] = {0.2,0.2,0.2,1.0};
	glDisable(GL_LIGHTING);
	glColor4f(1.0,1.0,1.0,0);
	menuLine=text(3,0,8,"by Florin N. Coada",1);
	menuLine.print();
	double y1=0,y2=0,y3=0,y4=0,x1=-6,x4=6;
	switch (menuSelection){
	case 1: y1=5;
		x1=-5;
		glColor4f(0.0,0.0,0.0,0);
		menuLine=text(-1,1,2,"Start",2);
		menuLine.print();
		menuLine=text(-5.9,1,2.7,"Left arrow - Move left   Right arrow - Move right",1);
		menuLine.print();
		menuLine=text(-2,1,3.4,"Enter - Select",1);
		menuLine.print();
		menuLine=text(-2,1,4.1,"Esc - Fast quit",1);
		menuLine.print();
		spin1=spins;
		break;
	case 2: y2=5;
		spin2=spins;
		glColor4f(0.0,0.0,0.0,0);
		menuLine=text(-7,1,2.3,"Left arw - Move bat left     Right arw - Move bat right",1);
		menuLine.print();
		menuLine=text(-5.2,1,3,"# Toggle through cameras default is Camera 1",1);
		menuLine.print();
		menuLine=text(-5.2,1,3.7,"a- Move camera left     d-Move camera right ",1);
		menuLine.print();
		menuLine=text(-5.4,1,4.4,"w-Move camera up    s-Move camera down ",1);
		menuLine.print();
		menuLine=text(-4.2,1,5.1,"    q-Zoom in    e-Zoom out ",1);
		menuLine.print();
		menuLine=text(-4.2,1,5.8,"      p - Pause    o - Resume ",1);
		menuLine.print();
		//menuLine=text(-5.2,1,3.7,"a- Move camera left d-Move camera right ",1);
		//menuLine.print();
		break;
	case 3: y3=5;
		glColor4f(0.0,0.0,0.0,0);
		menuLine=text(-4.2,0.5,2.5,"  Kill a brick you get 3 points",1);
		menuLine.print();
		menuLine=text(-3.8,0.5,3.2,"    Hit the bat you lose 1",1);
		menuLine.print();
		menuLine=text(-3.8,0.5,3.9," The ball is affected by friction",1);
		menuLine.print();
		menuLine=text(-6.1,0.5,4.6,"Hit a bat corner to gain speed (no point penalty)",1);
		menuLine.print();
		spin3=spins;
		break;
	case 4: y4=5;
		x4=5;
		glColor4f(0.0,0.0,0.0,0);
		menuLine=text(-2.4,1,2.4,"Exit the game",2);
		menuLine.print();
		spin4=spins;
		break;
	};
	glEnable(GL_LIGHTING);
	ground.draw();
	glEnable ( GL_TEXTURE_2D );
	//menu obtion 1
	sphereTexture = LoadBitmap("images/start2.bmp");
	glBindTexture ( GL_TEXTURE_2D, sphereTexture);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glTranslatef(x1,y1,0);
	glRotated(180,0,1,0);
	glRotated(spin1,0,0,-1);
	gluSphere(sphere, 1.5,20,20);
	glPopMatrix();
	//menu option2
	sphereTexture = LoadBitmap("images/control.bmp");
	glBindTexture ( GL_TEXTURE_2D, sphereTexture);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glTranslatef(-2,y2,0);
	glRotated(180,0,1,0);
	glRotated(spin2,0,0,-1);
	gluSphere(sphere, 1.5,20,20);
	glPopMatrix();
	////menu option3
	sphereTexture = LoadBitmap("images/about.bmp");
	glBindTexture ( GL_TEXTURE_2D, sphereTexture);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glTranslatef(2,y3,0);
	glRotated(180,0,1,0);
	glRotated(spin3,0,0,-1);
	gluSphere(sphere, 1.5,20,20);
	glPopMatrix();
	////menu option4
	sphereTexture = LoadBitmap("images/exit.bmp");
	glBindTexture ( GL_TEXTURE_2D, sphereTexture);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glTranslatef(x4,y4,0);
	glRotated(180,0,1,0);
	glRotated(spin4,0,0,-1);
	gluSphere(sphere, 1.5,20,20);
	glPopMatrix();
	glDisable( GL_TEXTURE_2D );

}
