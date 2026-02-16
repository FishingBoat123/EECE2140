README
Queueing System
=========================================================================
TO RUN THE PROGRAM, THE FOLLOWING IS NEEDED: queue.h, queue.cpp, main.cpp
=========================================================================
To compile the program, do g++ main.cpp src/queue.cpp -Iinclude -o run. Make sure queue.h is in include folder and queue.cpp is in src folder.
To run the program, do ./run after having compiled it.

The program as 5 options: insert into queue, nammed enqueue, which will insert a value of choice into the end of the queue; remove from queue, nammed dequeue, which will remove an inserted value at the start of the queue; peek, which will print the value at the start of the queue; size, which will print the number of elements in the queue, and print which will print the elements in the queue. 

The queue is capped at 5 elements. If a sixth value is attempted to be inserted, the program will not insert into queue. The program does this by first checking if isFull is true which would be true if count, variable used for number of elements in program, equals 5. if isFull is true, the program false which and prints queue is full. 

If one tries to remove a value from the program when queue is empty, the program will print queue is empty. It does this by first checking if the queue is empty, it does this in the same way it does for if it is full but by checking if count is equal to 0. If the queue is empty, the program outputs false and prints.

The program prints the first value in queue by first checking if queue is empty. If queue is not empty, the program passes the first value of the queue by using a pointer called front index that follows the first value of the queue even if the its index is not 0 in the array.

The program prints the size of the queue by printing variable count. this variable works as a counter and is updated each time a value is added or removed from queue.

The program prints the queue by usuing a for loop and printing the first value in the queue and then wrapping back to index 0 in the array when the index reaches beyond the cap.

An example of usage for this program is as follows:
===================
1) Enqueue
2) Dequeue
3) Peek
4) Size
5) Print
6) Exit
Choice: 1
Value: 56


===================
1) Enqueue
2) Dequeue
3) Peek
4) Size
5) Print
6) Exit
Choice: 1
Value: 20


===================
1) Enqueue
2) Dequeue
3) Peek
4) Size
5) Print
6) Exit
Choice: 5
The current queue is: 56, 20, 



===================
1) Enqueue
2) Dequeue
3) Peek
4) Size
5) Print
6) Exit
Choice: 2
Removed: 1
===================
1) Enqueue
2) Dequeue
3) Peek
4) Size
5) Print
6) Exit
Choice: 5
The current queue is: 20, 