
class TVector
{
public:
	double _x,_y,_z; //x,y and z coordinats for the vector
	TVector(void);
	TVector(double x, double y, double z); //TVector class constructor 
	~TVector(void);
	TVector unit();//get the unit vector
	double magnitude();//get the magnitude
	void invert(); //invert the vector
	void print();//print out vector information
	static TVector add(TVector v1, TVector v2); //add 2 vectors
	static TVector subtract(TVector v1, TVector v2); //subtract 2 vectors
	static double dotProduct(TVector v1, TVector v2); //dot product
	static double dotProduct(TVector v1, TVector v2,double angle);//dot product using angle
	static double getAngle(TVector v1,TVector v2);//get the angle between 2 vectors
	static TVector crossProductP(TVector v1, TVector v2); //cross product between two vectors(positive value)
	static TVector crossProduct(TVector v1, TVector v2); //cross product between two vectors
	static TVector multiply(TVector v1, double s); // multiply a vector by a scalar
	static double scalarTripleProduct(TVector v1, TVector v2, TVector v3); // get the scalar triple product
	static TVector normalCalc(TVector v1,TVector v2,TVector v3); //get the normal from 2 vectors
	double X()	{ return _x; }
	double Y()	{ return _y; }
	double Z()	{ return _z; }
	friend TVector operator+(TVector v1,TVector v2)
	{
	TVector v3;
	v3=TVector::add(v1,v2);
	return v3;
    } // addition using + operator
	friend TVector operator-(TVector v1,TVector v2)
	{
	TVector v3;
	v3=TVector::subtract(v1,v2);
	return v3;
    } // subtraction using - operator
	friend TVector operator*(TVector v1,TVector v2)
	{
	TVector v3;
	v3=TVector::crossProductP(v1,v2);
	return v3;
    } // crossProduct using * operator
};

