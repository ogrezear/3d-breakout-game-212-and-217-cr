#include "main.h"


Tmatrix::Tmatrix(void)
{
	for(int i=0;i<=2;i++)
		for(int j=0;j<=2;j++) _Mx[i][j]=0;
}

Tmatrix::Tmatrix(double a11,double a12,double a13,double a21,double a22,double a23,double a31,double a32,double a33)
{
	_Mx[0][0]=a11;
	_Mx[0][1]=a12;
	_Mx[0][2]=a13;
	_Mx[1][0]=a21;
	_Mx[1][1]=a22;
	_Mx[1][2]=a23;
	_Mx[2][0]=a31;
	_Mx[2][1]=a32;
	_Mx[2][2]=a33;
 }

Tmatrix::~Tmatrix(void)
{
}

Tmatrix Tmatrix::add(Tmatrix M1, Tmatrix M2)
{
	Tmatrix M3;
	for(int i=0;i<=2;i++)
		for(int j=0;j<=2;j++) M3._Mx[i][j]=M1._Mx[i][j]+M2._Mx[i][j];
	return M3;
}

Tmatrix Tmatrix::subtract(Tmatrix M1, Tmatrix M2)
{
		Tmatrix M3;
	for(int i=0;i<=2;i++)
		for(int j=0;j<=2;j++) M3._Mx[i][j]=M1._Mx[i][j]-M2._Mx[i][j];
	return M3;
}

Tmatrix Tmatrix::transpose()
{
	Tmatrix M2;
	for(int i=0;i<=2;i++)
		for(int j=0;j<=2;j++) M2._Mx[j][i]=_Mx[i][j];
	return M2;
}

double Tmatrix::det()
{
	return _Mx[0][0]*_Mx[1][1]*_Mx[2][2]+_Mx[0][1]*_Mx[1][2]*_Mx[2][0]+_Mx[0][2]*_Mx[1][0]*_Mx[2][1]-_Mx[2][0]*_Mx[1][1]*_Mx[0][2]-_Mx[0][1]*_Mx[1][0]*_Mx[2][2]-_Mx[2][1]*_Mx[1][2]*_Mx[0][0];
}

Tmatrix Tmatrix::invert()
{
	Tmatrix M;
	double detM;
	M._Mx[0][0]=_Mx[2][2]*_Mx[1][1]-_Mx[2][1]*_Mx[1][2];
	M._Mx[0][1]=_Mx[0][2]*_Mx[2][1]-_Mx[2][2]*_Mx[0][1];
	M._Mx[0][2]=_Mx[0][1]*_Mx[1][2]-_Mx[1][1]*_Mx[0][2];
	M._Mx[1][0]=_Mx[1][2]*_Mx[2][0]-_Mx[1][0]*_Mx[2][2];
	M._Mx[1][1]=_Mx[0][0]*_Mx[2][2]-_Mx[0][2]*_Mx[2][0];
	M._Mx[1][2]=_Mx[0][2]*_Mx[1][0]-_Mx[1][2]*_Mx[0][0];
	M._Mx[2][0]=_Mx[1][0]*_Mx[2][1]-_Mx[1][1]*_Mx[2][0];
	M._Mx[2][1]=_Mx[0][1]*_Mx[2][0]-_Mx[0][0]*_Mx[2][1];
	M._Mx[2][2]=_Mx[0][0]*_Mx[1][1]-_Mx[0][1]*_Mx[1][0];
	detM=Tmatrix::det();
	for(int i=0;i<=2;i++)
		for(int j=0;j<=2;j++) M._Mx[i][j]=M._Mx[i][j]/detM;
	return M;
}

Tmatrix Tmatrix::scalarMultiply(Tmatrix M,double s)
{
	Tmatrix M1;
	for(int i=0;i<=2;i++)
		for(int j=0;j<=2;j++) M1._Mx[i][j]=M._Mx[i][j]*s;
	return M1;
}

Tmatrix Tmatrix::matrixMultiply(Tmatrix M1, Tmatrix M2)
{
	Tmatrix M;
	for(int i=0;i<=2;i++)
		for(int j=0;j<=2;j++) 
			for(int k=0;k<=2;k++) M._Mx[i][j]+=M1._Mx[i][k]*M2._Mx[k][j];
	return M;
}

void Tmatrix::print()
{
	for(int i=0;i<=2;i++)
	{
		for(int j=0;j<=2;j++)
			cout<<_Mx[i][j]<<" ";
		printf("\n");
	}
	printf("\n");
}