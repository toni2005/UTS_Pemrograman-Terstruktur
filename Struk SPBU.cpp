#include <iostream>
#include <string>

using namespace std;

struct DataBBM {
    string kode_BBM;
    string nama_BBM;
    int harga;
};

// Fungsi untuk menampilkan list harga BBM
void tampilkanListHarga(DataBBM bbm1, DataBBM bbm2) {
    cout << "List Harga BBM : " << endl;
    cout << "Kode BBM    Jenis BBM         Harga " << endl;
    cout << "---------------------------------------------------" << endl;
    cout << " " << bbm1.kode_BBM << "          " << bbm1.nama_BBM << "     Rp. " << bbm1.harga << ",00" << endl;
    cout << " " << bbm2.kode_BBM << "          " << bbm2.nama_BBM << "      Rp. " << bbm2.harga << ",00" << endl;
    cout << "---------------------------------------------------" << endl;
}

// Fungsi untuk memilih jenis BBM dan mengisi data BBM
DataBBM pilihBBM(string kode_BBM) {
    DataBBM bbm;
    if (kode_BBM == "1") {
        bbm = {"1", "Pertalite", 10000};
    } else if (kode_BBM == "2") {
        bbm = {"2", "Pertamax", 13900};
    } else {
        cout << "Maaf anda salah memasukkan kode BBM";
    }
    return bbm;
}

// Fungsi untuk mencetak struk BBM
void cetakStruk(string nama_penjaga, string jenis, string no_pompa, string no_selang, string plat, int total, int jml_uang, float uang, float liter, int harga, int kembali) {
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "                      -PERTAMINA-                     " << endl;
    cout << "                 -SPBU DS. SENGONBUGEL-               " << endl;
    cout << "  -Jl. Raya Jepara - Kudus, Sengonbugel, Kec. Mayong- " << endl;
    cout << "------------------------------------------------------" << endl;
    cout << "Nomor Pompa    : " << no_pompa << endl;
    cout << "Nomor Plat     : " << plat << endl;
    cout << "Jenis BBM      : " << jenis << endl;
    cout << "Volume(L)      : " << liter << endl;
    cout << "Harga/liter    : Rp. " << harga << ",00" << endl;
    cout << "Total          : Rp. " << total << ",00" << endl;
    cout << "------------------------------------------------------" << endl;
    cout << "Cash           : Rp. " << jml_uang << ",00" << endl;
    cout << "Kembali        : Rp. " << kembali << ",00" << endl;
    cout << "======================================================" << endl;
    cout << "Operator       : " << nama_penjaga << endl;
    cout << "        BBM subsidi untuk golongan TIDAK MAMPU        " << endl;
    cout << "           TERIMA KASIH DAN SELAMAT JALAN             ";
}

int main() {
    DataBBM pertalite = {"1", "Pertalite", 10000};
    DataBBM pertamax = {"2", "Pertamax", 13900};

    tampilkanListHarga(pertalite, pertamax);

    string nama_penjaga, jenis, kode_BBM, plat, no_pompa, no_selang;
    int jml_uang, kembali, total = 0;
    float liter, uang;

    cout << "===================================================" << endl;
    cout << "     Selamat Datang di SPBU DS. SENGONBUGEL         " << endl;
    cout << " Jl. Raya Jepara - Kudus, Sengonbugel, Kec. Mayong " << endl;
    cout << "===================================================" << endl;

    // Perulangan - memilih jenis BBM
    do {
        cout << "Kode BBM   : ";
        cin >> kode_BBM;
    } while (kode_BBM != "1" && kode_BBM != "2");

    DataBBM bbmPilihan = pilihBBM(kode_BBM);

    cout << "Jenis BBM  : " << bbmPilihan.nama_BBM << endl;
    cout << "Rp. " << bbmPilihan.harga << "/liter" << endl;

    nama_penjaga = (kode_BBM == "1") ? "Rudi" : "Putri";
    no_pompa = (kode_BBM == "1") ? "1" : "2";
    no_selang = (kode_BBM == "1") ? "1" : "2";

    cout << endl;
    cout << "Plat nomor : ";
    cin >> plat;
    cout << "Beli       : ";
    cin >> uang;
    cout << "Bayar      : ";
    cin >> jml_uang;

    total = total + uang;
    liter = uang / bbmPilihan.harga;
    kembali = jml_uang - uang;

    // Memanggil fungsi untuk mencetak struk
    cetakStruk(nama_penjaga, bbmPilihan.nama_BBM, no_pompa, no_selang, plat, total, jml_uang, uang, liter, bbmPilihan.harga, kembali);

    return 0;
}

