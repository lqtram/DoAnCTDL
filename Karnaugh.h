#pragma once
#include "ArrKar.h"
#include "ArrPol.h"
#include <string>
#include <iostream>
using namespace std;

//Mỗi biến Karnaugh sẽ chứa số ô trong sơ đồ Karnaugh của 1 đơn thức, hay kar(f)
class ArrKar;
class ArrPol;
class Karnaugh
{
protected:
	int* arr;
	int length;
public:
	Karnaugh();
	Karnaugh(int x);
	Karnaugh(int* arr, int length);
	Karnaugh(const Karnaugh& orther);
	~Karnaugh();

	void Enter();
	void Print();

	int Length() { return this->length; }
	void Sort();//Sắp xếp tăng dần theo giá trị phần tử
	bool Have(int k);
	bool Belong(Karnaugh father);
	string Translate();//Hàm chuyển từ mảng karnaugh qua đơn thức

	Karnaugh& operator=(Karnaugh orther);
	Karnaugh operator+(Karnaugh orther);
	Karnaugh operator-(Karnaugh orther);

	bool operator==(Karnaugh orther);
	bool operator!=(Karnaugh orther);

	//----------------//

	friend istream& operator>>(istream& in, Karnaugh& kar);

	friend Karnaugh operator-(Karnaugh a, ArrKar b);

	friend ArrKar BigCell(Karnaugh Root);
	friend ArrKar BigCellRequired(Karnaugh Root, ArrKar BIGCell);
	friend void Optimal(Karnaugh Root, ArrKar BIGCell, ArrKar BIGCellRequired, ArrPol& Polynomial);//Tìm tất cả các trường hợp của các ô còn sót

	ArrPol MinimalPolynomial();//Hàm chính
};



