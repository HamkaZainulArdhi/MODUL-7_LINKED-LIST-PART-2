#include <iostream>
using namespace std;

struct dlinkedlist {
    dlinkedlist* prev;
    string data;
    dlinkedlist* next;
};

dlinkedlist* head;
dlinkedlist* tail;
dlinkedlist* vertex;

void inisialisasi() {
    head = NULL;
    tail = NULL;
}

bool dLinkKosong() {
    if (head == NULL && tail == NULL) {
        return true;
    } else {
        return false;
    }
}

void tambahDepan(string dataUser) {
    if (dLinkKosong() == true) {
        vertex = new dlinkedlist;
        vertex->data = dataUser;
        vertex->prev = NULL;
        vertex->next = NULL;
        head = vertex;
        tail = vertex;
    } else {
        vertex = new dlinkedlist;
        vertex->data = dataUser;
        vertex->prev = NULL;
        vertex->next = head;
        head->prev = vertex;
        head = vertex;
    }
}

void tambahBelakang(string dataUser) {
    if (dLinkKosong() == true) {
        vertex = new dlinkedlist;
        vertex->data = dataUser;
        vertex->prev = NULL;
        vertex->next = NULL;
        head = vertex;
        tail = vertex;
    } else {
        vertex = new dlinkedlist;
        vertex->data = dataUser;
        vertex->prev = tail;
        vertex->next = NULL;
        tail->next = vertex;
        tail = vertex;
    }
}

void hapusDepan() {
    if (dLinkKosong() == true) {
        cout << "Kosong...!!!" << endl;
    } else {
        dlinkedlist* helper;
        helper = head;
        if (head == tail) {
            head = NULL;
            tail = NULL;
            delete helper;
        } else {
            head = head->next;
            head->prev = NULL;
            helper->next = NULL;
            delete helper;
        }
    }
}

void hapusBelakang() {
    if (dLinkKosong() == true) {
        cout << "Kosong...!!!" << endl;
    } else {
        if (head == tail) {
            dlinkedlist* helper;
            helper = head;
            head = NULL;
            tail = NULL;
            delete helper;
        } else {
            dlinkedlist* helper;
            helper = tail;
            tail = tail->prev;
            tail->next = NULL;
            helper->prev = NULL;
            delete helper;
        }
    }
}

void tampilData() {
    if (dLinkKosong() == true) {
        cout << "Kosong...!!!" << endl;
    } else {
        dlinkedlist* helper;
        helper = head;
        while (helper != NULL) {
            cout << helper->data << " ";
            helper = helper->next;
        }
    }
}

int main() {
    int pilih;
    string data_user;
    bool lanjut = true;
    char keluar;
    do {
        cout << endl;
        cout << "MENU" <<endl;
        cout << "1. tambah_belakang" <<endl;
        cout << "2. tambah_depan" <<endl;
        cout << "3. hapus_belakang" <<endl;
        cout << "4. hapus_depan" <<endl;
        cout << "5. tampilkan list" <<endl;
        cout << "6. keluar" <<endl;
        cout << "pilih : ";
        cin >> pilih ;
        cout <<endl;

        switch (pilih) {

            case 1:
            cout << "tambah_belakang : " ; 
            cin >> data_user;
            tambahBelakang(data_user);
            break;

            case 2:
            cout << "tambah_depan : " ; 
            cin >> data_user;
            tambahDepan(data_user);
            break;

            case 3:
            hapusBelakang();
            cout << "data belakang telah terhapus" << endl;
            break;

            case 4:
            hapusDepan();
            cout << "data depan telah terhapus" << endl;
            break;
            
            case 5:
            cout << "daftar list" <<endl;
            tampilData();
            break;
            
            case 6:
            cout << "apakah anda ingin benar benar keluar ? (y/n) " ; 
            cin >> keluar;

            if (keluar == 'y') {
                cout << "terima kasih" << endl;
                lanjut = false;
            } else {
                lanjut = true;
            }
            break;

            default:
            cout << "Pilihan tidak valid. Silakan pilih antara 1 hingga 6." << endl;
            break;

        } 
    } while (lanjut);

    return 0;
}
