#include <iostream>
using namespace std;

struct PhanSo
{
	int Tu;
	int Mau;
};

typedef struct PhanSo PHANSO;

void Nhap(PHANSO&);
void Xuat(PHANSO);

int ktDuong(PHANSO);
int ktAm(PHANSO);

int UCLN(int, int);
void RutGon(PHANSO&);

PHANSO Tong(PHANSO, PHANSO);
PHANSO Hieu(PHANSO, PHANSO);
PHANSO Tich(PHANSO, PHANSO);
PHANSO Thuong(PHANSO, PHANSO);

int ktCoNghia(PHANSO);
int ktToiGian(PHANSO);

void QuiDongMau(PHANSO&, PHANSO&);
void QuiDongTu(PHANSO&, PHANSO&);

int SoSanh(PHANSO, PHANSO);

PHANSO operator+(PHANSO, PHANSO);
PHANSO operator-(PHANSO, PHANSO);
PHANSO operator*(PHANSO, PHANSO);
PHANSO operator/(PHANSO, PHANSO);

int main()
{
	PHANSO A, B;
	cout << "Nhap phan so 1" << endl;
	Nhap(A);
	cout << "\nNhap phan so 2" << endl;
	Nhap(B);

	cout << "\nPhan so 1: ";
	Xuat(A);
	cout << "\nPhan so 2: ";
	Xuat(B);

	if (ktDuong(A))
		cout << "\nA la phan so duong" << endl;
	else
		cout << "\nA khong la phan so duong" << endl;

	PHANSO tong = Tong(A, B);
	cout << "\nTong hai phan so la(1): ";
	Xuat(tong);
	cout << "\nTong hai phan so la(2): ";
	Xuat(A + B);

	PHANSO hieu = Hieu(A, B);
	cout << "\nHieu hai phan so la(1): ";
	Xuat(hieu);
	cout << "\nHieu hai phan so la(2): ";
	Xuat(A - B);

	PHANSO tich = Tich(A, B);
	cout << "\nTich hai phan so la(1): ";
	Xuat(tich);
	cout << "\nTich hai phan so la(2): ";
	Xuat(A * B);

	PHANSO thuong = Thuong(A, B);
	cout << "\nThuong hai phan so la(1): ";
	Xuat(thuong);
	cout << "\nThuong hai phan so la(2): ";
	Xuat(A/B);

	if (ktCoNghia(B))
		cout << "\nB co nghia" << endl;
	else
		cout << "\nA khong co nghia" << endl;

	if (ktCoNghia(B))
		cout << "\nB toi gian" << endl;
	else
		cout << "\nA chua toi gian" << endl;

	if (SoSanh(A, B))
		cout << "\nA lon hon B" << endl;
	else if (SoSanh(A, B) == -1)
		cout << "\nA nho hon B" << endl;
	else
		cout << "\nA bang B" << endl;
	return 0;
}

void Nhap(PHANSO& x)
{
	cout << "Nhap tu so: ";
	cin >> x.Tu;
	cout << "Nhap mau so: ";
	cin >> x.Mau;
}

void Xuat(PHANSO x)
{
	cout << x.Tu << "/" << x.Mau;
}

int ktDuong(PHANSO x)
{
	if (x.Tu * x.Mau > 0)
		return 1;
	return 0;
}

int ktAm(PHANSO x)
{
	if (x.Tu * x.Mau < 0)
		return 1;
	return 0;
}

int UCLN(int a, int b)
{
	a = abs(a);
	b = abs(b);
	while (a * b != 0)
		if (a > b)
			a -= b;
		else
			b -= a;
	return a + b;
}

void RutGon(PHANSO& x)
{
	int kq = UCLN(x.Tu, x.Mau);
	x.Tu = x.Tu / kq;
	x.Mau = x.Mau / kq;
}

PHANSO Tong(PHANSO x, PHANSO y)
{
	PHANSO kq;
	kq.Tu = x.Tu * y.Mau + y.Tu * x.Mau;
	kq.Mau = x.Mau * y.Mau;
	RutGon(kq);
	return kq;
}

PHANSO Hieu(PHANSO x, PHANSO y)
{
	PHANSO kq;
	kq.Tu = x.Tu * y.Mau - y.Tu * x.Mau;
	kq.Mau = x.Mau * y.Mau;
	RutGon(kq);
	return kq;
}

PHANSO Tich(PHANSO x, PHANSO y)
{
	PHANSO kq;
	kq.Tu = x.Tu * y.Tu;
	kq.Mau = x.Mau * y.Mau;
	RutGon(kq);
	return kq;
}

PHANSO Thuong(PHANSO x, PHANSO y)
{
	PHANSO kq;
	kq.Tu = x.Tu * y.Mau;
	kq.Mau = x.Mau * y.Tu;
	RutGon(kq);
	return kq;
}

int ktCoNghia(PHANSO x)
{
	if (x.Mau != 0)
		return 1;
	return 0;
}

int ktToiGian(PHANSO x)
{
	if (UCLN(x.Tu, x.Mau) == 1)
		return 1;
	return 0;
}

void QuiDongMau(PHANSO& x, PHANSO& y)
{
	int mc = x.Mau * y.Mau;
	x.Tu = x.Tu * y.Mau;
	y.Tu = x.Mau * y.Tu;
	x.Mau = mc;
	y.Mau = mc;
}

void QuiDongTu(PHANSO& x, PHANSO& y)
{
	int tc = x.Tu * y.Tu;
	x.Mau = x.Mau * y.Tu;
	y.Mau = y.Mau * x.Tu;
	x.Tu = tc;
	y.Tu = tc;
}

int SoSanh(PHANSO x, PHANSO y)
{
	float a = (float)x.Tu / x.Mau;
	float b = (float)y.Tu / y.Mau;
	if (a > b)
		return 1;
	if (a < b)
		return -1;
	return 0;
}

PHANSO operator+(PHANSO x, PHANSO y)
{
	PHANSO kq;
	kq.Tu = x.Tu * y.Mau + y.Tu * x.Mau;
	kq.Mau = x.Mau * y.Mau;
	RutGon(kq);
	return kq;
}

PHANSO operator-(PHANSO x, PHANSO y)
{
	PHANSO kq;
	kq.Tu = x.Tu * y.Mau - y.Tu * x.Mau;
	kq.Mau = x.Mau * y.Mau;
	RutGon(kq);
	return kq;
}

PHANSO operator*(PHANSO x, PHANSO y)
{
	PHANSO kq;
	kq.Tu = x.Tu * y.Tu;
	kq.Mau = x.Mau * y.Mau;
	RutGon(kq);
	return kq;
}

PHANSO operator/(PHANSO x, PHANSO y)
{
	PHANSO kq;
	kq.Tu = x.Tu * y.Mau;
	kq.Mau = x.Mau * y.Tu;
	RutGon(kq);
	return kq;
}