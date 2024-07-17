#include <iostream>
using namespace std;


struct Node {
    int data;
    Node* prev;
    Node* next;
};


Node* buatnode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}


void buat_linkedlist(Node** head, int value) {
    *head = buatnode(value);
    (*head)->next = (*head);
    (*head)->prev = (*head);
}


void tambkan_sisipdepan(Node** head, Node* newNode, Node* target) {
    newNode->next = target;
    newNode->prev = target->prev;
    if (target->prev != NULL) {
        target->prev->next = newNode;
    } else {
        newNode->next = *head;
    }
    target->prev = newNode;
    if (newNode->next == *head) {
        (*head)->prev = newNode;
    }
}


void tambakan_sisipbelakang(Node** head, Node* newNode, Node* target) {
    newNode->prev = target;
    newNode->next = target->next;
    if (target->next != NULL) {
        target->next->prev = newNode;
    } else {
        newNode->next = *head;
    }
    target->next = newNode;
    if (newNode->prev == *head) {
        (*head)->next = newNode;
    }
}


void tambahkan_tail(Node** head, Node* newNode) {
    if (*head == NULL) {
        *head = newNode;
        newNode->prev = newNode;
        newNode->next = newNode;
    } else {
        Node* last = (*head)->prev;
        newNode->prev = last;
        newNode->next = *head;
        last->next = newNode;
        (*head)->prev = newNode;
    }
}


void tampilkan_data(Node* head) {
    Node* current = head;
    do {
        cout << current->data << " ";
        current = current->next;
    } while (current != head);
    cout << endl;
}

int main() {
    Node* head = NULL;
    buat_linkedlist(&head, 1);
    tambkan_sisipdepan(&head, buatnode(0), head);
    tambakan_sisipbelakang(&head, buatnode(2), head);
    tambahkan_tail(&head, buatnode(3));
    tampilkan_data(head);
    return 0;
}