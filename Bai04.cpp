#include <iostream>
#include <vector>
#include <string>
using namespace std;

class GiaoDich {
protected:
    string MaGD;
    string NgayGD;
    double DonGia;
    double DienTich;
public:
    virtual void Nhap();
    virtual void Xuat();
    virtual double ThanhTien() = 0;
    string GetNgayGD();
    virtual ~GiaoDich() {}
};

void GiaoDich::Nhap() {
    cout << "Ma giao dich: ";
    getline(cin, MaGD);
    cout << "Ngay giao dich: ";
    getline(cin, NgayGD);
    cout << "Don gia: ";
    cin >> DonGia;
    cout << "Dien tich: ";
    cin >> DienTich;
    cin.ignore();
}

void GiaoDich::Xuat() {
    cout << "MaGD: " << MaGD << ", NgayGD: " << NgayGD << ", DonGia: " << DonGia << ", DienTich: " << DienTich;
}

string GiaoDich::GetNgayGD() {
    return NgayGD;
}

class GiaoDichDat : public GiaoDich {
private:
    char LoaiDat;
public:
    void Nhap();
    void Xuat();
    double ThanhTien();
};

void GiaoDichDat::Nhap() {
    GiaoDich::Nhap();
    cout << "Loai dat (A/B/C): ";
    cin >> LoaiDat;
    cin.ignore();
}

void GiaoDichDat::Xuat() {
    GiaoDich::Xuat();
    cout << ", LoaiDat: " << LoaiDat << ", ThanhTien: " << ThanhTien() << endl;
}

double GiaoDichDat::ThanhTien() {
    if (LoaiDat == 'A' || LoaiDat == 'a') return DienTich * DonGia * 1.5;
    return DienTich * DonGia;
}

class GiaoDichNhaPho : public GiaoDich {
private:
    string LoaiNha;
    string DiaChi;
public:
    void Nhap();
    void Xuat();
    double ThanhTien();
};

void GiaoDichNhaPho::Nhap() {
    GiaoDich::Nhap();
    cout << "Loai nha (cao cap/thuong): ";
    getline(cin, LoaiNha);
    cout << "Dia chi: ";
    getline(cin, DiaChi);
}

void GiaoDichNhaPho::Xuat() {
    GiaoDich::Xuat();
    cout << ", LoaiNha: " << LoaiNha << ", DiaChi: " << DiaChi << ", ThanhTien: " << ThanhTien() << endl;
}

double GiaoDichNhaPho::ThanhTien() {
    if (LoaiNha == "thuong") {
        return DienTich * DonGia * 0.9;
    }
    return DienTich * DonGia;
}

class GiaoDichCanHo : public GiaoDich {
private:
    string MaCan;
    int ViTriTang;
public:
    void Nhap();
    void Xuat();
    double ThanhTien();
};

void GiaoDichCanHo::Nhap() {
    GiaoDich::Nhap();
    cout << "Ma can: ";
    getline(cin, MaCan);
    cout << "Vi tri tang: ";
    cin >> ViTriTang;
    cin.ignore();
}

void GiaoDichCanHo::Xuat() {
    GiaoDich::Xuat();
    cout << ", MaCan: " << MaCan << ", Tang: " << ViTriTang << ", ThanhTien: " << ThanhTien() << endl;
}

double GiaoDichCanHo::ThanhTien() {
    if (ViTriTang == 1) {
        return DienTich * DonGia * 2;
    }
    if (ViTriTang >= 15) {
        return DienTich * DonGia * 1.2;
    }
    return DienTich * DonGia;
}

int main() {
    vector<GiaoDichDat> dsDat;
    vector<GiaoDichNhaPho> dsNha;
    vector<GiaoDichCanHo> dsCanHo;

    int luaChon;
    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Nhap danh sach giao dich Dat\n";
        cout << "2. Nhap danh sach giao dich Nha pho\n";
        cout << "3. Nhap danh sach giao dich Can ho\n";
        cout << "4. Xuat danh sach cac giao dich\n";
        cout << "5. Tinh trung binh thanh tien giao dich Can ho\n";
        cout << "6. Giao dich Nha pho co thanh tien cao nhat\n";
        cout << "7. Xuat giao dich trong thang 12 nam 2024\n";
        cout << "0. Thoat\n";
        cout << "Chon: ";
        cin >> luaChon;
        cin.ignore();

        if (luaChon == 1) {
            int n;
            cout << "Nhap so giao dich dat: ";
            cin >> n;
            cin.ignore();
            for (int i = 0; i < n; i++) {
                GiaoDichDat gd;
                gd.Nhap();
                dsDat.push_back(gd);
            }
        } else if (luaChon == 2) {
            int n;
            cout << "Nhap so giao dich nha pho: ";
            cin >> n;
            cin.ignore();
            for (int i = 0; i < n; i++) {
                GiaoDichNhaPho gd;
                gd.Nhap();
                dsNha.push_back(gd);
            }
        } else if (luaChon == 3) {
            int n;
            cout << "Nhap so giao dich can ho: ";
            cin >> n;
            cin.ignore();
            for (int i = 0; i < n; i++) {
                GiaoDichCanHo gd;
                gd.Nhap();
                dsCanHo.push_back(gd);
            }
        } else if (luaChon == 4) {
            cout << "\n--- Giao dich dat ---\n";
            for (size_t i = 0; i < dsDat.size(); i++) dsDat[i].Xuat();
            cout << "\n--- Giao dich nha pho ---\n";
            for (size_t i = 0; i < dsNha.size(); i++) dsNha[i].Xuat();
            cout << "\n--- Giao dich can ho ---\n";
            for (size_t i = 0; i < dsCanHo.size(); i++) dsCanHo[i].Xuat();
        } else if (luaChon == 5) {
            double tong = 0;
            for (size_t i = 0; i < dsCanHo.size(); i++) {
                tong += dsCanHo[i].ThanhTien();
            }
            if (dsCanHo.size() > 0) {
                cout << "Trung binh thanh tien can ho: " << tong / dsCanHo.size() << endl;
            } else {
                cout << "Khong co giao dich can ho nao\n";
            }
        } else if (luaChon == 6) {
            if (dsNha.size() == 0) {
                cout << "Khong co giao dich nha pho nao\n";
            } else {
                double max = dsNha[0].ThanhTien();
                for (size_t i = 1; i < dsNha.size(); i++) {
                    if (dsNha[i].ThanhTien() > max) {
                        max = dsNha[i].ThanhTien();
                    }
                }
                cout << "Giao dich nha pho co thanh tien cao nhat:\n";
                for (size_t i = 0; i < dsNha.size(); i++) {
                    if (dsNha[i].ThanhTien() == max) {
                        dsNha[i].Xuat();
                    }
                }
            }
        } else if (luaChon == 7) {
            cout << "Cac giao dich trong thang 12 nam 2024:\n";
            for (size_t i = 0; i < dsDat.size(); i++) {
                if (dsDat[i].GetNgayGD().find("12/2024") != string::npos) {
                    dsDat[i].Xuat();
                }
            }
            for (size_t i = 0; i < dsNha.size(); i++) {
                if (dsNha[i].GetNgayGD().find("12/2024") != string::npos) {
                    dsNha[i].Xuat();
                }
            }
            for (size_t i = 0; i < dsCanHo.size(); i++) {
                if (dsCanHo[i].GetNgayGD().find("12/2024") != string::npos) {
                    dsCanHo[i].Xuat();
                }
            }
        }
    } while (luaChon != 0);
}