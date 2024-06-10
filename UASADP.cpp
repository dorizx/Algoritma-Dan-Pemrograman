#include <iostream>
#include <string>
using namespace std;

struct buku {
    int    no;
    string nama;
    string penerbit;
    string penulis;
    int    tahun_terbit;
};

buku data[100];
int totalbuku = 0, buku_ke = 1;

bool tidaktambah = false;
bool ulangcari   = false;
void mainmenu() {
    system("cls");
    cout << "\t\t\t\t\t\t\t=============================="     << endl;
    cout << "\t\t\t\t\t\t\t          BOOK CORNER         "     << endl;
    cout << "\t\t\t\t\t\t\t==============================\n\n" << endl;
    cout << "\tMENU UTAMA                    \n" << endl;
    cout << "\t1. Input Data Buku            \n" << endl;
    cout << "\t2. Cari Data Buku             \n" << endl;
    cout << "\t3. Ubah Data Buku             \n" << endl;
    cout << "\t4. Tampilkan Daftar Buku      \n" << endl;
    cout << "\t5. Hapus Data Buku            \n" << endl;
    cout << "\t6. Keluar                     \n" << endl;
    cout << "\t==============================\n" << endl;
}

int menuinput() {
    int inpbuku = 0;
    system("cls");
    cout << "\t=================================="   << endl;
    cout << "\t          INPUT DATA BUKU         "   << endl;
    cout << "\t==================================\n" << endl;
    do {
        cout << "\tMasukkan Jumlah Buku yang Akan Diinput : ";
        cin  >> inpbuku;
        if (inpbuku > 5) {
            cout << "\n\tMaksimal input adalah 5 data buku per-inputannya." << endl << endl;
        } else if(inpbuku == 0) {
            cout << "\n\tTidak ada data yang diinput. " << endl << endl;
            tidaktambah = true;
        } else if (inpbuku < 0) {
            cout << "\n\tJumlah buku yang akan diinput harus menggunakan angka positif. " << endl << endl;
        }
    } while(inpbuku < 0 || inpbuku > 5);
    return inpbuku;
}

void inputdata() {
    totalbuku += menuinput();
    for (int i = buku_ke;i <= totalbuku;i++) {
        system("cls");
        cout << "\n\t\tBuku No. " << i << endl << endl;
        cout << "\tNama Buku    : ";
        getline(cin >> ws, data[i].nama);
        cout << "\tPenulis      : ";
        getline(cin >> ws, data[i].penulis);
        cout << "\tPenerbit     : ";
        getline(cin >> ws, data[i].penerbit);
        cout << "\tTahun Terbit : ";
        cin  >> data[i].tahun_terbit;
        buku_ke++;
    }
    if(tidaktambah == false) {
        cout << "\n\tData buku Anda berhasil diinput." << endl << endl;
    }
    tidaktambah = false;
    system("pause");
}

void searchlist() {
    system("cls");
    cout << "\t=================================="   << endl;
    cout << "\t    CARI DATA BUKU BERDASARKAN    "   << endl;
    cout << "\t==================================\n" << endl;
    cout << "\t1. Nomor Buku\n"                      << endl;
    cout << "\t2. Nama Buku\n"                       << endl;
    cout << "\t3. Penulis Buku\n"                    << endl;
    cout << "\t4. Penerbit Buku\n"                   << endl;
    cout << "\t5. Tahun Terbit\n"                    << endl;
    cout << "\t6. Kembali ke Menu Utama\n"           << endl;
    cout << "\t==================================\n" << endl;
}

void carilagi() {
	char confirm;
	bool salahinput;

	do {
        salahinput = false;
        cout << "\tApakah masih ada buku yang ingin Anda cari? (Y/N) : ";
        cin  >> confirm;
        if (confirm == 'Y' || confirm == 'y') {
            ulangcari = true;
        } else if (confirm == 'n' || confirm == 'N') {
            ulangcari = false;
        } else {
            cout << "\n\tInputan yang Anda masukkan salah." << endl << endl;
            salahinput = true;
        }
	} while(salahinput);
}

