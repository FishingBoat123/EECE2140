#include <iostream>
using namespace std;

class Die
{
    private:
    static int maxDieValue;
    int currentValue;

    public:
    void setValue (int currentValue) {this->currentValue = currentValue};
    int getValue() {return currentValue};

};
int Die::maxDieValue = 6;

int main()
{
    
}