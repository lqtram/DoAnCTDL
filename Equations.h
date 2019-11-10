#pragma once
#include "Matrix.h"
class Equations
{
	Matrix factor;//Ma trận hệ số
	Matrix freeFactor;//Vector hằng
public:
	Equations();
	Equations(Matrix factor, Matrix freeFactor) { this->factor = factor; this->freeFactor = freeFactor; }
	//Equations(const Equations& orther); //Không có thành phần động nên cũng không cần
	~Equations();

	void Enter();
	Matrix getFactor() { return factor; }
	Matrix getFreeFactor() { return freeFactor; }
	void Export();

	//Equations& operator=(const Equations m1); ///Không có thành phần động nên cũng không cần

	void stepMatrix(); //Đưa factor về ma trận bật thang, freeFactor cũng thay đổi theo factor
	void compact_stepMatrix(); //Đưa factor về ma trận bật thang rút gọn, freeFactor cũng thay đổi theo factor
	void Solution();//Giải hệ phương trình tuyến tính
};

