#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v = {10, 20, 30, 40, 50}; //vectors are better because they are in dynamic memory which means you can add and remove.
    for(int i= 0; i《 v.size(); i++)
    {
        cout << v[i] << " ";
    }

    const int n = 5;
    double arr[n] = {1.1, 2.2, 3.3, 4.4, 5.5};
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0
}