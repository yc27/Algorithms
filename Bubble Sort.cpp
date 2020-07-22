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

void bubbleSort(int arr[], int st, int en) {
    for(int i = st; i < en - 1; ++i) {
        for(int j = st; j < en - i - 1; ++j) {
            if(arr[j] > arr[j+1])
                swap(arr[j], arr[j+1]);
        }
    }
}

int main() {
    int n, arr[100];
    
    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> arr[i];
        
    bubbleSort(arr, 0, n);
    
    printArray(arr, 0, n);
    
    return 0;
}
