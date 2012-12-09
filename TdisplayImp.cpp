#include "main.h"

float angle;
float radius=1;
float ballRad=0.1;
float ballX=0,ballY=0;
float ballAngle=90;
float hitAngle=90;
float speed=0.0001;

void TDisplayImp::init(void)
{	
}

void TDisplayImp::reshape(int w, int h)
{
}

void TDisplayImp::ballMove(void)
{	
	glutPostRedisplay();
}


void TDisplayImp::renderScene() 
{
    glutMainLoop();
}


void TDisplayImp::displayCallBack() 
{
	

	glutPostRedisplay();
}


void TDisplayImp::SpecialKeyboardCallBack(int key1, int A, int B)
{
	glutPostRedisplay();
}


void main(int argc, char** argv)
{
	TDisplayImp::initialiseOpenGL(argc, argv);
	TDisplayImp::renderScene();
}
void TDisplayImp::initialiseOpenGL(int argc, char** argv) 
{
	glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize (500, 500);
	glutInitWindowPosition (200, 200);
    glutCreateWindow ("Breakout Game");
	init();
	glutReshapeFunc(TDisplayImp::reshape);
  	glutDisplayFunc(TDisplayImp::displayCallBack);
	glutKeyboardFunc(TDisplayImp::KeyboardCallBack);
	glutSpecialFunc(TDisplayImp::SpecialKeyboardCallBack);
	glutIdleFunc(TDisplayImp::ballMove);
}