#include "main.h"
#include "myMath.h"

void Ball::setTex()
{
	path[0]="images/ball.bmp";
	path[1]="images/sun.bmp";
}

Ball::Ball(void)
{
}

Ball::Ball(TVector speed, float ballx, float ballz, float radius,int texNr)
{
	_speed=speed;
	_ballx=ballx;
	_ballz=ballz;
	_bally=radius;
	_radius=radius;
	angle2=TVector::getAngle(_speed.unit(),TVector(1,0,0).unit());//angle between speed vector and 1,0,0 vector
	if(_speed._z<0) angle2=360-angle2;
	texNr=texNr;
	pos=TVector(_ballx,0,_ballz);
	spin=0;
	setTex();
}

void Ball::reset(TVector speed, float ballx, float ballz, float radius, int texNr)
{
	_speed=speed;
	_ballx=ballx;
	_ballz=ballz;
	_bally=radius;
	_radius=radius;
	angle2=TVector::getAngle(_speed.unit(),TVector(1,0,0).unit());//angle between speed vector and 1,0,0 vector
	if(_speed._z<0) angle2=360-angle2;
	texNr=texNr;
	pos=TVector(_ballx,0,_ballz);
	spin=0;
	setTex();
}

Ball::~Ball(void)
{
}

void Ball::init()
{
  glLoadIdentity();
  glOrtho(-1.0, 1.0, -1.0, 1.0, -2.0, 2.0);
     
  ballq = gluNewQuadric();
  gluQuadricTexture( ballq, GL_TRUE);
  ballTexture = LoadBitmap(path[texNr].c_str());
}

void Ball::spinZ()
{
	spin+=30;
	spin=int(spin)%360;
}

double Ball::GetX()
{
	return _ballx;
}

double Ball::GetZ()
{
	return _ballz;
}

void Ball::draw()
{
	//enable use of texture
	glEnable ( GL_TEXTURE_2D );
	glBindTexture ( GL_TEXTURE_2D, ballTexture);//set texture to be used
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glTranslatef(_ballx,_bally,_ballz); //place the ball in the scene
	glRotatef(angle2,0,-1,0); /* rotate the ball on the self Y axis in order 
								to obtain corect rolling efect */
	glRotatef(spin,0,0,-1); //rotate the ball on the self z axis
	gluSphere(ballq,_radius,20,20); // draw the ball
	glPopMatrix();
	glDisable ( GL_TEXTURE_2D );//disable use of textures

}

void Ball::move()
{
	//simple friction simulation
	_speed=TVector::multiply(_speed,0.999);
	//update ball position
	_ballx=_ballx+_speed._x;
	_ballz=_ballz+_speed._z;
	//calculate delta value
	delta=_speed.magnitude();
	if(cd!=0) cd--;
	else switch (collision()){
	case 1: PlaySound("sounds/roll4.wav",NULL,SND_FILENAME|SND_ASYNC);	//play sound of ball hits bat
		break;
	case 2: PlaySound("sounds/boing.wav",NULL,SND_FILENAME|SND_ASYNC); //play sound if ball hits circle edge
		break;
	};
}

int Ball::collision()
{
	double BallO,dotProd;
	double distance;//ball to outer circle
	double distance2;//ball to inner bat
	double distance3;//ball to outer bat
	double distance4;//ball to outer well
	double distance5;//ball to inner well
	TVector  normal;//normal vector of collision
	normal=angleCheck();
	pos=TVector(_ballx,0,_ballz);
	BallO=pow(_ballx,2)+pow(_ballz,2);
	dotProd=TVector::dotProduct(pos,_speed.unit());
	
	if(pos.magnitude()>5.5) //ball between circle and bats
	{ 
	//distance to outer circle
	distance=sqrt(abs(pow(ground.GetRadius()-_radius,2)-BallO+pow(dotProd,2)))-dotProd; 
	if(distance<=delta) {setSpeed(); return 2;}
		//distance to outer bat
	distance3=sqrt(pow(_ballx,2)+pow(_ballz,2))-5.5-_radius;
	if(abs(distance3)<=delta && normal.X()!=0 && normal.Z()!=0) {/*setSpeedFromBat(normal);*/ setSpeed(); if(score>0) score-=1; return 1;}
	}

	if(pos.magnitude()<5 && pos.magnitude()>2.4) //ball between bats and well
	{
	//distance to inner bat
	distance2=sqrt(abs(pow(5-_radius,2)-BallO+pow(dotProd,2)))-dotProd;
	if(abs(distance2)<=delta && normal.X()!=0 && normal.Z()!=0)	{/*setSpeedFromBat(normal);*/ setSpeed(); if(score>0) score-=1; return 1;}
	//distance to outer well
	distance4=sqrt(pow(_ballx,2)+pow(_ballz,2))-2.3-_radius;
	if(abs(distance4)<=delta)	{return killBrick(); }
	}
	if(pos.magnitude()<1.8){
	//distance to inner well
	distance5=sqrt(abs(pow(2-_radius,2)-BallO+pow(dotProd,2)))-dotProd;
	if(distance5<=delta){return killBrick(); }
	}
	sideCollision();
	return 0;
}

