#include "ArrKar.h"
#include <iostream>
using namespace std;

ArrKar::ArrKar()
{
	kar = NULL;
	length = 0;
}

ArrKar::ArrKar(Karnaugh* kar, int length)
{
	this->length = length;
	this->kar = new Karnaugh[length];
	for (int i = 0; i < length; i++)
		this->kar[i] = kar[i];
}

ArrKar::ArrKar(const ArrKar& orther)
{
	if (this == &orther)
		return;
	this->length = orther.length;
	this->kar = new Karnaugh[this->length];
	for (int i = 0; i < this->length; i++)
		this->kar[i] = orther.kar[i];
}

ArrKar::~ArrKar()
{
	if (kar)
		delete[] kar;
}

void ArrKar::Print()
{
	for (int i = 0; i < length; i++)
	{
		cout << "{"; kar[i].Print(); cout << " } ";
	}
	cout << endl;
}

void ArrKar::Add(Karnaugh kar)
{
	if (this->kar == NULL || length == 0)
	{
		length++;
		this->kar = new Karnaugh[1];
		this->kar[0] = kar;
	}
	else
	{
		ArrKar temp(*this);
		delete[] this->kar;
		this->length++;
		this->kar = new Karnaugh[this->length];
		for (int i = 0; i < temp.length; i++)
			this->kar[i] = temp.kar[i];
		this->kar[this->length - 1] = kar;
	}
}
void ArrKar::Del(Karnaugh kar)
{
	if (this->kar == NULL || (!this->Have(kar)))
	{
		return;
	}
	else
	{
		ArrKar temp(*this);
		delete[] this->kar;
		this->length = 0;
		this->kar = NULL;
		for (int i = 0; i < temp.length; i++)
		{
			if (temp.kar[i] != kar)
				this->Add(temp.kar[i]);
		}
	}
}

void ArrKar::Sort()
{
	for (int i = 0; i < length; i++)
		for (int j = length - 1; j > i; j--)
			if (kar[j].Length() > kar[j - 1].Length())
			{
				Karnaugh temp = kar[j];
				kar[j] = kar[j - 1];
				kar[j - 1] = temp;
			}
}
bool ArrKar::Have(Karnaugh kar)
{
	for (int i = 0; i < length; i++)
		if (kar == this->kar[i])
			return true;
	return false;
}
bool ArrKar::Have(int k)
{
	for (int i = 0; i < length; i++)
		if (this->kar[i].Have(k))
			return true;
	return false;
}

string ArrKar::Translate()
{
	string result;
	for (int i = 0; i < length; i++)
	{
		result += this->kar[i].Translate();
		if (i != length - 1)
			result += " + ";
	}
	return result;
}

ArrKar& ArrKar::operator=(ArrKar orther)
{
	if (this == &orther)
		return (*this);
	if (this->kar)
		delete[] this->kar;
	this->length = orther.length;
	this->kar = new Karnaugh[this->length];
	for (int i = 0; i < this->length; i++)
		this->kar[i] = orther.kar[i];
	return (*this);
}
ArrKar ArrKar::operator+(ArrKar orther)
{
	Karnaugh temp[100];
	int length = 0;
	for (int i = 0; i < this->length; i++)
	{
		temp[i] = this->kar[i];
		length++;
	}
	for (int i = 0; i < orther.length; i++)
		if (!this->Have(orther.kar[i]))
		{
			temp[length] = orther.kar[i];
			length++;
		}
	ArrKar result;
	result.length = length;
	result.kar = new Karnaugh[length];
	for (int i = 0; i < length; i++)
		result.kar[i] = temp[i];
	result.Sort();
	return result;
}
ArrKar ArrKar::operator-(ArrKar orther)
{
	Karnaugh temp[100];
	int length = 0;
	for (int i = 0; i < this->length; i++)
	{
		if (!orther.Have(this->kar[i]))
		{
			temp[length] = this->kar[i];
			length++;
		}
	}
	ArrKar result;
	result.length = length;
	result.kar = new Karnaugh[length];
	for (int i = 0; i < length; i++)
		result.kar[i] = temp[i];
	result.Sort();
	return result;
}
bool ArrKar::operator>(ArrKar orther) //vì đang so sánh dưới dạng đa thức nên dấu phải ngược lại
{
	if (this->length > orther.length)
		return true;
	else if (this->length < orther.length)
		return false;
	else
	{
		this->Sort();
		orther.Sort();
		for (int i = 0; i < this->length; i++)
			if (this->kar[i].Length() < orther.kar[i].Length())
				return true;
		return false;
	}
}
bool ArrKar::operator<(ArrKar orther)
{
	if (this->length < orther.length)
		return true;
	else if (this->length > orther.length)
		return false;
	else
	{
		this->Sort();
		orther.Sort();
		for (int i = 0; i < this->length; i++)
			if (this->kar[i].Length() > orther.kar[i].Length())
				return true;
		return false;
	}
}
bool ArrKar::operator==(ArrKar orther)
{
	if (this->length != orther.length)
		return false;
	else
	{
		this->Sort();
		orther.Sort();
		for (int i = 0; i < this->length; i++)
			if (this->kar[i].Length() != orther.kar[i].Length())
				return false;
		return true;
	}
}
bool ArrKar::operator!=(ArrKar orther)
{
	if (this->length != orther.length)
		return true;
	else
	{
		this->Sort();
		orther.Sort();
		for (int i = 0; i < this->length; i++)
			if (this->kar->Length() != orther.kar->Length())
				return true;
		return false;
	}
}
bool ArrKar::Same(ArrKar orther)
{
	if ((*this) != orther)
		return false;
	for (int i = 0; i < length; i++)
		if (!this->Have(orther.kar[i]))
			return false;
	return true;
}




