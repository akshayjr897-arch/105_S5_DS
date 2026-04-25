#include <iostream>
using namespace std;

#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

// PUSH (Insert)
void push(int value)
{
    if (rear == MAX - 1)
    {
        cout << "Queue Overflow\n";
        return;
    }

    if (front == -1)
        front = 0;

    rear++;
    queue[rear] = value;

    cout << "Inserted: " << value << endl;
}

// POP (Delete)
void pop()
{
    if (front == -1 || front > rear)
    {
        cout << "Queue Underflow\n";
        return;
    }

    cout << "Deleted: " << queue[front] << endl;
    front++;
}

// DISPLAY
void display()
{
    if (front == -1 || front > rear)
    {
        cout << "Queue is Empty\n";
        return;
    }

    cout << "Queue elements: ";
    for (int i = front; i <= rear; i++)
    {
        cout << queue[i] << " ";
    }
    cout << endl;
}

// MAIN FUNCTION
int main()
{
    int choice, value;

    do
    {
        cout << "\n--- Queue Menu ---\n";
        cout << "1. Push\n2. Pop\n3. Display\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                push(value);
                break;

            case 2:
                pop();
                break;

            case 3:
                display();
                break;

            case 4:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice\n";
        }

    } while (choice != 4);

    return 0;
}