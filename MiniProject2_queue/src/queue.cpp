#include "queue.h"
#include <iostream>
using namespace std;

Queue::Queue() : frontIndex(0), rearIndex(0), count(0) {}

bool Queue::isEmpty() const {return count == 0;}
bool Queue::isFull() const {return count == cap;}
int Queue::size() const {return count;}

//put in queue
bool Queue::enqueue (int item) 
{
    if (isFull())
        return false;
    arr[rearIndex] = item;
    rearIndex = (rearIndex + 1) % cap;
    count ++;
    return true;
}

//remove from queue
bool Queue::dequeue(int &removed)
{
    if (isEmpty()) 
        return false;
    arr[frontIndex] = removed;
    frontIndex = (frontIndex + 1) % cap;
    count --;
    return true;
}

//peek
bool Queue::front(int &value) const 
{
    if (isEmpty()) 
        return false;
    value = arr[frontIndex];
    return true;
}

//print
void Queue::print() const 
{
    cout << "The current queue is: ";
    for (int i = 0; i < count; i++) 
    {
        int index = (frontIndex + i) % cap;
        cout << arr[index] << ", ";
    }
    cout << endl << endl << endl;
}
