#pragma once
#include "ArrKar.h"
#include "Karnaugh.h"
#include <string>
#include <iostream>
using namespace std;

class Karnaugh;
class ArrKar;
class ArrPol
{
protected:
	ArrKar* pol;
	int length;
public:
	ArrPol();
	ArrPol(const  ArrPol& orther);
	~ArrPol();

	void Print();

	void Add(ArrKar pol);
	void Del(ArrKar pol);
	int Length() { return this->length; }

	void Sort();//Sắp xếp tăng dần theo số lượng số trong mỗi phần tử
	bool Have(ArrKar pol);
	bool Have(int k);
	string* Translate();//Hàm chuyển từ các mảng ArrKar qua qua các đa thức
	ArrPol& operator=(ArrPol orther);

	friend ostream& operator<<(ostream& out, const ArrPol obj);

	friend void Optimal(Karnaugh Root, ArrKar BIGCell, ArrKar BIGCellRequired, ArrPol& Polynomial);//Tìm tất cả các trường hợp của các ô còn sót

	void Standardized();//Hàm chuẩn hóa (xóa các phần tử trùng, sắp xếp)
	void MinimalPolynomial();//Chọn ra những đa thức đơn giản nhất <=> kết quả 
};

