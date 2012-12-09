using namespace std;
class Ball
{
private:
	double _ballx,_ballz; //xz position of the ball, y will always be equal to the radius
	double _radius,_bally;
	int cd;//side collision cooldown
	double spin;
	TVector _speed;
	TVector pos;
	float angle2;
	int collision();
	void setSpeed();
	TVector angleCheck();
	int killBrick();
	void setSpeedFromBat(TVector normal);
	void sideCollision();
	GLUquadric *ballq;
    GLuint ballTexture; //used to store planettextures
	double delta; //tolerance value, the collision will happen if the distance is lower than delta
	int texNr;
	string path[3]; // textures paths
public:
	Ball(void);
	Ball(TVector speed, float ballx, float ballz, float radius, int texNr);
	void reset(TVector speed, float ballx, float ballz, float radius, int texNr);
	~Ball(void);
	void draw();
	void move();
	double GetX();
	double GetZ();
	void setTex();
	void init();
	void spinZ();
	double GetY(){
		return _bally;
	}
	TVector GetSpeed()
	{
		return _speed;
	}
};

