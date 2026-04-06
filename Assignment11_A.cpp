#include <iostream>
#include <string>
using namespace std;

struct ListNode {
    int id;
    string name;
    ListNode* next;
};

class NodeList {
private:
    ListNode* head;
    int count;

    void clear()
    {
        ListNode* curr = head;
        while (curr) {
            ListNode* next = curr->next;
            delete curr;
            curr = next;
        }
        head  = nullptr;
        count = 0;
    }

    void copyFrom(const NodeList& src) {
        ListNode*  from = src.head;
        ListNode** tail = &head;
        while (from) {
            *tail = new ListNode{from->id, from->name, nullptr};
            tail  = &(*tail)->next;
            from  = from->next;
            ++count;
        }
    }

public:
    NodeList() : head(nullptr), count(0) {}

    void addNode(int id, string name) {
        ListNode* n = new ListNode{id, name, head};
        head = n;
        count++;
    }

    void removeNode(int id) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr && curr->id != id) {
            prev = curr;
            curr = curr->next;
        }
        if (!curr) return;
        if (prev) prev->next = curr->next;
        else head = curr->next;
        delete curr;
        count--;
    }

    void display() const {
        ListNode* curr = head;
        while (curr) {
            cout << "[" << curr->id << ": "
                 << curr->name << "] -> ";
            curr = curr->next;
        }
        cout << "null" << endl;
    }
    //Destructor
    ~NodeList() 
    {
        // clear();
    }

    //Copy constructor
    NodeList(const NodeList& other) : head(nullptr), count(0) 
    {
        copyFrom(other);
    }

    //operator
    NodeList& operator=(const NodeList& other) 
    {
        if (this != &other) 
        {
            clear();
            copyFrom(other);
        }
        return *this;
    }

};

int main() {
    NodeList n1;
    n1.addNode(1, "A");
    n1.addNode(2, "B");
    n1.addNode(3, "C");
    cout << "n1: "; n1.display();

    NodeList n2(n1);
    cout << "n2: "; n2.display();

    NodeList n3;
    n3 = n1;
    cout << "n3: "; n3.display();

    n1.removeNode(2);
    cout << "\nAfter removing 2 from n1:\n";
    cout << "n1: "; n1.display();
    cout << "n2: "; n2.display();
    cout << "n3: "; n3.display();
}