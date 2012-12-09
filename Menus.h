using namespace std;
class Menus
{
private:
	GLUquadric *sphere;
	GLuint sphereTexture;
	int spins;
	double x,y;
	int texNr;
public:
	Menus(void);
	Menus(double x,double y,int texNr);
	~Menus(void);
	void draw();
	void init();
	void spin();

};

