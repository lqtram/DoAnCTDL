#include "Equations.h"
#include <iomanip>

Equations::Equations() {} //Không có thành phần động nên chỉ để rổng là được

Equations::~Equations() {} //Như trên


void Equations::Enter()
{
	do
	{
		cout << "Nhap ma tran he so (factor): " << endl;
		this->factor.EnterMatrix();
		cout << "Nhap ma tran he so tu do(free factor): " << endl;
		this->freeFactor.EnterMatrix();
	} while (this->freeFactor.GetLencol() != 1 || this->factor.GetLenrow() != this->freeFactor.GetLenrow());
}

void Equations::Export()
{
	float** _factor = this->factor.GetMatrix();
	float** _freeFactor = this->freeFactor.GetMatrix();

	for (int i = 0; i < this->factor.GetLenrow(); i++)
	{
		for (int j = 0; j < factor.GetLencol(); j++)
		{
			cout << setw(6) << setprecision(3) << _factor[i][j] << " ";
		}
		cout << " | " << setw(6) << setprecision(3) << _freeFactor[i][0] << " ";
		cout << endl;
	}
}

void Equations::stepMatrix()
{
	//Lấy vùng nhớ của 2 trận và xử lí trên nó
	float** _factor = this->factor.GetMatrix();
	float** _freeFactor = this->freeFactor.GetMatrix();

	int i, j;
	i = j = 0; //B1: khởi tạo i,j = 0
	for (i = 0; i < factor.GetLenrow(); i++)
	{
		if (i >= factor.GetLenrow() || j >= factor.GetLencol()) //B2: điều kiện dừng
			return;

		if (_factor[i][j] != 0) //B3: nếu m[i][j] != 0 thì thực hiện việc trừ từng dòng dưới nó với các hệ số
		{
			for (int k = i + 1; k < factor.GetLenrow(); k++)
			{
				float factor = _factor[k][j] / _factor[i][j];
				this->factor.minusRow(k + 1, i + 1, factor);//Hàm tính từ 1, còn mảng ta đang thực hiện tính từ 0
				this->freeFactor.minusRow(k + 1, i + 1, factor);
			}
			j++; //tăng j và quay về bước 2
		}
		else //B3: nếu m[i][j] == 0 thì sang B4
		{
			for (int k = i + 1; k < factor.GetLenrow(); k++)
			{
				if (_factor[k][j] != 0)//B4: nếu có m[k][j] != 0 (k > i) thì thực hiện trao đổi dòng
				{
					swap(_factor[i], _factor[k]);
					swap(_freeFactor[i], _freeFactor[k]);
					i--;//Lùi đi 1 để thực hiện LẠI B3
					break;//Gặp một giá trị khác không phải thoát vòng lặp ngay lập tức
				}
				if (k == factor.GetLenrow() - 1)//B4: nếu thỏa điều kiện này tức mọi m[k][j] == 0, ta tăng j và quay về B2 (vẫn không tăng i)
				{
					j++;
					i--;
				}
			}
		}
	}
}

void Equations::compact_stepMatrix()
{
	this->stepMatrix();

	//Lấy mảng 2 chiều trong các ma trận để xử lý
	float** _factor = this->factor.GetMatrix();
	float** _freeFactor = this->freeFactor.GetMatrix();

	for (int row = factor.GetLenrow() - 1; row >= 0; row--)//Duyệt từ dòng dưới cùng lên, theo thứ tự này thì chắc chắn các dòng ở dưới sẽ đơn gian trước và không cần khử nữa
	{
		for (int col = 0; col < factor.GetLencol(); col++)
		{
			if (_factor[row][col] != 0) //Khi đụng phải giá trị khác không đầu tiên ta bắt đầu khử các dòng trên theo hệ số (phụ thuộc vào giá trị _factor[rol][col])
			{
				float f = _factor[row][col];

				//Rút gọn trước
				this->factor.divideRow(row + 1, f);
				this->freeFactor.divideRow(row + 1, f);

				//Khử các dòng ở trên 
				for (int i = 0; i < row; i++)
				{
					float _f = _factor[i][col];
					this->factor.minusRow(i + 1, row + 1, _f);
					this->freeFactor.minusRow(i + 1, row + 1, _f);
				}
				break;//Thoát khi đụng phải giá trị khác 0 đầu tiên trên dòng
			}
		}
	}
}

