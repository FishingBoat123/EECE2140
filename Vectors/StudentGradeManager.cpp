#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printArray(dpouble arr[], int n)
{
    for(int i = 0; i < n; i++)
    cout << arr[i] << " ";
}

void sortArray(double arr[], int n)
{
    for(int i = 0; i < n-1; i++)
    {
        for(int j = 0; j < n-1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

void sortVector(vector<double> v)
{
    for(int i = 0; i < v.size; i++)
    {
        for(int j = 0; j < v.size; j++)
        {
            if(v[j] > v[j+1])
            {
                swap(v[j], v[j+1]);
            }
        }
    }
}

int main()
{
    const int n = 5;
    double arr[5] = {85.5, 92.0, 78.3, 95.1, 88.6};
    vector<double> v = {85.5, 92.0, 78.3, 95.1, 88.6};


    printArray(arr[], n)
    return 0;

}