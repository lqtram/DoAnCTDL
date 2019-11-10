#pragma once
#include "Karnaugh.h"
#include "ArrPol.h"
#include <string>
#include <iostream>
using namespace std;

class Karnaugh;
class ArrPol;
class ArrKar
{
protected:
	Karnaugh* kar;
	int length;
public:
	ArrKar();
	ArrKar(Karnaugh* kar, int length);
	ArrKar(const  ArrKar& orther);
	~ArrKar();

	void Print();

	void Add(Karnaugh kar);
	void Del(Karnaugh kar);
	int Length() { return this->length; }

	void Sort();//Sắp xếp giảm dần theo số lượng số trong mỗi phần tử
	bool Have(Karnaugh kar);
	bool Have(int k);
	string Translate();//Hàm chuyển từ các mảng karnaugh qua đa thức tương ứng

	ArrKar& operator=(ArrKar orther);
	ArrKar operator+(ArrKar orther);
	ArrKar operator-(ArrKar orther);

	bool operator>(ArrKar orther);//đa thức nào tối tiểu hơn thì sẽ nhỏ hơn
	bool operator<(ArrKar orther);//ngược với cái trên
	bool operator==(ArrKar orther); //Đo dựa trên độ dài
	bool operator!=(ArrKar orther);
	bool Same(ArrKar orther); // giống nhau hoàng toàn

	//-----------------//

	friend Karnaugh operator-(Karnaugh a, ArrKar b);

	friend ArrKar BigCell(Karnaugh Root); //Hàm tìm tế bào lớn
	friend ArrKar BigCellRequired(Karnaugh Root, ArrKar BIGCell); //Hàm tìm tế bao lớn bắt buộc
	friend void Optimal(Karnaugh Root, ArrKar BIGCell, ArrKar BIGCellRequired, ArrPol& Polynomial);//Tìm tất cả các trường hợp của các ô còn sót
};