void caridata() {
    int kodecari, i, noada, tahunada, caribukusama = 0, caritahun;
    string caribuku, nama_ada, penulis_ada, penerbit_ada;
    bool ditemukan = false;
	ulangcari = true;
    while(ulangcari) {
        searchlist();
        do {
            cout << "\tSilakan Pilih Kode [1-6] : ";
            cin  >> kodecari;

            switch (kodecari) {
            case 1:
                system("cls");
                cout << "\tCari Data Berdasarkan Nomor Buku" << endl << endl;
                cout << "\tMasukkan Nomor Buku : ";
                cin  >> i;
                cout << endl;
                if (i <= 0 || i > totalbuku) {
                    cout << "\tData tidak ada." << endl << endl;
                    carilagi();
                    break;
                }
                cout << "\n\tBuku No. "       << i                    << endl;
                cout << "\n\t-- Data Buku --" << endl;
                cout << "\tNama Buku    : "   << data[i].nama         << endl;
                cout << "\tPenulis      : "   << data[i].penulis      << endl;
                cout << "\tPenerbit     : "   << data[i].penerbit     << endl;
                cout << "\tTahun Terbit : "   << data[i].tahun_terbit << endl;
                cout << endl;
                carilagi();
                break;
            case 2:
                system("cls");
                cout << "\tCari Data Berdasarkan Nama Buku" << endl << endl;
                cout << "\tMasukkan Nama Buku : ";
                getline(cin >> ws, caribuku);
                cout << endl;
                for (i = 1;i <= totalbuku;i++) {
                    if (caribuku == data[i].nama) {
                        ditemukan    = true;
                        noada        = i;
                        nama_ada     = data[i].nama;
                        penulis_ada  = data[i].penulis;
                        penerbit_ada = data[i].penerbit;
                        tahunada     = data[i].tahun_terbit;
                    }
                }
                if (ditemukan) {
                    cout << "\n\tBuku No. "       << noada        << endl;
                    cout << "\n\t-- Data Buku --" << endl;
                    cout << "\tNama Buku    : "   << nama_ada     << endl;
                    cout << "\tPenulis      : "   << penulis_ada  << endl;
                    cout << "\tPenerbit     : "   << penerbit_ada << endl;
                    cout << "\tTahun Terbit : "   << tahunada     << endl;
                    ditemukan = false;
                } else {
                    cout << "\tData tidak ada." << endl;
                }
                cout << endl;
                carilagi();
                break;
            case 3:
                system("cls");
                cout << "\tCari Data Berdasarkan Penulis Buku" << endl << endl;
                cout << "\tMasukkan Nama Penulis Buku : ";
                getline(cin >> ws, caribuku);
                cout << endl;
                for (i = 1;i <= totalbuku;i++) {
                    if (caribuku == data[i].penulis) {
                        caribukusama += 1;
                    }
                }
                if (caribukusama >= 1) {
                    cout << "\tTerdapat " << caribukusama << " buku dari hasil pencarian penulis buku \"" << caribuku << "\"." << endl;
                    caribukusama = 0;
                    for (i = 1;i <= totalbuku;i++) {
                        if (caribuku == data[i].penulis) {
                            cout << endl;
                            cout << "\n\tBuku No. "       << i                    << endl;
                            cout << "\n\t-- Data Buku --" << endl;
                            cout << "\tNama Buku    : "   << data[i].nama         << endl;
                            cout << "\tPenulis      : "   << data[i].penulis      << endl;
                            cout << "\tPenerbit     : "   << data[i].penerbit     << endl;
                            cout << "\tTahun Terbit : "   << data[i].tahun_terbit << endl;
                        }
                    }
                } else {
                    cout << "\tBuku dengan penulis \"" << caribuku << "\" tidak ditemukan." << endl;
                }
                cout << endl;
                carilagi();
                break;
            case 4:
                system("cls");
                cout << "\tCari Data Berdasarkan Penerbit Buku" << endl << endl;
                cout << "\tMasukkan Nama Penerbit Buku : ";
                getline(cin >> ws, caribuku);
                cout << endl;
                for (i = 1;i <= totalbuku; i++) {
                    if (caribuku == data[i].penerbit) {
                        caribukusama += 1;
                    }
                }
                if (caribukusama >= 1) {
                    cout << "\tTerdapat " << caribukusama << " buku dari hasil pencarian penerbit buku \"" << caribuku << "\"." << endl;
                    caribukusama = 0;
                    for (i = 1;i <= totalbuku;i++) {
                        if (caribuku == data[i].penerbit) {
                            cout << endl;
                            cout << "\n\tBuku No. "       << i                    << endl;
                            cout << "\n\t-- Data Buku --" << endl;
                            cout << "\tNama Buku    : "   << data[i].nama         << endl;
                            cout << "\tPenulis      : "   << data[i].penulis      << endl;
                            cout << "\tPenerbit     : "   << data[i].penerbit     << endl;
                            cout << "\tTahun Terbit : "   << data[i].tahun_terbit << endl;
                        }
                    }
                } else {
                    cout << "\tBuku dengan penerbit \"" << caribuku << "\" tidak ditemukan." << endl;
                }
                cout << endl;
                carilagi();
                break;
            case 5:
                system("cls");
                cout << "\tCari Data Berdasarkan Tahun Terbit Buku" << endl << endl;
                cout << "\tMasukkan Tahun Terbit Buku : ";
                cin  >> caritahun;
                cout << endl;
                for (i = 1;i <= totalbuku;i++) {
                    if (caritahun == data[i].tahun_terbit) {
                        caribukusama += 1;
                    }
                }
                if (caribukusama >= 1) {
                    cout << "\tTerdapat " << caribukusama << " buku dari hasil pencarian tahun terbit buku \"" << caritahun << "\"." << endl;
                    caribukusama = 0;
                    for (i = 1;i <= totalbuku;i++) {
                        if (caritahun == data[i].tahun_terbit) {
                            cout << endl;
                            cout << "\n\tBuku No. "       << i                    << endl;
                            cout << "\n\t-- Data Buku --" << endl;
                            cout << "\tNama Buku    : "   << data[i].nama         << endl;
                            cout << "\tPenulis      : "   << data[i].penulis      << endl;
                            cout << "\tPenerbit     : "   << data[i].penerbit     << endl;
                            cout << "\tTahun Terbit : "   << data[i].tahun_terbit << endl;
                        }
                    }
                } else {
                    cout << "\tBuku dengan tahun terbit \"" << caritahun << "\" tidak ditemukan." << endl;
                }
                cout << endl;
                carilagi();
                break;
            case 6:
                ulangcari = false;
                break;
            default:
                cout << "\n\tKode yang Anda pilih tidak ada di dalam menu." << endl << endl;
                break;
            }
        } while (kodecari < 1 || kodecari > 6);
    }
}

