#include "Matrix.h"
#include <iomanip>
#include <math.h>

Matrix::Matrix()
{
	lenrow = lencol = 0;
	m = NULL;
}

Matrix::Matrix(int lenrow, int lencol)
{
	while (lenrow < 0)
	{
		cout << "Gia tri khong hop le. Nhap lai so dong: ";
		cin >> lenrow;
	}
	while (lencol < 0)
	{
		cout << "Gia tri khong hop le. Nhap lai so cot: ";
		cin >> lencol;
	}
	this->lenrow = lenrow;
	this->lencol = lencol;
	this->m = new float*[lenrow];
	for (int i = 0; i < lenrow; i++)
	{
		this->m[i] = new float[lencol];
		for (int j = 0; j < lencol; j++)
			this->m[i][j] = 0;
	}
}

Matrix::Matrix(float **m, int lenrow, int lencol)
{
	while (lenrow < 0)
	{
		cout << "Gia tri khong hop le. Nhap lai so dong: ";
		cin >> lenrow;
	}
	while (lencol < 0)
	{
		cout << "Gia tri khong hop le. Nhap lai so cot: ";
		cin >> lencol;
	}
	this->lenrow = lenrow;
	this->lencol = lencol;
	this->m = new float*[lenrow];
	for (int i = 0; i < lenrow; i++)
	{
		this->m[i] = new float[lencol];
		for (int j = 0; j < lencol; j++)
			this->m[i][j] = m[i][j];
	}
}

Matrix::Matrix(const Matrix &m1)
{
	this->lenrow = m1.lenrow;
	this->lencol = m1.lencol;
	this->m = new float*[lenrow];
	for (int i = 0; i < lenrow; i++)
	{
		this->m[i] = new float[lencol];
		for (int j = 0; j < lencol; j++)
			this->m[i][j] = m1.m[i][j];
	}
}

Matrix::~Matrix()
{
	lenrow = lencol = NULL;
	if (m != NULL)
	{
		for (int i = 0; i < lenrow; i++)
			if (m[i] != NULL)
				delete[]m[i];
		delete[]m;
	}
}

void Matrix::SetLenrow(int lenrow)
{
	this->lenrow = lenrow;
}

void Matrix::SetLencol(int lencol)
{
	this->lencol = lencol;
}

void Matrix::EnterMatrix()
{
	if (m != NULL)
	{
		for (int i = 0; i < lenrow; i++)
			if (m[i] != NULL)
				delete[]m[i];
		delete[]m;
	}
	do
	{
		cout << "Nhap so dong: ";
		cin >> lenrow;
	} while (lenrow < 1);
	do
	{
		cout << "Nhap so cot: ";
		cin >> lencol;
	} while (lencol < 1);
	this->m = new float*[lenrow];
	for (int i = 0; i < lenrow; i++)
	{
		this->m[i] = new float[lencol];
		for (int j = 0; j < lencol; j++)
		{
			cout << "m[" << i + 1 << "][" << j + 1 << "]= ";
			cin >> m[i][j];
		}
	}
}

int Matrix::GetLenrow()
{
	return lenrow;
}

int Matrix::GetLencol()
{
	return lencol;
}

float** Matrix::GetMatrix()
{
	return m;
}

void Matrix::ExportMatrix()
{
	for (int i = 0; i < lenrow; i++)
	{
		for (int j = 0; j < lencol; j++)
		{
			cout << setw(6) << setprecision(3) << m[i][j] << " ";
		}
		cout << endl;
	}
}

Matrix& Matrix::operator=(const Matrix m1)
{
	if (this != &m1)
	{
		this->lenrow = m1.lenrow;
		this->lencol = m1.lencol;
		if (m != NULL)
		{
			for (int i = 0; i < lenrow; i++)
				if (m[i] != NULL)
					delete[]m[i];
			delete[]m;
		}
		this->m = new float*[lenrow];
		for (int i = 0; i < lenrow; i++)
		{
			this->m[i] = new float[lencol];
			for (int j = 0; j < lencol; j++)
				this->m[i][j] = m1.m[i][j];
		}
	}
	else return *this;
}

Matrix Matrix::CopyMatrixExceptRowCol(int row, int col) //chép ma trận đã cho vào ma trận mới bỏ đi dòng row và cột col
{
	Matrix temp(lenrow - 1, lencol - 1);
	int m = -1;
	int n;
	for (int i = 0; i < lenrow; i++)
	{
		if (i != row)
			m++;
		n = -1;
		for (int j = 0; j < lencol; j++)
		{
			if (j != col)
				n++;
			if (i != row && j != col)
			{
				temp.m[m][n] = this->m[i][j];
			}
		}
	}
	return temp;
}

