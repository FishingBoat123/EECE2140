#include <iostream>
#include "queue.h"
using namespace std;

int main() 
{
    Queue q;

    while (true) 
    {
        cout << "===================" << endl;
        cout << "1) Enqueue" << endl;
        cout << "2) Dequeue" << endl;
        cout << "3) Peek" << endl;
        cout << "4) Size"<< endl;
        cout << "5) Print" << endl;
        cout << "6) Exit" << endl << "Choice: ";
        int choice;
        cin >> choice;

        switch (choice)
        {
            case 1: // insert into queue
            {
                int i; 
                cout << "Value: "; 
                cin >> i;
                if (!q.enqueue(i)) 
                    cout << "Queue is full" << endl;
                    cout << endl << endl;
                break;
            }
            case 2: // remove first from queue
            {
                int removed;
                if (!q.dequeue(removed))
                    cout << "Queue is empty!\n";
                else
                    cout << "Removed: " << removed << endl;
                break;
            }
            case 3: // peek
            {
                int x;
                if (!q.front(x))
                    cout << "Queue is empty" << endl;
                else
                    cout << "Front: " << x << endl;
                break;
            }
            case 4: // size of queue
            {
                int n = q.size();
                cout << "Size of queue is: " << n << endl << endl;
                break;
            }
            case 5: // print queue
            {
                q.print();
                cout << endl;
                break;
            }
            case 6: // exit
            {
                return 0;
            }
            default:
            {
                cout << "Invalid input" << endl;
                continue;
            }
        }
    }
}



