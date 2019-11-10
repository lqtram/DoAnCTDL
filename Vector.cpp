# include "Vector.h"

Vector::Vector()
{
	length = 0;
	v = NULL;
}
Vector::Vector(int length)
{
	while (length < 0)
	{
		cout << "Gia tri khong hop le. Nhap lai so phan tu= ";
		cin >> length;
	}
	this->length = length;
	v = new float[length + 1];
	for (int i = 1; i <= length; i++)
	{
		this->v[i] = 0;
	}
}

Vector::Vector(float* v, int length)
{
	while (length < 0)
	{
		cout << "Gia tri khong hop le. Nhap lai so phan tu= ";
		cin >> length;
	}
	this->length = length;
	this->v = v;
}

Vector::Vector(const Vector& v1)
{
	this->length = v1.length;
	v = new float[length + 1];
	for (int i = 1; i <= length; i++)
		this->v[i] = v1.v[i];
}

Vector::~Vector()
{
	length = NULL;
	if (v != NULL)
		delete[]v;
}

void Vector::EnterVector()
{
	v = new float[length + 1];
	for (int i = 1; i <= length; i++)
	{
		cin >> v[i];
	}
}

void Vector::SetLength(int length)
{
	while (length < 0)
	{
		cout << "Gia tri khong hop le. Nhap lai so phan tu= ";
		cin >> length;
	}
	this->length = length;
}

void Vector::ExportVector()
{
	cout << "( ";
	for (int i = 1; i <= length; i++)
		cout << v[i] << " ";
	cout << ")";
	cout << endl;
}

float* Vector::GetVector()
{
	return v;
}

int Vector::GetLength()
{
	return length;
}

Vector& Vector:: operator=(const Vector& v1)
{
	if (this != &v1)
	{
		if (this != NULL)
			delete[]v;
		this->length = v1.length;
		v = new float[length + 1];
		for (int i = 1; i <= length; i++)
			this->v[i] = v1.v[i];
	}
	return *this;
}

Vector Vector::Sum2Vector(Vector v1)
{
	Vector sum(length);
	if (v1.length == length)
	{
		for (int i = 1; i <= length; i++)
			sum.v[i] = v[i] + v1.v[i];
		return sum;
	}
	else
	{
		cout << "Hai vector co do dai khac nhau" << endl;
		return NULL;
	}
}

Vector Vector:: operator+ (Vector v1)
{
	Vector sum(length);
	if (v1.length == length)
	{
		for (int i = 1; i <= length; i++)
			sum.v[i] = v[i] + v1.v[i];
		return sum;
	}
	else
	{
		cout << "Hai vector co do dai khac nhau" << endl;
		return NULL;
	}
}

Vector Vector::CalVector(int a)
{
	Vector cal(length);
	for (int i = 1; i <= length; i++)
		cal.v[i] = a * v[i];
	return cal;
}

Vector Vector ::operator*(int a)
{
	Vector cal(length);
	for (int i = 1; i <= length; i++)
		cal.v[i] = a * v[i];
	return cal;
}