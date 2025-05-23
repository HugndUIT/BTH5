#include <iostream>
#include <vector>
#include <string>
using namespace std;

class NhanVien {
protected:
    string HoTen, NgaySinh;
    double Luong;
public:
    virtual void Nhap();
    virtual void Xuat();
    virtual double TinhLuong() = 0;
};

void NhanVien::Nhap() {
    cout << "Ho ten: ";
    getline(cin, HoTen);
    cout << "Ngay sinh: ";
    getline(cin, NgaySinh);
}

void NhanVien::Xuat() {
    cout << "Ho ten: " << HoTen << endl;
    cout << "Ngay sinh: " << NgaySinh << endl;
    cout << "Luong: " << Luong << endl;
}

class VanPhong : public NhanVien {
private:
    double SoNgayLam;
public:
    void Nhap();
    void Xuat();
    double TinhLuong();
};

void VanPhong::Nhap() {
    NhanVien::Nhap();
    cout << "So ngay lam viec: ";
    cin >> SoNgayLam;
    cin.ignore();
    Luong = TinhLuong();
}

void VanPhong::Xuat() {
    NhanVien::Xuat();
    cout << "Loai nhan vien: Van phong" << endl;
    cout << "So ngay lam: " << SoNgayLam << endl;
}

double VanPhong::TinhLuong() {
    return SoNgayLam * 100000;
}

class SanXuat : public NhanVien {
private:
    double LuongCoBan, SoSanPham;
public:
    void Nhap();
    void Xuat();
    double TinhLuong();
};

void SanXuat::Nhap() {
    NhanVien::Nhap();
    cout << "Luong co ban: ";
    cin >> LuongCoBan;
    cout << "So san pham: ";
    cin >> SoSanPham;
    cin.ignore();
    Luong = TinhLuong();
}

void SanXuat::Xuat() {
    NhanVien::Xuat();
    cout << "Loai nhan vien: San xuat" << endl;
    cout << "Luong co ban: " << LuongCoBan << endl;
    cout << "So san pham: " << SoSanPham << endl;
}

double SanXuat::TinhLuong() {
    return LuongCoBan + SoSanPham * 5000;
}

class CongTy {
private:
    vector<VanPhong> NVVanPhong;
    vector<SanXuat> NVSanXuat;
public:
    void Nhap();
    void TinhLuong();
    void Xuat();
    double TongLuong();
};

void CongTy::Nhap() {
    int n;
    cout << "Nhap so NV van phong: ";
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        VanPhong nv;
        cout << "\nNhap NV van phong thu " << i + 1 << endl;
        nv.Nhap();
        NVVanPhong.push_back(nv);
    }

    cout << "Nhap so NV san xuat: ";
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        SanXuat nv;
        cout << "\nNhap NV san xuat thu " << i + 1 << endl;
        nv.Nhap();
        NVSanXuat.push_back(nv);
    }
}

void CongTy::TinhLuong() {
    for (size_t i = 0; i < NVVanPhong.size(); i++)
        NVVanPhong[i].TinhLuong();
    for (size_t i = 0; i < NVSanXuat.size(); i++)
        NVSanXuat[i].TinhLuong();
}

void CongTy::Xuat() {
    cout << "\nDanh sach NV van phong:\n";
    for (size_t i = 0; i < NVVanPhong.size(); i++) {
        cout << "\nNV " << i + 1 << endl;
        NVVanPhong[i].Xuat();
    }
    cout << "\nDanh sach NV san xuat:\n";
    for (size_t i = 0; i < NVSanXuat.size(); i++) {
        cout << "\nNV " << i + 1 << endl;
        NVSanXuat[i].Xuat();
    }
}

double CongTy::TongLuong() {
    double tong = 0;
    for (size_t i = 0; i < NVVanPhong.size(); i++)
        tong += NVVanPhong[i].TinhLuong();
    for (size_t i = 0; i < NVSanXuat.size(); i++)
        tong += NVSanXuat[i].TinhLuong();
    return tong;
}

int main() {
    CongTy ct;
    ct.Nhap();
    ct.Xuat();
    cout << "\nTong luong cong ty phai tra: " << ct.TongLuong() << endl;
    return 0;
}