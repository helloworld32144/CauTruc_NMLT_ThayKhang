#include <iostream>
using namespace std;

struct ThoiGian
{
	int Gio;
	int Phut;
	int Giay;
};
typedef struct ThoiGian THOIGIAN;

void Nhap(THOIGIAN&);
void Xuat(THOIGIAN);

int TinhSoGiay(THOIGIAN);
THOIGIAN KeTiep(THOIGIAN);
THOIGIAN TruocDo(THOIGIAN);

int ktHopLe(THOIGIAN);
int SoThuTu(THOIGIAN);
int KhoangCach(THOIGIAN, THOIGIAN);
int SoSanh(THOIGIAN, THOIGIAN);

int main()
{
	THOIGIAN A, B;
	cout << "Nhap thoi gian A" << endl;
	Nhap(A);
	Xuat(A);
	cout << endl;

	int g = TinhSoGiay(A);
	cout << "\nSo giay: " << g;
	cout << endl;

	THOIGIAN C, D;
	C = KeTiep(A);
	cout << "\nThoi gian ke tiep: ";
	Xuat(C);
	cout << endl;

	D = TruocDo(A);
	cout << "\nThoi gian truoc do: ";
	Xuat(D);
	cout << endl;

	int x = SoThuTu(A);
	cout << "\nSo thu giay ke tu luc 00:00:00 la: " << x;
	cout << endl;

	cout << "\nNhap thoi gian B" << endl;
	Nhap(B);

	if (ktHopLe(B))
		cout << "\nThoi gian hop le";
	else
		cout << "\nThoi gian khong hop le";
	Xuat(B);
	cout << endl;

	int kc = KhoangCach(A, B);
	cout << "\nKhoang cach giua hai thoi gian A va B: " << kc;
	cout << endl;

	if (SoSanh(A, B) == -1)
		cout << "\nThoi gian A nho hon thoi gian B";
	else if (SoSanh(A, B) == 1)
		cout << "\nThoi gian A lon hon thoi gian B";
	else
		cout << "\nThoi gian A bang thoi gian B";

	return 0;
}

void Nhap(THOIGIAN& x)
{
	cout << "Nhap gio: ";
	cin >> x.Gio;
	cout << "Nhap phut: ";
	cin >> x.Phut;
	cout << "Nhap giay: ";
	cin >> x.Giay;
}

void Xuat(THOIGIAN x)
{
	cout << "\nGio: " << x.Gio;
	cout << "\nPhut: " << x.Phut;
	cout << "\nGiay: " << x.Giay;
}

int TinhSoGiay(THOIGIAN x)
{
	return (x.Gio * 3600 + x.Phut * 60 + x.Giay);
}

THOIGIAN KeTiep(THOIGIAN x)
{
	THOIGIAN kt = x;
	kt.Giay = x.Giay + 1;
	if (x.Giay > 59)
	{
		kt.Phut = kt.Phut + 1;
		if (kt.Phut > 59)
		{
			kt.Gio = kt.Gio + 1;
			if (kt.Gio > 23)
				kt.Gio = 0;
			kt.Phut = 0;
		}
		kt.Giay = 0;
	}
	return kt;
}

THOIGIAN TruocDo(THOIGIAN x)
{
	x.Giay--;
	if (x.Giay < 0)
	{
		x.Phut--;
		if (x.Phut < 0)
		{
			x.Gio--;
			if (x.Gio < 0)
				x.Gio = 23;
			x.Phut = 59;
		}
		x.Giay = 59;
	}
	return x;
}

int ktHopLe(THOIGIAN x)
{
	if (!(x.Gio >= 0 && x.Gio <= 23))
		return 0;
	if (!(x.Phut >= 0 && x.Phut <= 59))
		return 0;
	if (!(x.Giay >= 0 && x.Giay <= 59))
		return 0;
	return 1;

}

int SoThuTu(THOIGIAN x)
{
	return x.Gio * 3600 + x.Phut * 60 + x.Giay;
}

int KhoangCach(THOIGIAN x, THOIGIAN y)
{
	int a = SoThuTu(x);
	int b = SoThuTu(y);
	return abs(a - b);
}

int SoSanh(THOIGIAN x, THOIGIAN y)
{
	if (x.Gio > y.Gio)
		return 1;
	if (x.Gio < y.Gio)
		return -1;
	if (x.Phut > y.Phut)
		return 1;
	if (x.Phut < y.Phut)
		return -1;
	if (x.Giay > y.Giay)
		return 1;
	if (x.Giay < y.Giay)
		return -1;
	return 0;

}