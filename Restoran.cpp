#include <iostream>
#include "Restoran.h"

using namespace std;

void createList(ListPelanggan &L) {
    L.first = nullptr;
    L.last = nullptr;
}

adrPelanggan createParent(int nomorMeja, string nama) {
    adrPelanggan p = new elemenPelanggan;
    p->info.nomorMeja = nomorMeja;
    p->info.nama = nama;
    p->next = nullptr;
    p->prev = nullptr;
    p->nextFood = nullptr;
    return p;
}

void insertFirstParent(ListPelanggan &L, adrPelanggan p) {
    if(L.first == nullptr) {
        L.first = p;
        L.last = p;
    } else {
        p->next = L.first;
        L.first->prev = p;
        L.first = p;
    }
}

void insertLastParent(ListPelanggan &L, adrPelanggan p) {
    if(L.first == nullptr) {
        L.first = p;
        L.last = p;
    } else {
        p->prev = L.last;
        L.last->next = p;
        L.last = p;
    }
}

void insertAfterParent(ListPelanggan &L, adrPelanggan prec, adrPelanggan p) {
    if(L.first == nullptr) {
        L.first = p;
        L.last = p;
    } else {
        p->next = prec->next;
        p->prev = prec;
        prec->next->prev = p;
        prec->next = p;
    }
}

void deleteFirstParent(ListPelanggan &L, adrPelanggan p) {
    if(L.first == nullptr) {
        p = nullptr;
    } else if(L.first->info == L.last->info) {
        p = L.first;
        L.first = nullptr;
        L.last = nullptr;
    } else {
        p = L.first;
        L.first = L.first->next;
        L.first->prev = nullptr;
        p->next = nullptr;
    }
}

void deleteLastParent(ListPelanggan &L, adrPelanggan p) {
    if(L.first == nullptr) {
        p = nullptr;
    } else if(L.first->info == L.last->info) {
        p = L.first;
        L.first = nullptr;
        L.last = nullptr;
    } else {
        p = L.last;
        L.last = L.last->prev;
        L.last->next = nullptr;
        p->prev = nullptr;
    }
}

void deleteAfterParent(ListPelanggan &L, adrPelanggan prec, adrPelanggan p) {
    if(L.first == nullptr) {
        p = nullptr;
    } else if(L.first->info == L.last->info) {
        p = L.first;
        L.first = nullptr;
        L.last = nullptr;
    } else {
        p = prec->next;
        prec->next = p->next;
        p->next->prev = prec;
        p->prev = nullptr;
        p->next = nullptr;
    }
}

adrPelanggan findParent(ListPelanggan L, int nomorMeja) {
    adrPelanggan P = L.first;

    while (P != NULL && P->info.nomorMeja != nomorMeja) {
        P = P->next;
    }

    return P;
}

void printParent(ListPelanggan L) {
    adrPelanggan P = L.first;

    if (P == NULL) {
        cout << "List pelanggan kosong." << endl;
        return;
    }

    int no = 1;
    while (P != NULL) {
        cout << no << ". Meja " << P->info.nomorMeja
             << " Atas nama:  " << P->info.nama << endl;
        P = P->next;
        no++;
    }
}



