#include <iostream>
using namespace std;

struct node { int data; node *prev, *next; };
node* head = NULL;

void insertEnd() {
    int x; cout<<"Enter value: "; cin>>x;
    node* t = new node{x, NULL, NULL};

    if (!head) head = t;
    else {
        node* p = head;
        while (p->next) p = p->next;
        p->next = t;
        t->prev = p;
    }
}

void deleteBeg() {
    if (!head) { cout<<"List is Empty\n"; return; }
    node* t = head;
    head = head->next;
    if (head) head->prev = NULL;
    delete t;
}

void display() {
    if (!head) { cout<<"List is Empty\n"; return; }
    for (node* p = head; p; p = p->next)
        cout<<p->data<<" <-> ";
    cout<<"NULL\n";
}

int main() {
    int ch;
    do {
        cout<<"\n1.Insert 2.DeleteBeg 3.Display 4.Exit\n";
        cin>>ch;
        if (ch==1) insertEnd();
        else if (ch==2) deleteBeg();
        else if (ch==3) display();
    } while (ch!=4);
}