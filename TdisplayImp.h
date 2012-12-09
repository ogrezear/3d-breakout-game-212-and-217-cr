#ifndef TDisplayImp_h
#define TDisplayImp_h

#include "TVector.h"
#include "Tmatrix.h"
#include <glut.h>



//class TScene;

class TDisplayImp 
{
 			
        public:
			static void init();
            static void initialiseOpenGL(int argc, char** argv);
			static void reshape(int w, int h);
			static void ballMove(void);
            static void renderScene();
            static void displayCallBack();
			static void KeyboardCallBack(unsigned char key, int A, int B);
			static void SpecialKeyboardCallBack(int key1, int A, int B);
};

#endif
