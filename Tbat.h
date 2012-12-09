class Tbat
{
private:
	TVector _normal[16];
	double _inRadius,_outRadius;
	double _angle;
public:
	TVector _points[17];
	Tbat(void);
	Tbat(double inRadius,double outRadius,double angle);
	~Tbat(void);
	void draw();
	void makeBat();
	void normals();
	void print();
};

