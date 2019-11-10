#include "Karnaugh.h"
#include "ArrKar.h"
#include <iostream>
using namespace std;
//File này chưa hàm chính và các hàm tay chân (thực thi các bước lớn trong hàm chính)

//----------Các hàm tay chân---------------//
Karnaugh operator-(Karnaugh a, ArrKar b)
{
	Karnaugh result = a;
	for (int i = 0; i < b.length; i++)
		result = result - b.kar[i];
	return result;
}

ArrKar BigCell(Karnaugh Root)
{
	Karnaugh Exem[64];
	//-------x-------//   8
	int temp_0[] = { 1,2,5,6,9,10,13,14 }; Exem[0] = Karnaugh(temp_0, 8);
	int temp_1[] = { 3,4,7,8,11,12,15,16 }; Exem[1] = Karnaugh(temp_1, 8);
	int temp_2[] = { 2,3,6,7,10,11,14,15 }; Exem[2] = Karnaugh(temp_2, 8);
	int temp_3[] = { 1,4,5,8,9,12,13,16 }; Exem[3] = Karnaugh(temp_3, 8);
	int temp_4[] = { 1,2,3,4,5,6,7,8 }; Exem[4] = Karnaugh(temp_4, 8);
	int temp_5[] = { 9,10,11,12,13,14,15,16 }; Exem[5] = Karnaugh(temp_5, 8);
	int temp_6[] = { 1,2,3,4,13,14,15,16 }; Exem[6] = Karnaugh(temp_6, 8);
	int temp_7[] = { 5,6,7,8,9,10,11,12 }; Exem[7] = Karnaugh(temp_7, 8);
	//------xx-------//   8.6/2 = 24
	int temp_8[] = { 2,6,10,14 }; Exem[8] = Karnaugh(temp_8, 4);
	int temp_9[] = { 1,5,9,13 }; Exem[9] = Karnaugh(temp_9, 4);
	int temp_10[] = { 1,2,5,6 }; Exem[10] = Karnaugh(temp_10, 4);
	int temp_11[] = { 9,10,13,14 }; Exem[11] = Karnaugh(temp_11, 4);
	int temp_12[] = { 5,6,9,10 }; Exem[12] = Karnaugh(temp_12, 4);
	int temp_13[] = { 1,2,13,14 }; Exem[13] = Karnaugh(temp_13, 4);
	int temp_14[] = { 3,7,11,12 }; Exem[14] = Karnaugh(temp_14, 4);
	int temp_15[] = { 4,8,12,16 }; Exem[15] = Karnaugh(temp_15, 4);
	int temp_16[] = { 3,4,7,8 }; Exem[16] = Karnaugh(temp_16, 4);
	int temp_17[] = { 11,12,15,16 }; Exem[17] = Karnaugh(temp_17, 4);
	int temp_18[] = { 7,8,11,12 }; Exem[18] = Karnaugh(temp_18, 4);
	int temp_19[] = { 3,4,15,16 }; Exem[19] = Karnaugh(temp_19, 4);
	int temp_20[] = { 2,3,6,7 }; Exem[20] = Karnaugh(temp_20, 4);
	int temp_21[] = { 10,11,14,15 }; Exem[21] = Karnaugh(temp_21, 4);
	int temp_22[] = { 6,7,10,11 }; Exem[22] = Karnaugh(temp_22, 4);
	int temp_23[] = { 2,3,14,15 }; Exem[23] = Karnaugh(temp_23, 4);
	int temp_24[] = { 1,4,5,8 }; Exem[24] = Karnaugh(temp_24, 4);
	int temp_25[] = { 9,12,13,16 }; Exem[25] = Karnaugh(temp_25, 4);
	int temp_26[] = { 5,8,9,12 }; Exem[26] = Karnaugh(temp_26, 4);
	int temp_27[] = { 1,4,13,16 }; Exem[27] = Karnaugh(temp_27, 4);
	int temp_28[] = { 5,6,7,8 }; Exem[28] = Karnaugh(temp_28, 4);
	int temp_29[] = { 1,2,3,4 }; Exem[29] = Karnaugh(temp_29, 4);
	int temp_30[] = { 9,10,11,12 }; Exem[30] = Karnaugh(temp_30, 4);
	int temp_31[] = { 13,14,15,16 }; Exem[31] = Karnaugh(temp_31, 4);
	//------xxx-------//   8.6.4/6 = 32
	int temp_32[] = { 2,6 }; Exem[32] = Karnaugh(temp_32, 2);
	int temp_33[] = { 3,7 }; Exem[33] = Karnaugh(temp_33, 2);
	int temp_34[] = { 1,5 }; Exem[34] = Karnaugh(temp_34, 2);
	int temp_35[] = { 10,14 }; Exem[35] = Karnaugh(temp_35, 2);
	int temp_36[] = { 4,8 }; Exem[36] = Karnaugh(temp_36, 2);
	int temp_37[] = { 9,13 }; Exem[37] = Karnaugh(temp_37, 2);
	int temp_38[] = { 11,15 }; Exem[38] = Karnaugh(temp_38, 2);
	int temp_39[] = { 12,16 }; Exem[39] = Karnaugh(temp_39, 2);
	int temp_40[] = { 6,7 }; Exem[40] = Karnaugh(temp_40, 2);
	int temp_41[] = { 5,8 }; Exem[41] = Karnaugh(temp_41, 2);
	int temp_42[] = { 10,11 }; Exem[42] = Karnaugh(temp_42, 2);
	int temp_43[] = { 2,3 }; Exem[43] = Karnaugh(temp_43, 2);
	int temp_44[] = { 9,12 }; Exem[44] = Karnaugh(temp_44, 2);
	int temp_45[] = { 14,15 }; Exem[45] = Karnaugh(temp_45, 2);
	int temp_46[] = { 1,4 }; Exem[46] = Karnaugh(temp_46, 2);
	int temp_47[] = { 13,16 }; Exem[47] = Karnaugh(temp_47, 2);
	int temp_48[] = { 5,6 }; Exem[48] = Karnaugh(temp_48, 2);
	int temp_49[] = { 9,10 }; Exem[49] = Karnaugh(temp_49, 2);
	int temp_50[] = { 1,2 }; Exem[50] = Karnaugh(temp_50, 2);
	int temp_51[] = { 7,8 }; Exem[51] = Karnaugh(temp_51, 2);
	int temp_52[] = { 13,14 }; Exem[52] = Karnaugh(temp_52, 2);
	int temp_53[] = { 3,4 }; Exem[53] = Karnaugh(temp_53, 2);
	int temp_54[] = { 11,12 }; Exem[54] = Karnaugh(temp_54, 2);
	int temp_55[] = { 15,16 }; Exem[55] = Karnaugh(temp_55, 2);
	int temp_56[] = { 6,10 }; Exem[56] = Karnaugh(temp_56, 2);
	int temp_57[] = { 2,14 }; Exem[57] = Karnaugh(temp_57, 2);
	int temp_58[] = { 7,11 }; Exem[58] = Karnaugh(temp_58, 2);
	int temp_59[] = { 5,9 }; Exem[59] = Karnaugh(temp_59, 2);
	int temp_60[] = { 3,15 }; Exem[60] = Karnaugh(temp_60, 2);
	int temp_61[] = { 8,12 }; Exem[61] = Karnaugh(temp_61, 2);
	int temp_62[] = { 1,13 }; Exem[62] = Karnaugh(temp_62, 2);
	int temp_63[] = { 4,16 }; Exem[63] = Karnaugh(temp_63, 2);

	ArrKar BIGCell;

	for (int i = 0; i < 64; i++)
	{
		if (Exem[i].Belong(Root))
			BIGCell.Add(Exem[i]);
	}
	for (int i = 0; i < BIGCell.Length(); i++)
	{
		for (int j = 0; j < BIGCell.Length(); j++)
		{
			if (BIGCell.kar[i].Belong(BIGCell.kar[j]) && i != j)
			{
				BIGCell.Del(BIGCell.kar[i]);
				i--; //Khi xóa 1 số phải lui lại để không bỏ sót trường hợp
				break;
			}
		}
	}
	return BIGCell;
}
ArrKar BigCellRequired(Karnaugh Root, ArrKar BIGCell)
{
	ArrKar BIGCellRequired;
	for (int i = 0; i < Root.length; i++)
	{
		int _bool = 0;
		for (int j = 0; j < BIGCell.length; j++)
		{
			if (BIGCell.kar[j].Have(Root.arr[i]))
				_bool++;
		}
		if (_bool == 1)
		{
			for (int j = 0; j < BIGCell.length; j++)
			{
				if (BIGCell.kar[j].Have(Root.arr[i]) && !BIGCellRequired.Have(BIGCell.kar[j]))
					BIGCellRequired.Add(BIGCell.kar[j]);
			}
		}
	}
	return BIGCellRequired;
}
//Đã gán BGR cho từng Temp, n ban đầu bằng 0, hàm này dùng thuật toán véc cạn
void Optimal(Karnaugh Root, ArrKar BIGCell, ArrKar BIGCellRequired, ArrPol& Polynomial)
{
	if ((Root - BIGCellRequired).length == 0) //Điều kiện dừng
	{
		Polynomial.Add(BIGCellRequired);
		return;
	}

	int _bool = 0;

	for (int i = 0; i < (Root - BIGCellRequired).length; i++)
	{
		_bool = 0;
		for (int j = 0; j < (BIGCell - BIGCellRequired).length; j++)
		{
			if ((BIGCell - BIGCellRequired).kar[j].Have((Root - BIGCellRequired).arr[i])) //Xét điều kiện
			{
				_bool++;
				Karnaugh temp = (BIGCell - BIGCellRequired).kar[j];
				BIGCellRequired.Add(temp);
				Optimal(Root, BIGCell, BIGCellRequired, Polynomial); //đệ quy
				BIGCellRequired.Del(temp);
			}
		}
		if (_bool == 0) //Nếu ô không có trong BigCell thì sẽ được tạo ra một Karnaugh (xxxx) và thêm vào đa thức 
		{
			Karnaugh temp((Root - BIGCellRequired).arr[i]);
			BIGCellRequired.Add(temp);
			i--;
		}
	}

	if (_bool == 0 && (Root - BIGCellRequired).length == 0) //Trường hợp này là khi ô cuối cùng không có trong BigCell thì vẫn cộng vào mảng được. Nếu không có đoạn này thì đa thức cuối cùng sẽ bị bỏ qua
	{
		Polynomial.Add(BIGCellRequired);
	}
}

