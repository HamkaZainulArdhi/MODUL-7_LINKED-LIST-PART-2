#include <iostream>
using namespace std;

struct human {
    human *front;
    string nama;
    float ages;
    human *back;
};

human *student;
human *head;
human *tail;
human *helper;
human *hero;
human *visit;

int main() {
    // Initial setup
    student = new human;
    student->nama = "Toni";
    student->ages = 21;
    student->front = student;
    student->back = student;
    head = student;
    tail = student;

    student = new human;
    student->nama = "Runa";
    student->ages = 17;
    student->back = head;
    student->front = tail;
    head->front = student;
    tail->back = student;
    head = student;

    student = new human;
    student->nama = "Alex";
    student->ages = 19;
    student->front = tail;
    student->back = head;
    tail->back = student;
    head->front = student;
    tail = student;

    student = new human;
    student->nama = "Jack";
    student->ages = 25;
    student->back = head;
    student->front = tail;
    head->front = student;
    tail->back = student;
    head = student;

    helper = tail->front;

    student = new human;
    student->nama = "Kate";
    student->ages = 23;
    student->back = tail;
    student->front = helper;
    helper->back = student;
    tail->front = student;

    student = new human;
    student->nama = "Praz";
    student->ages = 27;
    student->front = tail;
    student->back = head;
    head->front = student;
    tail->back = student;
    tail = student;

    helper = head->back;

    student = new human;
    student->nama = "Zep";
    student->ages = 30;
    student->front = head;
    student->back = helper;
    helper->front = student;
    head->back = student;

    student = new human;
    student->nama = "Jasmine";
    student->ages = 15;
    student->back = head;
    student->front = tail;
    head->front = student;
    tail->back = student;
    head = student;

    student = new human;
    student->nama = "Ivan";
    student->ages = 20;
    student->front = tail;
    student->back = head;
    head->front = student;
    tail->back = student;
    tail = student;

    helper = tail->front;
    hero = helper->front;
    tail->front = hero;
    hero->back = tail;
    helper->back = NULL;
    helper->front = NULL;
    delete(helper);

    // Traverse the list and print
    cout << "List of humans:\n";
    visit = head;
    do {
        cout << "Name: " << visit->nama << ", Age: " << visit->ages << endl;
        visit = visit->back;
    } while (visit != head);

    // Find and print who is behind "Runa"
    visit = head;
    do {
        if (visit->nama == "Runa") {
            cout << "The person behind Runa is: " << visit->back->nama << endl;
            break;
        }
        visit = visit->back;
    } while (visit != head);

    return 0;
}
