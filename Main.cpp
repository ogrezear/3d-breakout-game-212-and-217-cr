#include "main.h"
#include "myMath.h"
Ball ball=Ball(TVector(0.25,0,0.1),3,0,0.2,0);
TGround ground=TGround(8);
Tbat bat1;
Tbat bat2;
Tbat bat3;
int score=1;
char s[4]={"000"};
text scoreLine;
Menus menu;
float batsAngle=0;
GLuint bats;
GLuint bricks;
GLuint menuList;
int drawType=1;
int cameraType=1;
int showMenu=1;
int menuSelection=1;
float cameraY=7.399995;
//initilizing sun(light source) position 
GLfloat position[] = { 0.0, 10.0, 0.0, 0.0 };
angles brickLines[6][6];
int brickOnOff[7][6];
GLfloat brick1[]={0.5, 0.3, 0.6, 1.0}; //color for brick type one
GLfloat brick2[]={0.6, 0.1, 0.02, 1.0}; // color for brick type two
GLfloat no_ambient[]={0.2, 0.2, 0.2, 1.0}; //default ambient
GLfloat lightAmbient[] = {0.7,0.7,0.7,1.0}; //increse luminosity of the scene
int endGame=0;
int runNr=0;
void menuState();
int pauseState=0;


void setValues()
{
	for(int i=0;i<=5;i++)
		for(int j=0;j<=5;j++) { brickOnOff[i][j]=1;
								brickLines[i][j].angle1=j*60;
								brickLines[i][j].angle2=brickLines[i][j].angle1+60;
								}


}

void wait ( float seconds )
{
  clock_t endwait;
  endwait = clock () + seconds * CLOCKS_PER_SEC ;
  while (clock() < endwait) {}
}

void setBatList()
{

	bat1=Tbat(5,5.5,0+batsAngle);
	bat2=Tbat(5,5.5,120+batsAngle);
	bat3=Tbat(5,5.5,240+batsAngle);
	bats = glGenLists (1);
	glNewList(bats, GL_COMPILE);
	bat1.draw();
	bat2.draw();
	bat3.draw();
	glEndList();

}

void setBrickList()
{
	endGame=0;
	bricks=glGenLists(1);
	glNewList(bricks, GL_COMPILE);
	for(int i=0;i<=5;i++)
		for(int j=0;j<=5;j++) if(brickOnOff[i][j]==1){
			endGame=1;
			if((i+j)%2) {
				glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,brick1);
				Tbrick(brickLines[i][j].angle1,2,2.3,i).draw(); 
				glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,no_ambient);
			}
			else {
				glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,brick2);
				Tbrick(brickLines[i][j].angle1,2,2.3,i).draw();
				glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,no_ambient);
			}
	}
		if(endGame==0) { cameraType=1;
						 showMenu=1;
						 runNr++;
						 glutIdleFunc(menuState);
						 menuSelection=1;
						 setValues();
						 ball.reset(TVector(0.25,0,0.1),3,0,0.2,0);
						 PlaySound("sounds/Ball_Rolling.wav",NULL,SND_FILENAME|SND_LOOP|SND_ASYNC);
						}
	glEndList();
}

void init(void)
{	
// Clears the color pixels to white
glClearColor(0.0, 0.0, 0.0, 0.0);
// Selects smooth shading
glShadeModel(GL_SMOOTH);
// Enable lighting operations
glEnable(GL_LIGHTING);
// Enable an OpenGL light
glEnable(GL_LIGHT0);
// Enable depth test
glEnable(GL_DEPTH_TEST);
glMatrixMode(GL_PROJECTION);
// Set the light source parameters
glLightfv(GL_LIGHT0, GL_POSITION, position);
glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmbient);

ground.init();
ball.init();
menu.init();
setBatList();
setValues();
setBrickList();
initSkyBox();
PlaySound("sounds/Ball_Rolling.wav",NULL,SND_FILENAME|SND_LOOP|SND_ASYNC);
 }

void reshape(int w, int h)
{
// Sets the viewport
glViewport (0, 0, (GLsizei) w, (GLsizei) h);
// Applies matrix operations to the projection matrix stack
glMatrixMode(GL_PROJECTION);
// Replaces the current matrix with the identity matrix
glLoadIdentity();
// Sets up a perspective projection matrix
gluPerspective(40.0, (GLfloat) w/(GLfloat) h, 0.5, 200.0);
// Applies matrix operations to the modelview matrix stack
glMatrixMode(GL_MODELVIEW);
// Replaces the current matrix with the identity matrix
glLoadIdentity();
}

void ballMove(void)
{	
	ball.move();
	ball.spinZ();
	setBrickList();
	wait(0.035);
	glutPostRedisplay();
}

void Pause(void)
{
	wait(0.04);
	ball.spinZ();
	glutPostRedisplay();
}

void menuState(void)
{
	wait(0.04);
	menu.spin();
	glutPostRedisplay();
}

void renderScene() 
{
    glutMainLoop();
}

