class Tbrick
{
private:
	TVector _points[16]; //points of the brick
	double _radius;
	double _width,_height;
	TVector _normal[16];//normals of the brick
	double _angle;
	double _row;
	double _outRadius;
public:
	Tbrick(void);
	Tbrick(double angle, double radius, double width,double row);
	~Tbrick(void);
	void makeBrick();
	void draw();
};

