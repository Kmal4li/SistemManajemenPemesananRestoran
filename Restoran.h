#ifndef RESTORAN_H_INCLUDED
#define RESTORAN_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;

typedef elemenPelanggan *adrPelanggan;
typedef elemenPesanan *adrPesanan;

struct Pelanggan {
    int nomorMeja;
    string nama;
};

struct Pesanan {
    string namaMenu;
    int jumlahPesanan;
};

struct elemenPesanan {
    Pesanan info;
    adrPesanan next;
};

struct elemenPelanggan {
    Pelanggan info;
    adrPelanggan next;
    adrPelanggan prev;
    adrPesanan nextFood;
};

struct ListPelanggan {
    adrPelanggan first;
    adrPelanggan last;
};

#endif // MLL_H_INCLUDED
