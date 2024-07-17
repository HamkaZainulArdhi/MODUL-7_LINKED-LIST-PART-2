#include <iostream>

using namespace std;

struct node
{
    string nama;
    node *front;
    node *back;
};
    node *train;
    node *head;
    node *tail;
    node *helperAF;
    node *helperAM;

int main () {
     
     train = new node;
     train->nama = "afik";
     train->front = NULL;
     train->back = NULL;
     head = train;
     tail = train;

     train = new node;
     train->nama = "ani";
     train->back= head;
     train->front = NULL;
     head->front = train;
     head = train;

     train = new node;
     train->nama = "amelia";
     tail->back= train;
     train->front = tail;
     tail = train;
     train->back = NULL;

     train = new node;
     train->nama = "asbi";
     tail->front = train;
     head->back->back = train;
     train->back = tail;
     train->front = head->back;

     helperAF = head;
     while (helperAF->nama != "afiq" && helperAF != NULL)
     {
        helperAF = helperAF->back;
     }
     if (helperAF != NULL && helperAF !=tail){
    helperAM = helperAF->back;
    train = new node;
    train->nama = "asbi";
    helperAF->back = train;
    train->front =helperAF;
    train->back = helperAM;
    helperAM->front = train;
     }


return 0;

}