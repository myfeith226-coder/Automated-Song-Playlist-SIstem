#include <iostream>

using namespace std;

struct Node {
    string lagu;
    Node* next;
};

struct SllcPlaylistLagu {
    Node* Head = NULL, *Tail = NULL;

    // Fungsi untuk mengetahui kosong tidaknya suatu playlist musik
    int isEmpty() { 
        if(Head == NULL) {
            return 1;
        } else {
            return 0;
        }
    }

    // Menambah playlist lagu di awal
    void insertlaguawal(string lagu) {
        Node* baru;
        baru = new Node;

        baru->lagu = lagu;
        baru->next = baru;

        if(isEmpty() == 1) {
            Head = baru;
            Tail = baru;
            Head->next = Head;
            Tail->next = Tail;
        } else {
            baru->next = Head;
            Head = baru;
            Tail->next = Head;
        }
        cout << lagu << " berhasil di tambahkan ke playlist awal!" << endl;
    }

    // Menambah playlist lagu di akhir
    void insertlaguakhir(string lagu) {
        Node* baru;
        baru = new Node;

        baru->lagu = lagu;
        baru->next = baru;

        if(isEmpty() == 1) {
            Head = baru;
            Tail = baru;
            Head->next = Head;
            Tail->next = Tail;
        } else {
            Tail->next = baru;
            Tail = baru;
            Tail->next = Head;
        }
        cout << lagu << " berhasil di tambahkan ke playlist akhir!" << endl;
    }

    // Menampilkan semua playlist lagu
    void tampil() {
        Node* bantu;

        if(isEmpty() == 0) {
            bantu = Head;
            do {
                cout << bantu->lagu << " ";
                bantu = bantu->next;
            } while(bantu != Tail->next);
            cout << endl;
        } else {
            cout << "Playlist masih kosong!" << endl;
        }
    }

    // Menghapus playlist awal
    void hapusawal() {
        Node* hapus, *bantu;

        if(isEmpty() == 0) {
            hapus = Head;
            if(Head != Tail) {
                bantu = Head;
                while(bantu->next != Head) {
                    bantu = bantu->next;
                }
                Head = Head->next;
                Tail->next = Head;
                delete hapus;
            } else {
                hapus = Head = Tail;
                Head = NULL;
                Tail = NULL;
                delete hapus;
            }
            cout << "Playlist awal berhasil di hapus!" << endl;
        } else {
            cout << "Playlist masih kosong!" << endl;
        }
    }

    // Menghapus playlist akhir
    void hapusakhir() {
        Node* hapus, *bantu;

        if(isEmpty() == 0) {
            if(Head != Tail) {
                bantu = Head;
                while(bantu->next != Tail) {
                    bantu = bantu->next;
                }
                hapus = Tail;
                Tail = bantu;
                Tail->next = Head;
                delete hapus;
            } else {
                hapus = Head = Tail;
                Head = NULL;
                Tail = NULL;
                delete hapus;
            }
            cout << "Playlist akhir berhasil di hapus!" << endl;
        } else {
            cout << "Playlist masih kosong!" << endl;
        }
    }

    // Menghapus semua playlist lagu
    void clear() {
        Node* hapus, *bantu;

        bantu = Head;

        do {
            hapus = bantu;
            bantu = bantu->next;
            delete hapus;
        } while(bantu != Tail->next);
        hapus = Head = Tail;
        Head = NULL;
        Tail = NULL;
        delete hapus;
        cout << "Playlist berhasil di hapus seluruhnya!" << endl;
    }

    // Fungsi untuk memutar lagu berikutnya
    void putarlaguberikutnya() {

    }

    // Fungsi untuk memutar lagu
    void putarlagu() {
        Node* putar;
        if(isEmpty() == 1) {
            cout << "Playlist masih kosong!" << endl;
        } else {
            putar = Head;
            cout << "Lagu yang di putar: " << putar->lagu << endl;
        }
    }
};

void screen() {
    cout << "---=== AUTOMATED SONG PLAYLIST SISTEM ---===" << endl;
    cout << "1. Putar lagu" << endl;
    cout << "2. Tambah playlist awal" << endl;
    cout << "3. Tambah playlist akhir" << endl;
    cout << "4. Tampilkan playlist" << endl;
    cout << "5. Hapus playlist awal" << endl;
    cout << "6. Hapus playlist akhir" << endl;
    cout << "7. Keluar" << endl;
    cout << "Pilih: ";
}

int main() {

SllcPlaylistLagu sllc;

int pilihan;

while(true) {
screen();
cin >> pilihan;

switch(pilihan) {
    case 1: {
        sllc.putarlagu();
        break;
    }
}
}


    return 0;
}