float Matrix::Det()
{
	if (lenrow != lencol)
	{
		cout << "Ma tran khong phai la ma tran vuong" << endl;
		return NULL;
	}
	else
	{
		float det = 0;
		if (lenrow == 1)
			return m[0][0];
		else
		{
			for (int i = 0; i < lenrow; i++)
			{
				det += pow(-1, i)*m[0][i] * CopyMatrixExceptRowCol(0, i).Det();
			}
			return det;
		}
	}
}
Matrix Matrix::Inverse()
{
	if (lenrow != lencol)
	{
		cout << "Ma tran khong phai la ma tran vuong" << endl;
		return *this;
	}
	else
	{
		if (this->Det() == 0)
		{
			cout << "Ma tran khong co ma tran nghich dao" << endl;
			return *this;
		}
		else
		{
			Matrix inverse(lenrow, lencol);
			for (int i = 0; i < lenrow; i++)
			{
				for (int j = 0; j < lencol; j++)
				{
					inverse.m[i][j] = (pow(-1, i + j)*CopyMatrixExceptRowCol(j, i).Det()) / this->Det();
				}
			}
			return inverse;
		}
	}
}

Matrix Matrix::Cal2Matrix(Matrix m1)
{
	Matrix cal(lenrow, m1.lencol);
	for (int i = 0; i < lenrow; i++)
	{
		for (int j = 0; j < m1.lencol; j++)
		{
			for (int k = 0; k < lencol; k++)
			{
				cal.m[i][j] += m[i][k] * m1.m[k][j];
			}
		}
	}
	return cal;
}

Matrix Matrix::operator*(Matrix m1)
{
	Matrix cal(lenrow, m1.lencol);
	for (int i = 0; i < lenrow; i++)
	{
		for (int j = 0; j < m1.lencol; j++)
		{
			for (int k = 0; k < lencol; k++)
			{
				cal.m[i][j] += m[i][k] * m1.m[k][j];
			}
		}
	}
	return cal;
}

void Matrix::minusRow(int row_1, int row_2, float factor)
{
	for (int col = 0; col < lencol; col++)
	{
		float temp;
		temp = m[row_1 - 1][col] - factor * m[row_2 - 1][col] == -0 ? 0 : m[row_1 - 1][col] - factor * m[row_2 - 1][col];
		m[row_1 - 1][col] = round(temp * 10000) / 10000; //Làm tròn số, để tránh bị lỗi về dấu chấm động
	}
}
void Matrix::divideRow(int row, float factor)
{
	for (int col = 0; col < lencol; col++)
	{
		float temp;
		temp = m[row - 1][col] / factor == -0 ? 0 : m[row - 1][col] / factor; //Nếu nó bằng -0 thì cho bằng 0, vì số thập phân không hoàn toàn chính xác
		m[row - 1][col] = round(temp * 10000) / 10000; //Làm tròn số, để tránh bị lỗi về dấu chấm động
	}
}

void swap(float* &a, float* &b)
{
	float* temp = a;
	a = b;
	b = temp;
}

void Matrix::stepMatrix()
{
	int i, j;
	i = j = 0; //B1: khởi tạo i,j = 0
	for (i = 0; i < lenrow; i++)
	{
		if (i >= lenrow || j >= lencol) //B2: điều kiện dừng
			return;

		if (m[i][j] != 0) //B3: nếu m[i][j] != 0 thì thực hiện việc trừ từng dòng dưới nó với các hệ số
		{
			for (int k = i + 1; k < lenrow; k++)
			{
				float factor = m[k][j] / m[i][j];
				this->minusRow(k + 1, i + 1, factor);//Hàm tính từ 1, còn mảng ta đang thực hiện tính từ 0
			}
			j++; //tăng j và quay về bước 2
		}
		else //B3: nếu m[i][j] == 0 thì sang B4
		{
			for (int k = i + 1; k < lenrow; k++)
			{
				if (m[k][j] != 0)//B4: nếu có m[k][j] != 0 (k > i) thì thực hiện trao đổi dòng
				{
					swap(m[i], m[k]);
					i--;//Lùi đi 1 để thực hiện LẠI B3
					break;//Gặp một giá trị khác không phải thoát vòng lặp ngay lập tức
				}
				if (k == lenrow - 1)//B4: nếu thỏa điều kiện này tức mọi m[k][j] == 0, ta tăng j và quay về B2 (vẫn không tăng i)
				{
					j++;
					i--;
				}
			}
		}
	}
}

void Matrix::compact_stepMatrix()
{
	this->stepMatrix();

	for (int row = lenrow - 1; row >= 0; row--)
	{
		for (int col = 0; col < lencol; col++)
		{
			if (m[row][col] != 0)
			{
				this->divideRow(row + 1, m[row][col]);
				for (int i = 0; i < row; i++)
					this->minusRow(i + 1, row + 1, m[i][col]);
				break;
			}
		}
	}
}

int Matrix::Rank()
{
	Matrix temp(*this);//Dùng ma trận phụ để sau khi ra khỏi hàm ma trận gốc không bị thay đổi
	temp.stepMatrix();

	for (int row = 0; row < temp.lenrow; row++)
	{
		for (int col = 0; col < temp.lencol; col++)
		{
			if (temp.m[row][col] != 0)
				break;
			if (col == lencol - 1)
				return row;
		}
	}
	return lenrow;
}
