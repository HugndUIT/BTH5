#include <iostream>
#include <vector>
#include <string>
using namespace std;

class ChuyenXe {
protected:
    string MaSo, HoTenTaiXe;
    double SoXe, DoanhThu;
public:
    virtual void Nhap();
    virtual void Xuat();
    double getDoanhThu();  
};

void ChuyenXe::Nhap() {
    cout << "Nhap ma so chuyen xe: ";
    getline(cin, MaSo);
    cout << "Nhap ho ten tai xe: ";
    getline(cin, HoTenTaiXe);
    cout << "Nhap so xe: ";
    cin >> SoXe;
    cout << "Nhap doanh thu: ";
    cin >> DoanhThu;
    cin.ignore();
}

void ChuyenXe::Xuat() {
    cout << "Ma so chuyen xe: " << MaSo << endl;
    cout << "Ho ten tai xe: " << HoTenTaiXe << endl;
    cout << "So xe: " << SoXe << endl;
    cout << "Doanh thu: " << DoanhThu << endl;
}

double ChuyenXe::getDoanhThu() {
    return DoanhThu;
}

class NoiThanh : public ChuyenXe {
private:
    double SoKm, SoTuyen;
public:
    void Nhap();
    void Xuat();
};

void NoiThanh::Nhap() {
    cout << "\n=== Nhap chuyen xe noi thanh ===" << endl;
    ChuyenXe::Nhap();
    cout << "Nhap so tuyen: ";
    cin >> SoTuyen;
    cout << "Nhap so km di duoc: ";
    cin >> SoKm;
    cin.ignore();
}

void NoiThanh::Xuat() {
    cout << "\n--- Thong tin chuyen xe noi thanh ---" << endl;
    ChuyenXe::Xuat();
    cout << "So tuyen: " << SoTuyen << endl;
    cout << "So km di duoc: " << SoKm << endl;
}

class NgoaiThanh : public ChuyenXe {
private:
    double SoNgay;
    string NoiDen;
public:
    void Nhap();
    void Xuat();
};

void NgoaiThanh::Nhap() {
    cout << "\n=== Nhap chuyen xe ngoai thanh ===" << endl;
    ChuyenXe::Nhap();
    cout << "Nhap noi den: ";
    getline(cin, NoiDen);
    cout << "Nhap so ngay di: ";
    cin >> SoNgay;
    cin.ignore();
}

void NgoaiThanh::Xuat() {
    cout << "\n--- Thong tin chuyen xe ngoai thanh ---" << endl;
    ChuyenXe::Xuat();
    cout << "Noi den: " << NoiDen << endl;
    cout << "So ngay di: " << SoNgay << endl;
}

class CongTy {
private:
    vector<NoiThanh> dsNoiThanh;
    vector<NgoaiThanh> dsNgoaiThanh;
public:
    void Nhap();
    void Xuat();
    double TongDoanhThuNoiThanh();
    double TongDoanhThuNgoaiThanh();
    double TongTatCa();
};

void CongTy::Nhap() {
    dsNoiThanh.resize(2);
    dsNgoaiThanh.resize(2);
    for (int i = 0; i < 2; i++) {
        cout << "\n==> Nhap chuyen xe noi thanh thu " << i + 1 << ":" << endl;
        dsNoiThanh[i].Nhap();
        cout << "\n==> Nhap chuyen xe ngoai thanh thu " << i + 1 << ":" << endl;
        dsNgoaiThanh[i].Nhap();
    }
}

void CongTy::Xuat() {
    cout << "\n=========== DANH SACH CHUYEN XE NOI THANH ===========" << endl;
    for (int i = 0; i < 2; i++) {
        dsNoiThanh[i].Xuat();
    }

    cout << "\n=========== DANH SACH CHUYEN XE NGOAI THANH ===========" << endl;
    for (int i = 0; i < 2; i++) {
        dsNgoaiThanh[i].Xuat();
    }
}

double CongTy::TongDoanhThuNoiThanh() {
    double tong = 0;
    for (auto xe : dsNoiThanh)
        tong += xe.getDoanhThu();
    return tong;
}

double CongTy::TongDoanhThuNgoaiThanh() {
    double tong = 0;
    for (auto xe : dsNgoaiThanh)
        tong += xe.getDoanhThu();
    return tong;
}

double CongTy::TongTatCa() {
    return TongDoanhThuNoiThanh() + TongDoanhThuNgoaiThanh();
}

int main() {
    CongTy congTy;
    congTy.Nhap();
    congTy.Xuat();
    cout << "\n=========== TONG DOANH THU ===========" << endl;
    cout << "Tong doanh thu noi thanh: " << congTy.TongDoanhThuNoiThanh() << endl;
    cout << "Tong doanh thu ngoai thanh: " << congTy.TongDoanhThuNgoaiThanh() << endl;
    cout << "Tong doanh thu tat ca: " << congTy.TongTatCa() << endl;
}