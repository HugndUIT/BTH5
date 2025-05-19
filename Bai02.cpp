#include <vector>
#include <iostream>
using namespace std;

class Sach {
    protected:
        string MaSach, NgayNhap, NXB;
        double DonGia, SoLuong, ThanhTien;
    public:
        string GetNXB();
        double GetDonGia();
        double GetThanhTien();
        virtual void Nhap();
        virtual void Xuat();
};

string Sach::GetNXB() {
    return NXB;
}

double Sach::GetDonGia() {
    return DonGia;
}

double Sach::GetThanhTien() {
    return ThanhTien;
}

void Sach::Nhap() {
    cout << "Nhap ma sach: ";
    cin >> MaSach;
    cout << "Nhap ngay nhap: ";
    cin >> NgayNhap;
    cout << "Nhap don gia: ";
    cin >> DonGia;
    cout << "Nhap so luong: ";
    cin >> SoLuong;
    cout << "Nhap nha xuat ban: ";
    cin >> NXB;
}

void Sach::Xuat() {
    cout << "Ma sach: " << MaSach << endl;
    cout << "Ngay nhap: " << NgayNhap << endl;
    cout << "Don gia: " << DonGia << endl;
    cout << "So luong: " << SoLuong << endl;
    cout << "Nha xuat ban: " << NXB << endl;
    cout << "Thanh tien: " << ThanhTien << endl;
}

class SGK : public Sach {
    private:
        string TinhTrang;
    public:
        void Nhap();
        void Xuat();
};

void SGK::Nhap() {
    cout << "=== Nhap sach giao khoa ===\n";
    Sach::Nhap();
    cout << "Nhap tinh trang (Moi/Cu): ";
    cin >> TinhTrang;
    if (TinhTrang == "Moi") {
        ThanhTien = SoLuong * DonGia;
    } else {
        ThanhTien = SoLuong * DonGia * 0.5;
    }
}

void SGK::Xuat() {
    cout << "=== Thong tin sach giao khoa ===\n";
    Sach::Xuat();
    cout << "Tinh trang: " << TinhTrang << endl;
    cout << "------------------------\n";
}

class STK : public Sach {
    private:
        double Thue;
    public:
        void Nhap();
        void Xuat();
};

void STK::Nhap() {
    cout << "=== Nhap sach tham khao ===\n";
    Sach::Nhap();
    cout << "Nhap thue: ";
    cin >> Thue;
    ThanhTien = SoLuong * DonGia * Thue;
}

void STK::Xuat() {
    cout << "=== Thong tin sach tham khao ===\n";
    Sach::Xuat();
    cout << "Thue: " << Thue << endl;
    cout << "------------------------\n";
}

class ThuVien {
    private:
        vector<SGK> SachGiaoKhoa;
        vector<STK> SachThamKhao;
    public:
        void Nhap();
        void Xuat();
        double TongThanhTienSGK();
        double TongThanhTienSTK();
        double TrungBinhDonGiaSTK();
        void TimSachTheoNXB(string);
};

void ThuVien::Nhap() {
    SachGiaoKhoa.resize(3);
    SachThamKhao.resize(3);
    for (int i = 0; i < 3; i++) {
        SachGiaoKhoa[i].Nhap();
        SachThamKhao[i].Nhap();
    }
}

void ThuVien::Xuat() {
    for (int i = 0; i < 3; i++) {
        SachGiaoKhoa[i].Xuat();
        SachThamKhao[i].Xuat();
    }
}

double ThuVien::TongThanhTienSGK() {
    double TongThanhTien = 0;
    for (int i = 0; i < 3; i++) {
        TongThanhTien += SachGiaoKhoa[i].GetThanhTien();
    }
    return TongThanhTien;
}

double ThuVien::TongThanhTienSTK() {
    double TongThanhTien = 0;
    for (int i = 0; i < 3; i++) {
        TongThanhTien += SachThamKhao[i].GetThanhTien();
    }
    return TongThanhTien;
}

double ThuVien::TrungBinhDonGiaSTK() {
    double TongDonGia = 0;
    for (int i = 0; i < 3; i++) {
        TongDonGia += SachThamKhao[i].GetDonGia();
    }
    return TongDonGia / 3;
}

void ThuVien::TimSachTheoNXB(string NXB) {
    bool TimThay = false;
    for (int i = 0; i < 3; i++) {
        if (SachGiaoKhoa[i].GetNXB() == NXB) {
            SachGiaoKhoa[i].Xuat();
            TimThay = true;
        }
    }
    if (!TimThay) {
        cout << "Not Found!\n";
    }
}

int main() {
    ThuVien X;
    X.Nhap();
    cout << "\n===== DANH SACH SACH =====\n";
    X.Xuat();
    cout << "\n===== TONG THANH TIEN TUNG LOAI =====\n";
    cout << "Tong SGK: " << X.TongThanhTienSGK() << endl;
    cout << "Tong STK: " << X.TongThanhTienSTK() << endl;
    cout << "\nTrung Binh Don Gia STK: " << X.TrungBinhDonGiaSTK() << endl;
    cout << "\nNhap NXB can tim: ";
    string NXB;
    cin >> NXB;
    X.TimSachTheoNXB(NXB);
}