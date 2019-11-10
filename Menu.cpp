#include "Menu.h"

void Menu()
{
	bool isExit = false;
	int option; //biến lưu lại lựa chọn người dùng
	do
	{
		system("cls");
		cout << "CAU TRUC DU LIEU & GIAI THUAT             Sinh vien: Ly Quynh Tram\n";
		cout << "DO AN 1                                              Cao Minh Tri \n";
		cout << "      ======================================================\n";
		cout << "   MENU  \n\n";
		cout << "   1.  Ham Bool.\n";
		cout << "   2.  Vector.\n";
		cout << "   3.  Ma tran.\n";
		cout << "   0.  Thoat.\n\n";


		cout << "~  Nhap lua chon (0-3): "; cin >> option;
		while (option > 3 || option < 0)
		{
			cout << "~  Luu chon khong hop le, nhap lai (0-3): "; cin >> option;
		}

		switch (option)
		{
			//Hàm bool
		case 1:
		{
			system("cls");
			cout << "CAU TRUC DU LIEU & GIAI THUAT             Sinh vien: Ly Quynh Tram\n";
			cout << "DO AN 1                                              Cao Minh Tri \n";
			cout << "      ======================================================\n";
			cout << "Ham bool > Tim tat ca cac cong thuc toi tieu cua ham Bool: \n\n";

			cout << "*Luu y: chi giai duoc ham bool voi kich thuoc 4*4!\n";
			Karnaugh Root;
			cin >> Root;
			ArrPol Polynomial = Root.MinimalPolynomial();
			cout << Polynomial;

			cout << "\n\nNhan mot phim bat ki de thoat!\n"; system("pause");

			break;
		}
		//Vector
		case 2:
		{
			cout << "      ======================================================\n";
			cout << " Cac phep toan voi Vector: \n";
			cout << "   1.  Cong 2 vector.\n";
			cout << "   2.  Nhan vector voi mot so nguyen k.\n";
			cout << "   0.  Quay lai.\n\n";

			int option_2;
			cout << "~  Nhap lua chon (0-2): "; cin >> option_2;
			while (option_2 > 2 || option_2 < 0)
			{
				cout << "~  Luu chon khong hop le, nhap lai (0-2): "; cin >> option_2;
			}
			switch (option_2)
			{
			case 1:
			{
				system("cls");
				cout << "CAU TRUC DU LIEU & GIAI THUAT             Sinh vien: Ly Quynh Tram\n";
				cout << "DO AN 1                                              Cao Minh Tri \n";
				cout << "      ======================================================\n";
				cout << "Vector > Cong 2 vector: \n\n";

				int m, n;
				Vector A, B;
				cout << "Nhap so luong phan tu cua vector thu 1: ";
				cin >> m;
				A.SetLength(m);
				cout << "Nhap gia tri cac phan tu cua vector 1:" << endl;
				A.EnterVector();
				cout << "Nhap so luong phan tu cua vector thu 2: ";
				cin >> n;
				B.SetLength(n);
				cout << "Nhap gia tri cac phan tu cua vector 2:" << endl;
				B.EnterVector();

				Vector D;
				cout << "Tong 2 vector: " << endl;
				D = A + B;
				if (A.GetLength() == B.GetLength())
					D.ExportVector();

				cout << "\n\nNhan mot phim bat ki de thoat!\n"; system("pause");
				break;
			}
			case 2:
			{
				system("cls");
				cout << "CAU TRUC DU LIEU & GIAI THUAT             Sinh vien: Ly Quynh Tram\n";
				cout << "DO AN 1                                              Cao Minh Tri \n";
				cout << "      ======================================================\n";
				cout << "Vector > Nhan vector voi mot so nguyen k: \n\n";

				int m;
				Vector A;
				cout << "Nhap so luong phan tu cua vector: ";
				cin >> m;
				A.SetLength(m);
				cout << "Nhap gia tri cac phan tu cua vector:" << endl;
				A.EnterVector();

				int k;
				cout << "Nhap so nguyen k: "; cin >> k;

				cout << "Tich cua vector da nhap voi so nguyen k: " << endl;
				Vector C = A * k;
				C.ExportVector();

				cout << "\n\nNhan mot phim bat ki de thoat!\n"; system("pause");
				break;
			}
			default:
				break;
			}

			break;
		}
		//Ma trận
		case 3:
		{
			cout << "      ======================================================\n";
			cout << " Cac phep toan voi Vector: \n";
			cout << "   1.  Tim dinh thuc cua ma tran.\n";
			cout << "   2.  Nghich dao ma tran.\n";
			cout << "   3.  Tich hai ma tran.\n";
			cout << "   4.  Tim hang cua ma tran.\n";
			cout << "   5.  Giai he phuong trinh tuyen tinh.\n";
			cout << "   0.  Quay lai.\n\n";

			int option_3;
			cout << "~  Nhap lua chon (0-5): "; cin >> option_3;
			while (option_3 > 5 || option_3 < 0)
			{
				cout << "~  Luu chon khong hop le, nhap lai (0-5): "; cin >> option_3;
			}
			switch (option_3)
			{
			case 1:
			{
				system("cls");
				cout << "CAU TRUC DU LIEU & GIAI THUAT             Sinh vien: Ly Quynh Tram\n";
				cout << "DO AN 1                                              Cao Minh Tri \n";
				cout << "      ======================================================\n";
				cout << "Ma tran > Tim dinh thuc: \n\n";

				Matrix A;
				cout << "Nhap ma tran: \n";
				A.EnterMatrix();
				cout << "Ma tran da nhap: " << endl;
				A.ExportMatrix();
				cout << "Dinh thuc cua ma tran da nhap: " << A.Det();

				cout << "\n\nNhan mot phim bat ki de thoat!\n"; system("pause");
				break;
			}
			case 2:
			{
				system("cls");
				cout << "CAU TRUC DU LIEU & GIAI THUAT             Sinh vien: Ly Quynh Tram\n";
				cout << "DO AN 1                                              Cao Minh Tri \n";
				cout << "      ======================================================\n";
				cout << "Ma tran > Nghich dao ma tran: \n\n";

				Matrix A;
				cout << "Nhap ma tran: \n";
				A.EnterMatrix();
				cout << "Ma tran da nhap: " << endl;
				A.ExportMatrix();

				Matrix B = A.Inverse();
				if (A.GetLencol() == A.GetLenrow())
				{
					if (B.Det() != 0)
					{
						cout << "Nghich dao cua ma tran da nhap: \n";
						B.ExportMatrix();
					}
				}

				cout << "\n\nNhan mot phim bat ki de thoat!\n"; system("pause");
				break;
			}
			case 3:
			{
				system("cls");
				cout << "CAU TRUC DU LIEU & GIAI THUAT             Sinh vien: Ly Quynh Tram\n";
				cout << "DO AN 1                                              Cao Minh Tri \n";
				cout << "      ======================================================\n";
				cout << "Ma tran > Tich hai ma tran: \n\n";

				Matrix A;
				cout << "Nhap ma tran A: \n";
				A.EnterMatrix();
				cout << "Ma tran A da nhap: " << endl;
				A.ExportMatrix();

				Matrix B;
				cout << "Nhap ma tran B: \n";
				B.EnterMatrix();
				cout << "Ma tran B da nhap: " << endl;
				B.ExportMatrix();

				if (A.GetLencol() != B.GetLenrow())
					cout << "Hai ma tran da nhap khong the nhan voi nhau!";
				else
				{
					cout << "Tich hai ma tran da nhap A*B: \n";
					(A*B).ExportMatrix();
				}

				cout << "\n\nNhan mot phim bat ki de thoat!\n"; system("pause");
				break;
			}
			case 4:
			{
				system("cls");
				cout << "CAU TRUC DU LIEU & GIAI THUAT             Sinh vien: Ly Quynh Tram\n";
				cout << "DO AN 1                                              Cao Minh Tri \n";
				cout << "      ======================================================\n";
				cout << "Ma tran > Tim hang cua ma tran: \n\n";

				Matrix A;
				cout << "Nhap ma tran: \n";
				A.EnterMatrix();
				cout << "Ma tran da nhap A: " << endl;
				A.ExportMatrix();

				cout << "Hang ma tran da nhap: " << A.Rank();

				cout << "\n\nNhan mot phim bat ki de thoat!\n"; system("pause");
				break;
			}
			case 5:
			{
				system("cls");
				cout << "CAU TRUC DU LIEU & GIAI THUAT             Sinh vien: Ly Quynh Tram\n";
				cout << "DO AN 1                                              Cao Minh Tri \n";
				cout << "      ======================================================\n";
				cout << "Ma tran > Giai he phuong trinh tuyen tinh: \n\n";

				Equations A;
				A.Enter();
				cout << "He phuong trinh tuyen tinh da nhap: " << endl;
				A.Export();
				A.compact_stepMatrix();
				cout << "Giai he: " << endl;
				A.Solution();

				cout << "\n\nNhan mot phim bat ki de thoat!\n"; system("pause");
				break;
			}
			default:
				break;
			}

			break;
		}

		case 0:
		{
			isExit = true;
			break;
		}
		}
	} while (!isExit);
}