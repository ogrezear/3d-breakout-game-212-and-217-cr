#include<iostream>
#include<string.h>
#include<glut.h>

class text
{
public:
	char s[100];
	float _x,_y,_z;
	int _type;
	text(void)
	{}

	text(float x,float y,float z,char *t,int type)
	{
		_x=x;
		_y=y;
		_z=z;
		_type=type;
		strcpy_s(s,t);
	}

	~text(void)
	{}

	void print()
	{
		int i,len;
		glRasterPos3f(_x,_y,_z);
		len =  strlen(s);
		//draw 1 item at a time
		for (i = 0; i < len; i++)   {   
			                            if(_type==1) glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, s[i]); 
										if(_type==2) glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, s[i]);
						             }
	}
};

