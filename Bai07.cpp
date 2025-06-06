#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

class GiaSuc {
protected:
    int SoLuong;
    int TongSoCon;
    int TongSua;
public:
    GiaSuc();
    void NhapSoLuong();
    int GetSoLuong();
    int GetTongSoCon();
    int GetTongSua();
};

GiaSuc::GiaSuc() {
    SoLuong = 0;
    TongSoCon = 0;
    TongSua = 0;
}

void GiaSuc::NhapSoLuong() {
    cin >> SoLuong;
}

int GiaSuc::GetSoLuong() {
    return SoLuong;
}

int GiaSuc::GetTongSoCon() {
    return TongSoCon;
}

int GiaSuc::GetTongSua() {
    return TongSua;
}

class Bo : public GiaSuc {
public:
    void TiengKeu();
    void SinhCon();
    void ChoSua();
};

void Bo::TiengKeu() {
    for (int i = 0; i < SoLuong; i++)
        cout << "Bo keu: Um boooo!\n";
}

void Bo::SinhCon() {
    for (int i = 0; i < SoLuong; i++)
        TongSoCon += rand() % 3 + 1; 
}

void Bo::ChoSua() {
    for (int i = 0; i < SoLuong; i++)
        TongSua += rand() % 21; 
}

class Cuu : public GiaSuc {
public:
    void TiengKeu();
    void SinhCon();
    void ChoSua();
};

void Cuu::TiengKeu() {
    for (int i = 0; i < SoLuong; i++)
        cout << "Cuu keu: Be beee!\n";
}

void Cuu::SinhCon() {
    for (int i = 0; i < SoLuong; i++)
        TongSoCon += rand() % 3 + 1;
}

void Cuu::ChoSua() {
    for (int i = 0; i < SoLuong; i++)
        TongSua += rand() % 6;
}

class De : public GiaSuc {
public:
    void TiengKeu();
    void SinhCon();
    void ChoSua();
};

void De::TiengKeu() {
    for (int i = 0; i < SoLuong; i++)
        cout << "De keu: E eeeee!\n";
}

void De::SinhCon() {
    for (int i = 0; i < SoLuong; i++)
        TongSoCon += rand() % 3 + 1;
}

void De::ChoSua() {
    for (int i = 0; i < SoLuong; i++)
        TongSua += rand() % 11; 
}

int main() {
    srand(time(0));
    Bo DanBo;
    Cuu DanCuu;
    De DanDe;
    cout << "Nhap so luong bo: ";
    DanBo.NhapSoLuong();
    cout << "Nhap so luong cuu: ";
    DanCuu.NhapSoLuong();
    cout << "Nhap so luong de: ";
    DanDe.NhapSoLuong();
    cout << "\nTieng keu cua cac gia suc:\n";
    DanBo.TiengKeu();
    DanCuu.TiengKeu();
    DanDe.TiengKeu();
    DanBo.SinhCon();
    DanCuu.SinhCon();
    DanDe.SinhCon();
    DanBo.ChoSua();
    DanCuu.ChoSua();
    DanDe.ChoSua();
    cout << "\nThong ke sau khi gia suc sinh con va cho sua:\n";
    cout << "Bo: " << DanBo.GetSoLuong() << " con, sinh ra " << DanBo.GetTongSoCon()
         << " con, tong sua: " << DanBo.GetTongSua() << " lit\n";
    cout << "Cuu: " << DanCuu.GetSoLuong() << " con, sinh ra " << DanCuu.GetTongSoCon()
         << " con, tong sua: " << DanCuu.GetTongSua() << " lit\n";
    cout << "De: " << DanDe.GetSoLuong() << " con, sinh ra " << DanDe.GetTongSoCon()
         << " con, tong sua: " << DanDe.GetTongSua() << " lit\n";
}