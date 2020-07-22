/***********************************
* Time Complexity
    * Worst complexity: O(n^2)
    * Average complexity: O(n*log(n))
    * Best complexity: O(n*log(n))

* Space complexity: O(n)
**********************************/

#include<bits/stdc++.h>
using namespace std;

void printArray(int arr[], int st, int en) {
    for(int i = st; i < en; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

int partition(int arr[], int low, int high) {
    int m = low + (high - low) / 2;
    int pivot = arr[m]; // middle element as pivot
    
    while(low < high) {
        while(arr[low] < pivot)
            ++low;
            
        while(arr[high] > pivot)
            --high;
            
        if(low < high)
            swap(arr[low], arr[high]);
    }
    
    return low;
}

void quickSort(int arr[], int low, int high) {
    if(low >= high)
        return;
        
    int pivot = partition(arr, low, high);
    
    quickSort(arr, low, pivot - 1);
    quickSort(arr, pivot + 1, high);
}

/************************************************************
* optimization for reducing sapce complexity to O(log(n))
* using tail call elimination
************************************************************/
void quickSortOptimized(int arr[], int low, int high) {
    while(low < high) {
        int pivot = partition(arr, low, high);

        // If left part is smaller, then recur for left part and handle right part iteratively
        if(pivot - low < high - pivot) {
            quickSortOptimized(arr, low, pivot - 1);
            low = pivot + 1;
        }

        // Else recur for right part
        else {
            quickSortOptimized(arr, pivot + 1, high);
            high = pivot - 1;
        }
    }
}

int main() {
    int n, arr[100];
    
    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> arr[i];
        
    quickSort(arr, 0, n-1);
    
    printArray(arr, 0, n);
    
    return 0;
}
