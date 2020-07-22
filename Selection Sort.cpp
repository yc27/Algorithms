/***********************************
* Time Complexity
    * Worst complexity: O(n^2)
    * Average complexity: O(n^2)
    * Best complexity: O(n^2)

* Space complexity: O(1)
**********************************/

#include<bits/stdc++.h>
using namespace std;

void printArray(int arr[], int st, int en) {
    for(int i = st; i < en; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

void selectionSort(int arr[], int st, int en) {
    for(int i = st; i < en - 1; ++i) {
        int pos = i;
        
        for(int j = i+1; j < en; ++j) {
            if(arr[j] < arr[pos])
                pos = j;
        }
        
        swap(arr[i], arr[pos]);
        printArray(arr, 0, en);
    }
}

int main() {
    int n, arr[100];
    
    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> arr[i];
        
    selectionSort(arr, 0, n);
    
    printArray(arr, 0, n);
    
    return 0;
}
