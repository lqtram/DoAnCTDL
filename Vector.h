# pragma once
# include <iostream>
using namespace std;

class Vector
{
private:
	float* v;
	int length;
public:
	Vector();
	Vector(int length);
	Vector(float* v, int length);
	Vector(const Vector& v1);
	~Vector();
public:
	void EnterVector();
	void SetLength(int length);
	void ExportVector();
	float* GetVector();
	int GetLength();
public:
	Vector& operator= (const Vector& v1);
	Vector Sum2Vector(Vector v1);
	Vector operator+ (Vector v1);
	Vector CalVector(int a);
	Vector operator* (int a);
};