void Ball::setSpeed()
{
	//Speed bounce algorithm posted by Gareth Rees on stackoverflow.com
	TVector u,w;
	double q;
	u = TVector(_ballx,0,_ballz);
	q=TVector::dotProduct(_speed,TVector(_ballx,0,_ballz))/TVector::dotProduct(TVector(_ballx,0,_ballz),TVector(_ballx,0,_ballz));
	u=TVector::multiply(u,q);
	w=_speed-u;
	_speed=w-u;
	angle2=TVector::getAngle(_speed.unit(),TVector(1,0,0).unit());//angle between speed vector and 1,0,0 vector
	if(_speed._z<0) angle2=360-angle2;
}

void Ball::setSpeedFromBat(TVector normal)
{
	//Speed bounce algorithm posted by Gareth Rees on stackoverflow.com
	TVector u,w;
	double q;
	u=normal;
	q=TVector::dotProduct(_speed,normal)/TVector::dotProduct(normal,normal);
	u=TVector::multiply(u,q);
	w=_speed-u;
	_speed=w-u;
	angle2=TVector::getAngle(_speed.unit(),TVector(1,0,0).unit());//angle between speed vector and 1,0,0 vector
	if(_speed._z<0) angle2=360-angle2;
}

TVector Ball::angleCheck()
{
float angle3,angle4;
TVector normal;
double x,z;
angle3=TVector::getAngle(bat1._points[0],pos);
angle4=TVector::getAngle(pos,bat1._points[3]);
if(abs(60-angle4-angle3)<=0.05){ 
	if(angle3<18){ x=bat1._points[0].X()+bat1._points[1].X();
				   z=bat1._points[0].Z()+bat1._points[1].Z();	
					}
	else if(angle3>22 && angle3<38){ x=bat1._points[1].X()+bat1._points[2].X();
						     	     z=bat1._points[1].Z()+bat1._points[2].Z();
									}
		else if(angle3>42 && angle3<58){ x=bat1._points[2].X()+bat1._points[3].X();
						     			 z=bat1._points[2].Z()+bat1._points[3].Z();
										}
		else {x=_ballx;z=_ballz;}
	normal=TVector(x/2,0,z/2).unit();
	return normal;
	}


angle3=TVector::getAngle(bat2._points[0],pos);
angle4=TVector::getAngle(pos,bat2._points[3]);
if(abs(60-angle4-angle3)<=0.05) {
	if(angle3<18){ x=bat2._points[0].X()+bat2._points[1].X();
				   z=bat2._points[0].Z()+bat2._points[1].Z();	
					}
	else if(angle3>22 && angle3<38){ x=bat2._points[1].X()+bat2._points[2].X();
						     	     z=bat2._points[1].Z()+bat2._points[2].Z();
									}
		else if(angle3>42 && angle3<58){ x=bat2._points[2].X()+bat2._points[3].X();
						     			 z=bat2._points[2].Z()+bat2._points[3].Z();
										}
		else {x=_ballx;z=_ballz;}
	normal=TVector(x/2,0,z/2).unit();
	return normal;
	}
angle3=TVector::getAngle(bat3._points[0],pos);
angle4=TVector::getAngle(pos,bat3._points[3]);
if(abs(60-angle4-angle3)<=0.05) {
	if(angle3<18){ x=bat3._points[0].X()+bat3._points[1].X();
				   z=bat3._points[0].Z()+bat3._points[1].Z();	
					}
	else if(angle3>22 && angle3<38){ x=bat3._points[1].X()+bat3._points[2].X();
						     	     z=bat3._points[1].Z()+bat3._points[2].Z();
									}
		else if(angle3>42 && angle3<58){ x=bat3._points[2].X()+bat3._points[3].X();
						     			 z=bat3._points[2].Z()+bat3._points[3].Z();
										}
		else {x=_ballx;z=_ballz;}
	normal=TVector(x/2,0,z/2).unit();
	return normal;
	}
return TVector(0,0,0);
}

int Ball::killBrick()
{
float angle1,angle3,angle4;
angle1=TVector::getAngle(pos.unit(),TVector(1,0,0).unit());//get the angle between ball position and (1,0,0) vector
if(_ballz<0) angle1=360-angle1; //convert angle to 360 degrees format
for(int i=0;i<=5;i++){

	angle3=float(brickLines[0][i].angle1);
	angle4=float(brickLines[0][i].angle2);
	//printf("%f < %f -= %f =- %i\n",angle3, angle4, angle1,i);
	if(angle3<=angle1 && angle1<=angle4 && brickOnOff[0][i]==1) for(int j=0;j<=6;j++) if(brickOnOff[j][i]==0 && j>=0) {brickOnOff[j-1][i]=0;
																														setSpeed();
																														score+=3;
																														return 1;
																														break;}
	}
return 0;
}

