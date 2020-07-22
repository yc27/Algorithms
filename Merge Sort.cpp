/***********************************
* Time Complexity
    * Worst complexity: O(n*log(n))
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

void merge(int arr[], int l, int r, int m) {
    int n1 = m - l + 1;
    int n2 = r - m;
    
    int L[n1], R[n2];
    
    for(int i = 0; i < n1; ++i)
        L[i] = arr[l+i];
    
    for(int i = 0; i < n2; ++i)
        R[i] = arr[m + i + 1];
        
    int i = 0, j = 0, k = l;
    
    while(i < n1 && j < n2) {
        if(L[i] < R[j]) {
            arr[k++] = L[i];
            ++i;
        }
        
        else {
            arr[k++] = R[j];
            ++j;
        }
    }
    
    while(i < n1)
        arr[k++] = L[i++];
        
    while(j < n2)
        arr[k++] = R[j++];
}

void mergeSort(int arr[], int l, int r) {
    if(l >= r)
        return;
        
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m+1, r);
    
    merge(arr, l, r, m);
}

int main() {
    int n, arr[100];
    
    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> arr[i];
        
    mergeSort(arr, 0, n-1);
    
    printArray(arr, 0, n);
    
    return 0;
}
