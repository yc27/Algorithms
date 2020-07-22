/***********************************
* Time Complexity
    * Worst complexity: O(n+k)
    * Average complexity: O(n+k)
    * Best complexity: O(n+k)

* Space complexity: O(n+k)
**********************************/

#include<bits/stdc++.h>
using namespace std;

void printArray(int arr[], int st, int en) {
    for(int i = st; i < en; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

int findMax(int arr[], int st, int en) {
    int mx = INT_MIN;
    for(int i = st; i < en; ++i)
        mx = max(mx, arr[i]);
        
    return mx;
}

int findMin(int arr[], int st, int en) {
    int mn = INT_MAX;
    for(int i = st; i < en; ++i)
        mn = min(mn, arr[i]);
        
    return mn;
}

void countingSort(int arr[], int st, int en) {
    int mx = findMax(arr, st, en);
    int mn = findMin(arr, st, en);
    int range = mx - mn + 1;
    int n = en - st;
    
    int count[range], output[n];
    
    memset(count, 0, sizeof count);
    
    for(int i = st; i < en; ++i)
        ++count[ arr[i]-mn ];
        
    for(int i = 1; i < range; ++i)
        count [i] += count[i-1];
        
    for(int i = en-1; i >= st; --i) {
        output[ count[arr[i]-mn] - 1 ] = arr[i];
        --count[arr[i]-mn];
    }
    
    for(int i = 0; i < n; ++i)
        arr[st+i] = output[i];
}

int main() {
    int n, arr[100];
    
    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> arr[i];
        
    countingSort(arr, 0, n);
    
    printArray(arr, 0, n);
    
    return 0;
}