void ArrPol::Standardized()
{
	if (length == 0 || length == 1)
		return;
	ArrPol Temp(*this);
	delete[] this->pol;
	this->length = 0;
	for (int i = 0; i < Temp.length; i++)
		if (!this->Have(Temp.pol[i]))
			this->Add(Temp.pol[i]);
	this->Sort();
}

void ArrPol::MinimalPolynomial()
{
	if (length == 0 || length == 1)
		return;
	ArrPol Temp(*this);
	delete[] this->pol;
	this->length = 0;
	this->Add(Temp.pol[0]);
	for (int i = 0; i < Temp.length - 1; i++)
	{
		if (Temp.pol[i] == Temp.pol[i + 1])
			this->Add(Temp.pol[i + 1]);
		else
			break;
	}
}
//-----------Hàm chính---------------//
ArrPol Karnaugh::MinimalPolynomial()
{
	ArrKar _BigCell = BigCell(*this); //Tìm các tế bào lớn
	ArrKar _BigCellRequired = BigCellRequired(*this, _BigCell); //Tìm các tế bào lớn bắt buộc

	ArrPol Polynomial;
	Optimal(*this, _BigCell, _BigCellRequired, Polynomial); //Đệ quy tìm các đa thức có thể xuất hiện, dựa trên các tế bào lớn bắt buộc tìm được trước đó
	Polynomial.Standardized(); //Chuẩn hóa lại cái đa thức vừa tìm được (xóa các phần tử trùng, sắp xếp)
	Polynomial.MinimalPolynomial(); //Lấy các đa thức đơn giản nhất làm kết quả

	return Polynomial;
}