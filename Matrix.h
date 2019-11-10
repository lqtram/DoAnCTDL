# pragma once
# include <iostream>
using namespace std;

class Matrix
{
	float **m;
	int lenrow;
	int lencol;
public:
	Matrix();
	Matrix(int lenrow, int lencol);
	Matrix(float **m, int lenrow, int lencol);
	Matrix(const Matrix &m1);
	~Matrix();
public:
	void SetLenrow(int lenrow);
	void SetLencol(int lencol);
	void EnterMatrix();
	int GetLenrow();
	int GetLencol();
	float ** GetMatrix();
	void ExportMatrix();
public:
	Matrix& operator=(const Matrix m1);
	Matrix CopyMatrixExceptRowCol(int row, int col); //chép ma trận đã cho vào ma trận mới bỏ đi cột col và dòng row
	float Det();
	Matrix Inverse();
	Matrix Cal2Matrix(Matrix m1);
	Matrix operator*(Matrix m1);

	void minusRow(int row_1, int row_2, float factor); //thực hiện phép trừ row_1 = row_1 - factor*row_2
	void divideRow(int row, float factor);// thực hiện phép chia row = row/factor
	void stepMatrix(); //Đưa về ma trận bật thang
	void compact_stepMatrix(); //Đưa về ma trận bật thang rút gọn

	int Rank();

};



