#include <iostream>
#include <vector>
#include <string>
using namespace std;

class SinhVien {
protected:
    string MaSo, HoTen, DiaChi;
    int TongSoTinChi;
    float DiemTrungBinh;
public:
    void Nhap();
    void Xuat();
    float GetDiemTB();
    int GetTinChi();
};

void SinhVien::Nhap() {
    cout << "Ma so: "; cin >> MaSo;
    cin.ignore();
    cout << "Ho ten: "; getline(cin, HoTen);
    cout << "Dia chi: "; getline(cin, DiaChi);
    cout << "Tong so tin chi: "; cin >> TongSoTinChi;
    cout << "Diem trung binh: "; cin >> DiemTrungBinh;
}

void SinhVien::Xuat() {
    cout << MaSo << " | " << HoTen << " | " << DiaChi << " | "
         << TongSoTinChi << " | " << DiemTrungBinh;
}

float SinhVien::GetDiemTB() {
    return DiemTrungBinh;
}

int SinhVien::GetTinChi() {
    return TongSoTinChi;
}

class SinhVienCaoDang : public SinhVien {
    float DiemTotNghiep;
public:
    void Nhap();
    void Xuat();
    bool DuDieuKienTotNghiep();
};

void SinhVienCaoDang::Nhap() {
    cout << "\nNhap sinh vien cao dang:\n";
    SinhVien::Nhap();
    cout << "Diem thi tot nghiep: "; cin >> DiemTotNghiep;
}

void SinhVienCaoDang::Xuat() {
    SinhVien::Xuat();
    cout << " | " << DiemTotNghiep << endl;
}

bool SinhVienCaoDang::DuDieuKienTotNghiep() {
    return (TongSoTinChi >= 110 && DiemTrungBinh >= 5 && DiemTotNghiep >= 5);
}

class SinhVienDaiHoc : public SinhVien {
    string TenLuanVan;
    float DiemLuanVan;
public:
    void Nhap();
    void Xuat();
    bool DuDieuKienTotNghiep();
};

void SinhVienDaiHoc::Nhap() {
    cout << "\nNhap sinh vien dai hoc:\n";
    SinhVien::Nhap();
    cin.ignore();
    cout << "Ten luan van: "; getline(cin, TenLuanVan);
    cout << "Diem luan van: "; cin >> DiemLuanVan;
}

void SinhVienDaiHoc::Xuat() {
    SinhVien::Xuat();
    cout << " | " << TenLuanVan << " | " << DiemLuanVan << endl;
}

bool SinhVienDaiHoc::DuDieuKienTotNghiep() {
    return (TongSoTinChi >= 145 && DiemTrungBinh >= 5 && DiemLuanVan >= 5);
}

int main() {
    int SoCD, SoDH;
    vector<SinhVienCaoDang> DanhSachCD;
    vector<SinhVienDaiHoc> DanhSachDH;

    cout << "Nhap so sinh vien cao dang: ";
    cin >> SoCD;
    for (int i = 0; i < SoCD; i++) {
        SinhVienCaoDang Sv;
        Sv.Nhap();
        DanhSachCD.push_back(Sv);
    }

    cout << "Nhap so sinh vien dai hoc: ";
    cin >> SoDH;
    for (int i = 0; i < SoDH; i++) {
        SinhVienDaiHoc Sv;
        Sv.Nhap();
        DanhSachDH.push_back(Sv);
    }

    cout << "\nDANH SACH SINH VIEN CAO DANG:\n";
    for (auto Sv : DanhSachCD)
        Sv.Xuat();

    cout << "\nDANH SACH SINH VIEN DAI HOC:\n";
    for (auto Sv : DanhSachDH)
        Sv.Xuat();

    cout << "\nSINH VIEN CAO DANG DU DIEU KIEN TOT NGHIEP:\n";
    for (auto Sv : DanhSachCD)
        if (Sv.DuDieuKienTotNghiep())
            Sv.Xuat();

    cout << "\nSINH VIEN DAI HOC DU DIEU KIEN TOT NGHIEP:\n";
    for (auto Sv : DanhSachDH)
        if (Sv.DuDieuKienTotNghiep())
            Sv.Xuat();

    cout << "\nSINH VIEN CAO DANG KHONG DU DIEU KIEN TOT NGHIEP:\n";
    for (auto Sv : DanhSachCD)
        if (!Sv.DuDieuKienTotNghiep())
            Sv.Xuat();

    cout << "\nSINH VIEN DAI HOC KHONG DU DIEU KIEN TOT NGHIEP:\n";
    for (auto Sv : DanhSachDH)
        if (!Sv.DuDieuKienTotNghiep())
            Sv.Xuat();

    if (!DanhSachDH.empty()) {
        SinhVienDaiHoc SvMax = DanhSachDH[0];
        for (auto Sv : DanhSachDH)
            if (Sv.GetDiemTB() > SvMax.GetDiemTB())
                SvMax = Sv;
        cout << "\nSINH VIEN DAI HOC CO DIEM TRUNG BINH CAO NHAT:\n";
        SvMax.Xuat();
    }
}