/***********************************
* Time Complexity
    * Worst complexity: O(n^2)
    * Average complexity: O(n^2)
    * Best complexity: O(n)

* Space complexity: O(1)
**********************************/

#include<bits/stdc++.h>
using namespace std;

void printArray(int arr[], int st, int en) {
    for(int i = st; i < en; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

void insertionSort(int arr[], int st, int en) {
    for(int i = st + 1; i < en; ++i) {
        int j = i - 1;
        int key = arr[i];
        
        while(j >= st && arr[j] > key) {
            arr[j+1] = arr[j];
            --j;
        }
        arr[j+1] = key;
    }
}

int main() {
    int n, arr[100];
    
    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> arr[i];
        
    insertionSort(arr, 0, n);
    
    printArray(arr, 0, n);
    
    return 0;
}
