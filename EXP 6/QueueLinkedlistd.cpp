#include <iostream>
using namespace std;

// Node structure
struct node
{
    int data;
    node *next;
};

// Queue pointers
node *front = NULL;
node *rear = NULL;

// ENQUEUE (Push)
void enqueue()
{
    int value;
    cout << "Enter value: ";
    cin >> value;

    node *temp = new node;
    temp->data = value;
    temp->next = NULL;

    // If queue is empty
    if (rear == NULL)
    {
        front = rear = temp;
    }
    else
    {
        rear->next = temp;  // Insert at rear
        rear = temp;
    }

    cout << "Enqueued: " << value << endl;
}

// DEQUEUE (Pop)
void dequeue()
{
    if (front == NULL)
    {
        cout << "Queue Underflow\n";
        return;
    }

    node *temp = front;
    cout << "Dequeued: " << front->data << endl;

    front = front->next;

    // If queue becomes empty
    if (front == NULL)
        rear = NULL;

    delete temp;
}

// DISPLAY
void display()
{
    if (front == NULL)
    {
        cout << "Queue is Empty\n";
        return;
    }

    node *temp = front;
    cout << "Queue (Front -> Rear): ";

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// MAIN
int main()
{
    int choice;

    while (true)
    {
        cout << "\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: return 0;
            default: cout << "Invalid choice\n";
        }
    }

    return 0;
}