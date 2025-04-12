#include <iostream>
#include <vector>
using namespace std;

// Merge two sorted halves into one sorted array
void merge(vector<int>& arr, int left, int mid, int right) {
    vector<int> temp;

    int i = left;     // Starting index for left half
    int j = mid + 1;  // Starting index for right half

    while(i <= mid && j <= right) {
        if(arr[i] <= arr[j]) {
            temp.push_back(arr[i]);
            i++;
        } else {
            temp.push_back(arr[j]);
            j++;
        }
    }

    // Copy any remaining elements from left half
    while(i <= mid) {
        temp.push_back(arr[i]);
        i++;
    }

    // Copy any remaining elements from right half
    while(j <= right) {
        temp.push_back(arr[j]);
        j++;
    }

    // Copy sorted elements back to original array
    for(int k = 0; k < temp.size(); k++) {
        arr[left + k] = temp[k];
    }
}

// Recursive Merge Sort function
void mergeSort(vector<int>& arr, int left, int right) {
    if(left >= right) return;

    int mid = left + (right - left) / 2;

    mergeSort(arr, left, mid);         // Sort left half
    mergeSort(arr, mid + 1, right);    // Sort right half
    merge(arr, left, mid, right);      // Merge both halves
}

int main() {
    vector<int> arr = {5, 3, 8, 4, 2, 7, 1, 10};

    mergeSort(arr, 0, arr.size() - 1);

    cout << "Sorted array: ";
    for(int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}