void Ball::sideCollision()
{
	float angle3,angle4;
	TVector bSide;
	float sideDist;
	float upDist;
	float downDist;
//side collision for bat1
	angle3=TVector::getAngle(bat1._points[0],pos);
	angle4=TVector::getAngle(pos,bat1._points[3]);
	if(angle3<30) { bSide=TVector((bat1._points[0].X()+bat1._points[4].X())/2,0,(bat1._points[0].Z()+bat1._points[4].Z())/2);
					downDist=(pos-bat1._points[0]).magnitude();
					upDist=(pos-bat1._points[4]).magnitude();
					sideDist=(pos-bSide).magnitude();
					if(abs(sideDist-_radius)<=0.1 || abs(downDist-_radius)<=0.1 || abs(upDist-_radius)<=0.1) {
					_speed=TVector::multiply(_speed,1.2);
					_speed.invert();
					cd=3;}
					}
	else if(angle4<30) { bSide=TVector((bat1._points[3].X()+bat1._points[7].X())/2,0,(bat1._points[3].Z()+bat1._points[7].Z())/2);
						downDist=(pos-bat1._points[3]).magnitude();
						upDist=(pos-bat1._points[7]).magnitude();
						sideDist=(pos-bSide).magnitude();
						if(abs(sideDist-_radius)<=0.1 || abs(downDist-_radius)<=0.1 || abs(upDist-_radius)<=0.1) {
						_speed=TVector::multiply(_speed,1.2);
						_speed.invert();
						cd=3;}
						}
//side collision for bat2
	angle3=TVector::getAngle(bat2._points[0],pos);
	angle4=TVector::getAngle(pos,bat2._points[3]);
	if(angle3<30) { bSide=TVector((bat2._points[0].X()+bat2._points[4].X())/2,0,(bat2._points[0].Z()+bat2._points[4].Z())/2);
					downDist=(pos-bat2._points[0]).magnitude();
					upDist=(pos-bat2._points[4]).magnitude();
					sideDist=(pos-bSide).magnitude();
					if(abs(sideDist-_radius)<=0.1 || abs(downDist-_radius)<=0.1 || abs(upDist-_radius)<=0.1) {
					_speed=TVector::multiply(_speed,1.2);
					_speed.invert();
					cd=3;}
					}
	else if(angle4<30) { bSide=TVector((bat2._points[3].X()+bat2._points[7].X())/2,0,(bat2._points[3].Z()+bat2._points[7].Z())/2);
						downDist=(pos-bat2._points[3]).magnitude();
						upDist=(pos-bat2._points[7]).magnitude();
						sideDist=(pos-bSide).magnitude();
						if(abs(sideDist-_radius)<=0.1 || abs(downDist-_radius)<=0.1 || abs(upDist-_radius)<=0.1) {
						_speed=TVector::multiply(_speed,1.2);
						_speed.invert();
						cd=3;}
						}
//side collision for bat3
	angle3=TVector::getAngle(bat3._points[0],pos);
	angle4=TVector::getAngle(pos,bat3._points[3]);
	if(angle3<30) { bSide=TVector((bat3._points[0].X()+bat3._points[4].X())/2,0,(bat3._points[0].Z()+bat3._points[4].Z())/2);
					downDist=(pos-bat3._points[0]).magnitude();
					upDist=(pos-bat3._points[4]).magnitude();
					sideDist=(pos-bSide).magnitude();
					if(abs(sideDist-_radius)<=0.1 || abs(downDist-_radius)<=0.1 || abs(upDist-_radius)<=0.1) {
					_speed=TVector::multiply(_speed,1.2);
					_speed.invert();
					cd=3;}
					}
	else if(angle4<30) { bSide=TVector((bat3._points[3].X()+bat3._points[7].X())/2,0,(bat3._points[3].Z()+bat3._points[7].Z())/2);
						downDist=(pos-bat3._points[3]).magnitude();
						upDist=(pos-bat3._points[7]).magnitude();
						sideDist=(pos-bSide).magnitude();
						if(abs(sideDist-_radius)<=0.1 || abs(downDist-_radius)<=0.1 || abs(upDist-_radius)<=0.1) {
						_speed=TVector::multiply(_speed,1.2);
						_speed.invert();
						cd=3;}

						}
	angle2=TVector::getAngle(_speed.unit(),TVector(1,0,0).unit());//angle between speed vector and 1,0,0 vector
	if(_speed._z<0) angle2=360-angle2;
}	

