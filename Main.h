#include <stdio.h> // import standard C library
#include <stdlib.h> // import standard C library
#include <iostream> // import standard C library
#include <windows.h> // import standard C library
#include <fstream> // import standarc C library
#include <time.h> // import standard C library
#include <math.h> // import standard C library
#include <string.h> // import standard C library
#include "glut.h" // import GLUT library
#include "Tmatrix.h"
#include "TVector.h"
#include "TGround.h"
#include "Ball.h"
#include "Tbat.h"
#include "Camera.h"
#include "Tbrick.h"
#include "Textures.h"
#include "Menus.h"
#include "text.h"
#include "skyBox.h"
using namespace std;
class Tmatrix;
class TVector;
#define PI 3.14159265
#define _USE_MATH_DEFINES
struct angles{
	int angle1;
	int angle2;
};

extern TGround ground;
extern float batsAngle;
extern Tbat bat1;
extern Tbat bat2;
extern Tbat bat3;
extern angles brickLines[6][6];
extern int brickOnOff[7][6];
extern GLuint bats;
extern GLuint bricks;
extern Ball ball;
extern int menuSelection;
extern GLfloat lightAmbient[];
extern GLfloat no_ambient[];
extern int score;
extern float yp;

