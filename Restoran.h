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
    adrPesanan firstPesanan;
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

void createList(ListPelanggan &L);

//Parent
adrPelanggan createParent(int nomorMeja, string nama);
void insertFirstParent(ListPelanggan &L, adrPelanggan p);
void insertLastParent(ListPelanggan &L, adrPelanggan p);
void insertAfterParent(ListPelanggan &L, adrPelanggan prec, adrPelanggan p);

void deleteFirstParent(ListPelanggan &L, adrPelanggan p);
void deleteLastParent(ListPelanggan &L, adrPelanggan p);
void deleteAfterParent(ListPelanggan &L, adrPelanggan prec, adrPelanggan p);

adrPelanggan findParent(ListPelanggan L, int nomorMeja);
void printParent(ListPelanggan L);

//Child
adrPesanan createChild(string namaMenu, int jumlahPesanan);
void insertFirstChild(adrPelanggan p, adrPesanan q);
void insertLastChild(adrPelanggan p, adrPesanan q);
void insertAfterChild(adrPesanan prec, adrPesanan q);

void deleteFirstChild(adrPelanggan p, adrPesanan q);
void deleteLastChild(adrPelanggan p, adrPesanan q);
void deleteAfterChild(adrPesanan prec, adrPesanan q);

adrPesanan findChild(adrPelanggan p, string namaMenu);
void printChild(adrPelanggan p);

//print all
void printAll(ListPelanggan L);


#endif // MLL_H_INCLUDED