void daftarbuku() {
    system("cls");
    cout << "\t=================================="   << endl;
    cout << "\t            DAFTAR BUKU           "   << endl;
    cout << "\t==================================\n" << endl;
    if (totalbuku == 0) {
        cout << "\tBelum ada buku yang diinput." << endl << endl;
    } else if (totalbuku >= 1) {
        cout << "\tSaat ini ada " << totalbuku << " buku yang berhasil diinput." << endl << endl;
    }
    for (int i = 1;i <= totalbuku;i++) {
        cout << "\tBuku No. "       << i                    << endl;
        cout << "\t-----------------------------"           << endl;
        cout << "\tNama Buku    : " << data[i].nama         << endl;
        cout << "\tPenulis      : " << data[i].penulis      << endl;
        cout << "\tPenerbit     : " << data[i].penerbit     << endl;
        cout << "\tTahun Terbit : " << data[i].tahun_terbit << endl;
        cout << "\t-----------------------------"           << endl;
        cout << endl;
    }
}

void ubahdata() {
    int i, temptahunterbit;
    string tempnama, temppenulis, temppenerbit;
    char confirm;
    bool salahinput, editulang, ubahulang;

    daftarbuku();
    if (totalbuku != 0) {
        do {
            ubahulang = false;
            if (totalbuku > 1) {
                cout << "\n\tMasukkan Nomor Buku yang Ingin Anda Ubah (1-" << totalbuku << ") : ";
                cin  >> i;
            } else {
                cout << "\n\tMasukkan Nomor Buku yang Ingin Anda Ubah : ";
                cin  >> i;
            }
            if (i > 0 && i <= totalbuku) {
                do {
                    editulang = false;
                    system("cls");
                    cout << "\t-- Data Buku --"              << endl;
                    cout << "\tNama Buku    : "              << data[i].nama         << endl;
                    cout << "\tPenulis      : "              << data[i].penulis      << endl;
                    cout << "\tPenerbit     : "              << data[i].penerbit     << endl;
                    cout << "\tTahun Terbit : "              << data[i].tahun_terbit << endl << endl;
                    cout << "\tMasukkan Data Buku yang Baru" << endl;
                    cout << "\tNama Buku    : ";
                    getline(cin >> ws, tempnama);
                    cout << "\tPenulis      : ";
                    getline(cin >> ws, temppenulis);
                    cout << "\tPenerbit     : ";
                    getline(cin >> ws, temppenerbit);
                    cout << "\tTahun Terbit : ";
                    cin  >> temptahunterbit;

                    system("cls");
                    cout << "\tKonfirmasi Kembali Perubahan Data Buku Anda" << endl << endl;
                    cout << "\t-- Data Buku --"     << endl;
                    cout << "\tNama Buku    : "     << data[i].nama         << endl;
                    cout << "\tPenulis      : "     << data[i].penulis      << endl;
                    cout << "\tPenerbit     : "     << data[i].penerbit     << endl;
                    cout << "\tTahun Terbit : "     << data[i].tahun_terbit << endl << endl;
                    cout << "\tAkan Diubah Menjadi" << endl;
                    cout << "\tNama Buku    : "     << tempnama             << endl;
                    cout << "\tPenulis      : "     << temppenulis          << endl;
                    cout << "\tPenerbit     : "     << temppenerbit         << endl;
                    cout << "\tTahun Terbit : "     << temptahunterbit      << endl << endl;
                    do {
                        salahinput = false;
                        cout << "\tApakah data yang Anda masukkan sudah benar? (Y/N) : ";
                        cin  >> confirm;
                        if (confirm == 'Y' || confirm == 'y') {
                            data[i].nama         = tempnama;
                            data[i].penulis      = temppenulis;
                            data[i].penerbit     = temppenerbit;
                            data[i].tahun_terbit = temptahunterbit;
                            cout << "\n\tPerubahan disimpan.\n" << endl;
                            system("Pause");
                        } else if (confirm == 'N' || confirm == 'n') {
                            do {
                                salahinput = false;
                                cout << "\n\tApakah Anda ingin memasukkan ulang? (Y/N) : ";
                                cin  >> confirm;
                                if (confirm == 'Y' || confirm == 'y') {
                                    editulang = true;
                                } else if (confirm == 'N' || confirm == 'n') {
                                    cout << "\n\tPerubahan telah dibatalkan.\n"     << endl ;
                                    system("pause");
                                } else {
                                    cout << "\n\tInputan yang Anda masukkan salah." << endl ;
                                    salahinput = true;
                                }
                            } while(salahinput);
                        } else {
                            cout << "\n\tInputan yang Anda masukkan salah.\n"     << endl ;
                            salahinput = true;
                        }
                    } while(salahinput);
                } while(editulang);
            } else {
                do {
                    salahinput = false;
                    cout << "\n\tNomor buku yang Anda masukkan tidak ada. Batalkan ubah data? (Y/N) : ";
                    cin  >> confirm;
                    if (confirm == 'N' || confirm == 'n') {
                        ubahulang = true;
                    } else if (confirm == 'Y' || confirm == 'y') {
                    } else {
                        cout << "\n\tInputan yang Anda masukkan salah." << endl ;
                        salahinput = true;
                    }
                } while(salahinput);
            }
        } while(ubahulang);
    } else {
        system("pause");
    }
}