void Equations::Solution()
{
	//Chuyển qua ma hệ phương trình tạm (tránh làm thay đổi hệ pt gốc) đưa về dạng bậc thang rút gọn
	Equations Temp;
	Temp = *this;
	Temp.compact_stepMatrix();

	int row = Temp.factor.GetLenrow();
	int col = Temp.factor.GetLencol();

	//Lấy mảng 2 chiều trong các ma trận để xử lý
	float** _factor = Temp.factor.GetMatrix();
	float** _freeFactor = Temp.freeFactor.GetMatrix();

	int rank = Temp.factor.Rank();

	//Trường hợp 1: nếu có 1 dòng 0 0 0 .. 0 | !=0 thì vô nghiệm
	for (int i = row - 1; i >= 0; i--)
	{
		if (_freeFactor[i][0] != 0 && i > rank - 1)
		{
			cout << "Phuong trinh vo nghiem.\n";
			return;
		}
	}

	/*Trường hợp 2: nếu số cột của ma trận factor == rank của ma trận rút gọn thì có 1 nghiệm duy nhất
	 Ma trận bậc thang rút gọn ở trường hợp này có dạng

		1 0 0 0 ... 0 | x1
		0 1 0 0 ... 0 |	x2
		0 0 1 0 ... 0 | x3
		0 0 0 1 ... 0 | x4
		............. | ..
		0 0 0 0     1 | xn

	Do đó ta sẽ lấy trực tiếp các gia trị bên _freeFact để gán vào kq */
	if (rank == col)
	{
		cout << "Phuong trinh tren co mot nghiem duy nhat: \n";
		for (int i = 0; i < rank; i++)
		{
			cout << "   x[" << i + 1 << "] = " << _freeFactor[i][0] << endl;
		}
	}
	/*Trường hợp 3: Khác 2 trường hợp trên, thì sẽ có vô số nghiệm và sẽ có (col - rank) ẩn tự do
	Ma trận bậc thang rút gọn ở trường hợp này có dạng (ví dụ)

		1 a 0 0 ... 0 | x1
		0 0 1 0 ... 0 | x2
		0 0 0 1 ... 0 | x3
		0 0 0 0 ... 0 | x4
		............. | ..
		0 0 0 0     1 | xn

		Do đó ta sẽ lấy trực tiếp các gia trị bên _freeFact để gán vào kq */
	else
	{
		cout << "Phuong trinh co vo so nghiem, gom " << col - rank << " an tu do: " << endl;
		int* _freeHide = new int[col - rank];
		//Tìm vị trí các ẩn tự do
		int k = 0;
		for (int i = 0; i < col; i++)
		{
			if (_factor[i - k][i] == 0)
			{
				_freeHide[k] = i;
				k++;
			}
		}
		char c = 'a';
		int n = 0;
		for (int i = 0; i < col; i++)
		{
			if (i != _freeHide[n])
			{
				cout << "   x[" << i + 1 << "] = ";
				for (int j = 0; j < k; j++)
				{
					if (_factor[i - n][_freeHide[j]] <= 0)
						cout << -_factor[i - n][_freeHide[j]] << "*" << char(c + j); //Hệ số dương
					else
						cout << "(" << -_factor[i - n][_freeHide[j]] << ")*" << char(c + j); //Hệ số âm
					cout << " + ";
				}
				if (_freeFactor[i - n][0] <= 0)
					cout << "(" << _freeFactor[i - n][0] << ")\n"; //Hệ số âm
				else
					cout << _freeFactor[i - n][0] << endl; //Hệ số dương
			}
			else
			{
				cout << "   x[" << i + 1 << "] = " << char(c + n) << endl;
				n++;
			}
		}
	}

}