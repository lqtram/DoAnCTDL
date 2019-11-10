#include "ArrPol.h"
#include <iostream>
using namespace std;

ArrPol::ArrPol()
{
	pol = NULL;
	length = 0;
}

ArrPol::ArrPol(const  ArrPol& orther)
{
	if (this == &orther)
		return;
	this->length = orther.length;
	this->pol = new ArrKar[this->length];
	for (int i = 0; i < this->length; i++)
		this->pol[i] = orther.pol[i];
}

ArrPol::~ArrPol()
{
	if (pol)
		delete[] pol;
}

void ArrPol::Print()
{
	cout << "Cac da thuc tim duoc: \n";
	for (int i = 0; i < length; i++)
	{
		pol[i].Print();
	}
}

void ArrPol::Add(ArrKar pol)
{
	if (this->pol == NULL || length == 0)
	{
		length++;
		this->pol = new ArrKar[1];
		this->pol[0] = pol;
	}
	else
	{
		ArrPol temp(*this);
		delete[] this->pol;
		this->length++;
		this->pol = new ArrKar[this->length];
		for (int i = 0; i < temp.length; i++)
			this->pol[i] = temp.pol[i];
		this->pol[this->length - 1] = pol;
	}
}

void ArrPol::Sort()
{
	for (int i = 0; i < length; i++)
		for (int j = length - 1; j > i; j--)
			if (pol[j] < pol[j - 1])
			{
				ArrKar temp = pol[j];
				pol[j] = pol[j - 1];
				pol[j - 1] = temp;
			}
}

bool ArrPol::Have(ArrKar pol)
{
	for (int i = 0; i < length; i++)
		if (pol.Same(this->pol[i]))
			return true;
	return false;
}
bool ArrPol::Have(int k)
{
	for (int i = 0; i < length; i++)
		if (this->pol[i].Have(k))
			return true;
	return false;
}
string* ArrPol::Translate()
{
	string* result = new string[this->length];
	for (int i = 0; i < this->length; i++)
		result[i] = this->pol[i].Translate();
	return result;
}

ArrPol& ArrPol::operator=(ArrPol orther)
{
	if (this == &orther)
		return (*this);
	if (this->pol)
		delete[] this->pol;
	this->length = orther.length;
	this->pol = new ArrKar[this->length];
	for (int i = 0; i < this->length; i++)
		this->pol[i] = orther.pol[i];
	return (*this);
}

ostream& operator<<(ostream& out, ArrPol obj)
{
	out << "Mo ta so do Karnaugh: " << endl;
	int num = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			num++;
			if (obj.Have(num))
				out << "1 ";
			else
				out << "0 ";
		}
		cout << endl;
	}
	out << "Cac da thuc toi tieu tim duoc: " << endl;
	string* result = obj.Translate();
	for (int i = 0; i < obj.Length(); i++)
		out << result[i] << endl;
	return out;
}
