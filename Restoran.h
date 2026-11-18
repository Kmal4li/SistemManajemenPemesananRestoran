#ifndef RESTORAN_H_INCLUDED
#define RESTORAN_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;

typedef Elm_Pelanggan* Adr_Pelanggan;
typedef Elm_Pesanan* Adr_Pesanan;

struct Infotype_Pelanggan {
    int idPelanggan;
    string nama;
};

struct Infotype_Pesanan {
    string namaMenu;
    int jumlah;
};

struct List_Pesanan {
    Adr_Pesanan first;
};

struct Elm_Pelanggan {
    Infotype_Pelanggan info;
    Adr_Pelanggan next;
    List_Pesanan pesanan;
};

struct Elm_Pesanan {
    Infotype_Pesanan info;
    Adr_Pesanan next;
};

struct MLL {
    Adr_Pelanggan first;
};

#endif // RESTORAN_H_INCLUDED
