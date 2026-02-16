#ifndef QUEUE_H
#define QUEUE_H

class Queue
{
    private: 
        static const int cap = 5;
        int arr[cap];
        int frontIndex;
        int rearIndex;
        int count;

    public: 

        Queue();

        bool enqueue(int item); //true if item was put in, false if queue is full
        bool dequeue(int &removed); // true if item removed, false if queue is empty
        bool front(int &item) const; // true if queue not empty, false if queue is empty

        bool isEmpty() const;
        bool isFull() const;
        int size() const;

    void print() const;
};

#endif