#include <iostream>

using namespace std;

struct Node { // Node Single linkedlist Circular untuk wadah data lagu
    string lagu;
    Node* next;
};

struct SllcPlaylistLagu { // Penerapan Single Linkedlist Circular dengan struct untuk logika sistem playlist otomatis
    Node* Head = NULL, *Tail = NULL, *current = NULL;

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
            current = baru;
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
            current = baru;
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

        if(isEmpty() == 1) {
            cout << "Playlist masih kosong!" << endl;
        } else {
            bantu = Head;
            cout << "\n--- DAFTAR PLAYLIST ---" << endl;
            do {
                if(bantu == current) {
                    cout << "-> " << bantu->lagu << " (Sedang di putar)" << endl;
                } else {
                    cout << "   " << bantu->lagu << endl;
                }
                bantu = bantu->next;
            } while(bantu != Head);
            cout << "-------------------------" << endl;
        }
    }

    // Menghapus playlist awal
    void hapusawal() {
        Node* hapus;

        if(isEmpty() == 0) {
            hapus = Head;
            if(Head != Tail) {
                Head = Head->next;
                Tail->next = Head;
                if(current == hapus) current = Head;
                delete hapus;
            } else {
                hapus = Head = Tail = current;
                Head = NULL;
                Tail = NULL;
                current = NULL;
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

        if(isEmpty() == 0) {
            bantu = Head;
            do {
                hapus = bantu;
                bantu = bantu->next;
                delete hapus;
            } while(bantu != Head);
            Head = NULL;
            Tail = NULL;
            
            cout << "Playlist berhasil di hapus seluruhnya!" << endl;
        }
    }

    // PENGEMBANGAN: Fungsi untuk memutar lagu berikutnya (Next Track)
    void putarlaguberikutnya() {
        if(isEmpty() == 1) {
            cout << "Playlist masih kosong!" << endl;
        } else {
            current = current->next;
            cout << "\n⏭️ Beralih ke lagu berikutnya: " << current->lagu << endl;
        }
    }

    // PENGEMBANGAN: Fungsi untuk memutar lagu saat ini
    void putarlagu() {
        if(isEmpty() == 1) {
            cout << "Playlist masih kosong!" << endl;
        } else {
            cout << "\n▶️ Memutar lagu: " << current->lagu << endl;
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
    cout << "7. Hapus semua playlist" << endl;
    cout << "8. Keluar" << endl;
    cout << "Pilih: ";
}

int main() {

SllcPlaylistLagu sllc;

int pilihan;
string lagu;

while(true) {
screen();
cin >> pilihan;

switch(pilihan) {
    case 1: {
        sllc.putarlagu();
        break;
    }
    case 2: {
        cout << "Masukkan nama lagu: ";
        cin.clear();
        cin.ignore();
        getline(cin, lagu);
        sllc.insertlaguawal(lagu);
        break;
    }
    case 3: {
        cout << "Masukkan nama lagu: ";
        cin.clear();
        cin.ignore();
        getline(cin, lagu);
        sllc.insertlaguakhir(lagu);
        break;
    }
    case 4: {
        sllc.tampil();
        break;
    }
    case 5: {
        sllc.hapusawal();
        break;
    }
    case 6: {
        sllc.hapusakhir();
        break;
    }
    case 7: {
        sllc.clear();
        break;
    }
    case 8: {
        cout << "Terima kasih, semoga hari anda menyenangkan!" << endl;
        return 0;
    }
    default :
    cout << "Error: input anda tidak valid!" << endl;

}
}


    return 0;
}