void setScore()
{
	s[0]=char(48+score/100);
	s[1]=char(48+(score%100)/10);
	s[2]=char(48+score%10);
}

void setCamera()
{
glDisable(GL_LIGHTING);
glColor3f(1,1,1);
if(cameraType==2) {
		setCamera2();
	if(showMenu==0)
		{	
			scoreLine=text(-0.2,3,0,"Score:",2);
			scoreLine.print();
			scoreLine=text(-0.1,2.5,0,s,2);
			scoreLine.print();
		}
	}
if(cameraType==1) {
		setCamera1();
		if(showMenu==0)
		{	scoreLine=text(-1,3,-0.5,"Score:",2);
			scoreLine.print();
			scoreLine=text(-0.5,2,0.5,s,2);
			scoreLine.print();
		}
	}
if(cameraType==3) {
		setCamera3();
	if(showMenu==0)
		{	scoreLine=text(-0.2,3,0,"Score:",2);
			scoreLine.print();
			scoreLine=text(-0.1,2.5,0,s,2);
			scoreLine.print();
		}
	}
glEnable(GL_LIGHTING);
}

void draw() 
{
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT ); //clear buffer bits
	glPushMatrix();
	setScore();
	setCamera();
	drawSkyBox();
	if(showMenu==0){
					ground.draw();
					glCallList(bats);
					glFlush();
					glCallList(bricks);
					glFlush();
					ball.draw();
					}
	else{
		 if(runNr){		
			 scoreLine=text(-2.5,1,-3,"Your score was:",2);
			 scoreLine.print();
			 scoreLine=text(-0.3,1,-2.2,s,2);
			 scoreLine.print();
		 }
		 menu.draw();
	}
	glPopMatrix();
	glutSwapBuffers();
}

void KeyboardCallBack(unsigned char key, int A, int B)
{

if(showMenu==1)
{

switch (key)
{
case 27: 
	exit(0); // Terminates the program
	break;
case 13:
	if(menuSelection==1) {showMenu=0;	
						  glutIdleFunc(ballMove);
						  score=1;
						  setScore();
						  runNr=0;
						 }
	if(menuSelection==4) exit(0);
	break;
default:
	break;
};
}

else{
if(cameraType==2) switch(key)
{
//Camera 2
case 'a':
	moveLeft();break;// go left on the circle
case 'd':
	moveRight();break; // go right on the circle
case 's':
	if(cameraY>1){ cameraY-=0.1;
	moveUp(-0.1);}break; // move up
case 'w':
	cameraY+=0.1;
	moveUp(0.1);break; // move down
case 'q':
	zoom(-0.1);break; //zoom in
case 'e':
	zoom(0.1);break; //zoom out
case '#':
	cameraType++;
	cameraType=cameraType%3+1;
	break; // change the camera type
case 'o':    //increase orbiting speed
	glutIdleFunc(ballMove);
	pauseState=0;
	break;
case 'p':   //decrease orbiting speed
	glutIdleFunc(Pause);
	pauseState=1;
	break;
case 27: 
	exit(0); // Terminates the program
	break;
case 32:
	showMenu=0;
	break;
}

else switch(key)
{
//Camera 1
case '#':
	cameraType++;
	cameraType=cameraType%3+1;
	break;
case 'o':    //increase orbiting speed
	glutIdleFunc(ballMove);
	pauseState=0;
	break;
case 'p':   //decrease orbiting speed
	glutIdleFunc(Pause);
	pauseState=1;
	break;
// Escapes from the program by pressing 'Esc'
case 27: 
	exit(0); // Terminates the program
	break;
case 32:
	showMenu=0;
	glutIdleFunc(ballMove);
	break;
default:
	break;
}
}
	glutPostRedisplay();
}

void SpecialKeyboardCallBack(int key1, int A, int B)
{
if(showMenu==1){
switch(key1){
case GLUT_KEY_LEFT:
	if(menuSelection>1) menuSelection--;
	break;
case GLUT_KEY_RIGHT:
	if(menuSelection<4) menuSelection++;
	break;
};
}

else{
switch(key1){
case GLUT_KEY_LEFT:
	if(!pauseState){
	batsAngle+=2;
	if(batsAngle>360) batsAngle-=360;
	setBatList();}
	break; //rotate bats
case GLUT_KEY_RIGHT:
	if(!pauseState){
	batsAngle-=2;
	if(batsAngle<0) batsAngle=360+batsAngle;
	setBatList();}
	break; //rotate bats
};
}
	glutPostRedisplay();
}

void initialiseOpenGL(int argc, char** argv) 
{
	glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize (500, 500);
	glutInitWindowPosition (200, 200);
    glutCreateWindow ("Breakout Game");
	init();
	glutReshapeFunc(reshape);
  	glutDisplayFunc(draw);
	glutKeyboardFunc(KeyboardCallBack);
	glutSpecialFunc(SpecialKeyboardCallBack);
	glutIdleFunc(menuState);
}

void main(int argc, char** argv)
{
	initialiseOpenGL(argc, argv);

	renderScene();
}