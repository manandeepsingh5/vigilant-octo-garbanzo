#include <iostream>
using namespace std;

int main()
{

    int arr[] = {6, 5, 3, 7, 2, 1};
    int n = sizeof(arr) / sizeof(int);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}