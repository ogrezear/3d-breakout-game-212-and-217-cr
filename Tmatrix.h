
class Tmatrix
{
public:
	double _Mx[3][3];
	Tmatrix(void);
	Tmatrix(double a11,double a12,double a13,double a21,double a22,double a23,double a31,double a32,double a33);
	~Tmatrix(void);
	static Tmatrix add(Tmatrix M1, Tmatrix M2);
	static Tmatrix subtract(Tmatrix M1, Tmatrix M2);
	Tmatrix Tmatrix::transpose();
	double Tmatrix::det();
	Tmatrix Tmatrix::invert();
	static Tmatrix Tmatrix::scalarMultiply(Tmatrix M,double s);
	static Tmatrix matrixMultiply(Tmatrix M1, Tmatrix M2);
	void Tmatrix::print();
	friend Tmatrix operator+(Tmatrix m1,Tmatrix m2)
	{
	Tmatrix m3;
	m3=Tmatrix::add(m1,m2);
	return m3;
    }
	friend Tmatrix operator-(Tmatrix m1,Tmatrix m2)
	{
	Tmatrix m3;
	m3=Tmatrix::subtract(m1,m2);
	return m3;
    }
	friend Tmatrix operator*(Tmatrix m1,Tmatrix m2)
	{
		Tmatrix m3;
		m3=Tmatrix::matrixMultiply(m1,m2);
		return m3;
	}
};

