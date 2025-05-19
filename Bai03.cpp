#include <vector>
#include <climits>
#include <iostream>
using namespace std;

class GiaoDich {
protected:
    string MaGiaoDich, NgayGiaoDich;
    double DonGia, SoLuong;
public:
    virtual void Nhap();
    virtual void Xuat();
    virtual double ThanhTien();
    virtual ~GiaoDich();
};

void GiaoDich::Nhap() {
    cout << "Nhap MaGiaoDich NgayGiaoDich DonGia SoLuong: ";
    cin >> MaGiaoDich >> NgayGiaoDich >> DonGia >> SoLuong;
}

void GiaoDich::Xuat() {
    cout << MaGiaoDich << " " << NgayGiaoDich << " " << DonGia << " " << SoLuong << " ";
}

double GiaoDich::ThanhTien() {
    return 0;
}

GiaoDich::~GiaoDich() {}

class Vang : public GiaoDich {
private:
    string LoaiVang;
public:
    void Nhap();
    void Xuat();
    double ThanhTien();
};

void Vang::Nhap() {
    GiaoDich::Nhap();
    cout << "Nhap LoaiVang: ";
    cin >> LoaiVang;
}

void Vang::Xuat() {
    GiaoDich::Xuat();
    cout << LoaiVang << " => Thanh tien: " << ThanhTien() << endl;
}

double Vang::ThanhTien() {
    return SoLuong * DonGia;
}

class TienTe : public GiaoDich {
protected:
    double TiGia;
public:
    void Nhap();
    void Xuat();
    virtual double ThanhTien();
};

void TienTe::Nhap() {
    GiaoDich::Nhap();
    cout << "Nhap TiGia: ";
    cin >> TiGia;
}

void TienTe::Xuat() {
    GiaoDich::Xuat();
    cout << TiGia << " ";
}

double TienTe::ThanhTien() {
    return 0;
}

class VND : public TienTe {
public:
    double ThanhTien();
    void Xuat() {
        cout << "[VND] ";
        TienTe::Xuat();
        cout << "=> Thanh tien: " << ThanhTien() << endl;
    }
};

double VND::ThanhTien() {
    return SoLuong * DonGia;
}

class USD : public TienTe {
public:
    double ThanhTien();
    void Xuat() {
        cout << "[USD] ";
        TienTe::Xuat();
        cout << "=> Thanh tien: " << ThanhTien() << endl;
    }
};

double USD::ThanhTien() {
    return SoLuong * DonGia * TiGia;
}

class Euro : public TienTe {
public:
    double ThanhTien();
    void Xuat() {
        cout << "[EURO] ";
        TienTe::Xuat();
        cout << "=> Thanh tien: " << ThanhTien() << endl;
    }
};

double Euro::ThanhTien() {
    return SoLuong * DonGia * TiGia;
}

class CongTy {
private:
    vector<Vang> GiaoDichVang;
    vector<TienTe*> GiaoDichTienTe;
public:
    void Nhap();
    void Xuat();
    Vang DichVuVangCaoNhat();
    Euro NgoaiTeEuroThapNhat();
    void XuatGiaoDichTren1Ty();
    ~CongTy();
};

void CongTy::Nhap() {
    int SoLuongGDVang;
    cout << "Nhap so luong giao dich vang: ";
    cin >> SoLuongGDVang;
    for (int i = 0; i < SoLuongGDVang; i++) {
        cout << "Nhap giao dich vang thu " << i + 1 << ":\n";
        Vang Temp;
        Temp.Nhap();
        GiaoDichVang.push_back(Temp);
    }

    int SoLuongGDTienTe;
    cout << "Nhap so luong giao dich tien te: ";
    cin >> SoLuongGDTienTe;
    for (int i = 0; i < SoLuongGDTienTe; i++) {
        cout << "Nhap giao dich tien te thu " << i + 1 << " (1: VND, 2: USD, 3: Euro): ";
        int Loai;
        cin >> Loai;
        TienTe* Temp = nullptr;
        if (Loai == 1)
            Temp = new VND;
        else if (Loai == 2)
            Temp = new USD;
        else
            Temp = new Euro;
        Temp->Nhap();
        GiaoDichTienTe.push_back(Temp);
    }
}

void CongTy::Xuat() {
    cout << "\n--- Danh sach giao dich vang ---\n";
    for (size_t i = 0; i < GiaoDichVang.size(); i++) {
        GiaoDichVang[i].Xuat();
    }

    cout << "\n--- Danh sach giao dich tien te ---\n";
    for (size_t i = 0; i < GiaoDichTienTe.size(); i++) {
        GiaoDichTienTe[i]->Xuat();
    }
}

Vang CongTy::DichVuVangCaoNhat() {
    Vang Temp;
    double Max = -1;
    for (size_t i = 0; i < GiaoDichVang.size(); i++) {
        if (GiaoDichVang[i].ThanhTien() > Max) {
            Max = GiaoDichVang[i].ThanhTien();
            Temp = GiaoDichVang[i];
        }
    }
    return Temp;
}

Euro CongTy::NgoaiTeEuroThapNhat() {
    double Min = INT_MAX;
    Euro* Euros = nullptr;
    for (auto Temp : GiaoDichTienTe) {
        if (dynamic_cast<Euro*>(Temp)) {
            if (Temp->ThanhTien() < Min) {
                Min = Temp->ThanhTien();
                Euros = dynamic_cast<Euro*>(Temp);
            }
        }
    }
    if (Euros != nullptr)
        return *Euros;
    else
        return Euro(); 
}

void CongTy::XuatGiaoDichTren1Ty() {
    cout << "\n--- Cac giao dich co thanh tien tren 1 ty ---\n";
    for (size_t i = 0; i < GiaoDichVang.size(); i++) {
        if (GiaoDichVang[i].ThanhTien() > 1000000000) {
            GiaoDichVang[i].Xuat();
        }
    }
    for (size_t i = 0; i < GiaoDichTienTe.size(); i++) {
        if (GiaoDichTienTe[i]->ThanhTien() > 1000000000) {
            GiaoDichTienTe[i]->Xuat();
        }
    }
}

CongTy::~CongTy() {
    for (auto x : GiaoDichTienTe)
        delete x;
}

int main() {
    CongTy X;
    X.Nhap();
    X.Xuat();
    X.XuatGiaoDichTren1Ty();
    cout << "\n--- Giao dich vang co thanh tien cao nhat ---\n";
    Vang TempV = X.DichVuVangCaoNhat();
    TempV.Xuat();
    cout << "\n--- Giao dich Euro co thanh tien thap nhat ---\n";
    Euro TempE = X.NgoaiTeEuroThapNhat();
    TempE.Xuat();
}