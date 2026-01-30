#include <iostream>
using namespace std;

int main()
{
    int values[6] = {3, 5, 1, 4, 2, 7};
    int sum = 0;

    for (int i = 0; i < 6; i++)
    {
        sum = sum + values[i];
    }

    cout << sum << endl;

    return 0;
}