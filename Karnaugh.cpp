#include "Karnaugh.h"
#include <iostream>
using namespace std;
//Dựa trên các biến x,y,z,t và ngịch đảo của chúng ~x,~y,~z,~t

//-------------------------------------------------------//
Karnaugh::Karnaugh()
{
	arr = NULL;
	length = 0;
}

Karnaugh::Karnaugh(int x)
{
	arr = new int[1];
	length = 1;
	arr[0] = x;
}

Karnaugh::Karnaugh(int* arr, int length)
{
	this->length = length;
	this->arr = new int[length];
	for (int i = 0; i < length; i++)
		this->arr[i] = arr[i];
}

Karnaugh::Karnaugh(const Karnaugh& orther)
{
	if (this == &orther)
		return;
	this->length = orther.length;
	this->arr = new int[this->length];
	for (int i = 0; i < this->length; i++)
		this->arr[i] = orther.arr[i];
}

Karnaugh::~Karnaugh()
{
	if (arr)
		delete[] arr;
}

//----------------------------------------------------//
void Karnaugh::Enter()
{
	cout << "Nhap so phan tu: "; cin >> length;
	arr = new int[length];
	cout << "Nhap cac phan tu: \n";
	for (int i = 0; i < length; i++)
	{
		cout << i << ". "; cin >> arr[i];
	}
}
void Karnaugh::Print()
{
	for (int i = 0; i < length; i++)
		cout << " " << arr[i];
}

//----------------------------------------------------//
void Karnaugh::Sort()
{
	for (int i = 0; i < length; i++)
		for (int j = length - 1; j > i; j--)
			if (arr[j] < arr[j - 1])
			{
				int temp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = temp;
			}
}

bool Karnaugh::Have(int k)
{
	for (int i = 0; i < length; i++)
		if (k == arr[i])
			return true;
	return false;
}

bool Karnaugh::Belong(Karnaugh father)
{
	if (this->length > father.length)
		return false;
	for (int i = 0; i < this->length; i++)
		if (!father.Have(this->arr[i]))
			return false;
	return true;
}

string Karnaugh::Translate()
{
	Karnaugh Exem[8];
	//-------x-------//   8
	int temp_0[] = { 1,2,5,6,9,10,13,14 }; Exem[0] = Karnaugh(temp_0, 8); //x
	int temp_1[] = { 3,4,7,8,11,12,15,16 }; Exem[1] = Karnaugh(temp_1, 8); //~x
	int temp_2[] = { 2,3,6,7,10,11,14,15 }; Exem[2] = Karnaugh(temp_2, 8); //y
	int temp_3[] = { 1,4,5,8,9,12,13,16 }; Exem[3] = Karnaugh(temp_3, 8); //~y
	int temp_4[] = { 1,2,3,4,5,6,7,8 }; Exem[4] = Karnaugh(temp_4, 8); //z
	int temp_5[] = { 9,10,11,12,13,14,15,16 }; Exem[5] = Karnaugh(temp_5, 8); //~z
	int temp_6[] = { 5,6,7,8,9,10,11,12 }; Exem[6] = Karnaugh(temp_6, 8); //t
	int temp_7[] = { 1,2,3,4,13,14,15,16 }; Exem[7] = Karnaugh(temp_7, 8); //~t

	string result;
	for (int i = 0; i < 8; i++)
	{
		if (this->Belong(Exem[i]))
		{
			switch (i)
			{
			case 0:
			{
				result += "x";
				break;
			}
			case 1:
			{
				result += "~x";
				break;
			}
			case 2:
			{
				result += "y";
				break;
			}
			case 3:
			{
				result += "~y";
				break;
			}
			case 4:
			{
				result += "z";
				break;
			}
			case 5:
			{
				result += "~z";
				break;
			}
			case 6:
			{
				result += "t";
				break;
			}
			case 7:
			{
				result += "~t";
				break;
			}
			}
		}
	}
	return result;
}
//---------------------------------------------------//
Karnaugh& Karnaugh::operator=(Karnaugh orther)
{
	if (this == &orther)
		return (*this);
	if (this->arr)
		delete this->arr;
	this->length = orther.length;
	this->arr = new int[this->length];
	for (int i = 0; i < this->length; i++)
		this->arr[i] = orther.arr[i];
	return (*this);
}
Karnaugh Karnaugh::operator+(Karnaugh orther)
{
	int temp[16];
	int length = 0;
	for (int i = 0; i < this->length; i++)
	{
		temp[i] = this->arr[i];
		length++;
	}
	for (int i = 0; i < orther.length; i++)
	{
		if (!(*this).Have(orther.arr[i]))
		{
			temp[length] = orther.arr[i];
			length++;
		}
	}
	Karnaugh result;
	result.arr = new int[length];
	result.length = length;
	for (int i = 0; i < length; i++)
		result.arr[i] = temp[i];
	result.Sort();
	return result;
}
Karnaugh Karnaugh::operator-(Karnaugh orther)
{
	int temp[16];
	int length = 0;
	for (int i = 0; i < this->length; i++)
	{
		if (!orther.Have(this->arr[i]))
		{
			temp[length] = this->arr[i];
			length++;
		}
	}
	Karnaugh result;
	result.arr = new int[length];
	result.length = length;
	for (int i = 0; i < length; i++)
		result.arr[i] = temp[i];
	result.Sort();
	return result;
}
bool Karnaugh::operator==(Karnaugh orther)
{
	if ((*this).Belong(orther) && orther.Belong(*this))
		return true;
	return false;
}
bool Karnaugh::operator!=(Karnaugh orther)
{
	if ((*this).Belong(orther) && orther.Belong(*this))
		return false;
	return true;
}

istream& operator>>(istream& in, Karnaugh& kar)
{
	cout << "Nhap so o bi bao phu: "; in >> kar.length;
	cout << "Nhap thu tu cac o bi bao phu (1-16): ";
	kar.arr = new int[kar.length];
	for (int i = 0; i < kar.length; i++)
		in >> kar.arr[i];
	return in;
}


