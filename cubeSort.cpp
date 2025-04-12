#include <iostream>
#include <algorithm>

const int CUBE_SIZE = 8;

// function to sort the cube
void cubeSort(int arr[], int n)
{
    // divide the array into cubes of size CUBE_SIZE
    for (int i = 0; i < n; i += CUBE_SIZE)
    {
        std::sort(arr + i, arr + std::min(i + CUBE_SIZE, n));
    }

    // merge the cubes
    int temp[n];
    for (int i = 0; i < n; i += CUBE_SIZE)
    {
        std::merge(arr + i, arr + std::min(i + CUBE_SIZE, n),
                   arr + std::min(i + CUBE_SIZE, n),
                   arr + std::min(i + 2 * CUBE_SIZE, n),
                   temp + i);
    }

    // copy the result from temp[] back to arr[]
    for (int i = 0; i < n; i++)
        arr[i] = temp[i];
}

// main function
int main()
{
    // input array
    int arr[] = {3, 6, 7, 1, 5, 2, 8, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    // call cubeSort
    cubeSort(arr, n);

    // print the sorted array
    for (int i = 0; i < n; i++)
        std::cout << arr[i] << " ";
    return 0;
}