void hapus() {
    int x;
    char confirm;
    bool inputsalah, hapusulang;

    daftarbuku();
    if (totalbuku != 0) {
        do {
            hapusulang = false;
            if (totalbuku > 1) {
                cout << "\n\tMasukkan Nomor Buku yang Ingin Anda Hapus (1-" << totalbuku << ") : ";
                cin  >> x;
            } else {
                cout << "\n\tMasukkan Nomor Buku yang Ingin Anda Hapus : ";
                cin  >> x;
            }
            if (x > 0 && x <= totalbuku) {
                system("cls");
                cout << "\t-- Data Buku --" << endl;
                cout << "\tNama Buku    : " << data[x].nama         << endl;
                cout << "\tPenulis      : " << data[x].penulis      << endl;
                cout << "\tPenerbit     : " << data[x].penerbit     << endl;
                cout << "\tTahun Terbit : " << data[x].tahun_terbit << endl << endl;
                do {
                    inputsalah = false;
                    cout << "\tApakah Anda yakin ingin menghapus buku no. " << x << "? (Y/N) : ";
                    cin  >> confirm;
                    if (confirm == 'Y' || confirm == 'y') {
                        if (totalbuku > 1) {
                            for (int i = x; i < totalbuku; ++i) {
                                data[i] = data[i + 1];
                            }
                        }
                        totalbuku -= 1;
                        buku_ke -= 1;
                        cout << "\n\tPerubahan disimpan.\n"               << endl;
                        system("pause");
                    } else if (confirm == 'N' || confirm == 'n') {
                        cout << "\n\tPerubahan telah dibatalkan.\n"       << endl;
                        system("pause");
                    } else {
                        cout << "\n\tInputan yang Anda masukkan salah.\n" << endl;
                        inputsalah = true;
                    }
                } while(inputsalah);
            } else {
                do {
                    inputsalah = false;
                    cout << "\n\tNomor buku yang Anda masukkan tidak ada. Batalkan hapus data? (Y/N) : ";
                    cin  >> confirm;
                    if (confirm == 'N' || confirm == 'n') {
                        hapusulang = true;
                    } else if (confirm == 'Y' || confirm == 'y') {
                    } else {
                        cout << "\n\tInputan yang Anda masukkan salah." << endl;
                        inputsalah = true;
                    }
                } while(inputsalah);
            }
        } while(hapusulang);
    } else {
        system("pause");
    }
}

int main() {
    bool keluar = false;
    int kodemenu;

    while (keluar == false) {
        mainmenu();
        do {
            cout << "\tMasukkan Angka (1-6) : ";
            cin  >> kodemenu;

            switch (kodemenu) {
            case 1:
                inputdata();
                break;
            case 2:
                caridata();
                break;
            case 3:
                ubahdata();
                break;
            case 4:
                daftarbuku();
                system("pause");
                break;
            case 5:
                hapus();
                break;
            case 6:
                keluar = true;
                break;
            default:
                cout << "\n\tAngka yang Anda masukkan tidak berada di dalam menu." << endl << endl;
                break;
            }
        } while(kodemenu < 1 || kodemenu > 6);
    }

    system("cls");
    cout << "\n\n\n\n\n\n\n\n\n\n\n";
    cout << "\t\t\t\t\t\t\t\t=============\n" << endl;
    cout << "\t\t\t\t\t\t\t\tTERIMA KASIH!\n" << endl;
    cout << "\t\t\t\t\t\t\t\t=============\n" << endl;
    cin.get();

    cin.get();
    return 0;
}
