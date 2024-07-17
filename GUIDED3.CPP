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
        head = vertex;
        tail = vertex;
        head->prev = tail;
        tail->next = head;
    } else {
        vertex = new dlinkedlist;
        vertex->data = dataUser;
        vertex->next = head;
        head->prev = vertex;
        head = vertex;
        head->prev = tail;
        tail->next = head;
    }
}

void tambahBelakang(string dataUser) {
    if (dLinkKosong() == true) {
        vertex = new dlinkedlist;
        vertex->data = dataUser;
        head = vertex;
        tail = vertex;
        head->prev = tail;
        tail->next = head;
    } else {
        vertex = new dlinkedlist;
        vertex->data = dataUser;
        vertex->prev = tail;
        tail->next = vertex;
        tail = vertex;
        tail->next = head;
        head->prev = tail;
    }
}

void hapusDepan() {
    if (dLinkKosong() == true) {
        cout << "Kosong...!!!" << endl;
    } else {
        dlinkedlist* helper;
        helper = head;
        if (head == tail) {
            tail->next = NULL;
            head->prev = NULL;
            head = NULL;
            tail = NULL;
            delete helper;
        } else {
            head = head->next;
            head->prev = tail;
            tail->next = head;
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
            head->prev = NULL;
            tail->next = NULL;
            head = NULL;
            tail = NULL;
            delete helper;
        } else {
            dlinkedlist* helper;
            helper = tail;
            tail = tail->prev;
            tail->next = head;
            head->prev = tail;
            helper->prev = NULL;
            helper->next = NULL;
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
        do {
            cout << helper->data << " ";
            helper = helper->next;
        } while (helper != head);
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

        if (pilih == 1) {
            cout << "tambahkan belakang :";
            cin >>data_user;
            tambahBelakang(data_user);
        } 
        if (pilih == 2) {
            cout << "tambahkan depan :";
            cin >>data_user;
            tambahDepan(data_user);
        }
        if (pilih == 3) {
            hapusBelakang();
            cout << "data belakang telah terhapus" << endl;
        }
        if (pilih == 4) {
            hapusDepan();
            cout << "data depan telah terhapus" << endl;
        }
        if (pilih == 5) {
            tampilData();
        }
        if (pilih == 6) {
            cout << " apakah anda ingin benar benar keluar ? (y/n)";
            cin >> keluar;

            if (keluar == 'y') {
                lanjut = false;
            } else {
                lanjut = true;
            }

        } if (pilih > 6) {
            cout << " pilihan tidak valid silahkan memilih 1 sampai 6" << endl;
        }
        
        
    } while (lanjut);
    
return 0;  
}
    

