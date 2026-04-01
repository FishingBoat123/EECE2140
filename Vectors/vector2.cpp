#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<double> v;
    v.push_back(85.5);
    v.push_back(90.0);
    v.push_back(78.5);
    cout << "The scores are: ";
    for(size_t i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    sort(v.begin(), v.end());
    cout << "The sorted scores are: ";
    
}