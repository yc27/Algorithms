/***********************************
* Time Complexity
    * Worst complexity: O(log(n))
    * Average complexity: O(log(n))
    * Best complexity: O(1)

* Space complexity: O(1)
**********************************/

#include<bits/stdc++.h>
using namespace std;

int find(int arr[], int n, int x) {
    int left = 0, right = n, mid;
    
    while(left <= right) {
        mid = left + (right - left) / 2;
        
        if(arr[mid] == x)
            return mid;
            
        if(arr[mid] < x)
            left = mid + 1;
        else
            right = mid - 1;
    }
    
    return -1;
}

int main() {
    int arr[100], n, x;
    
    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> arr[i];
        
    cin >> x;
    
    int result = find(arr, n, x);
    
    if(result > -1)
        cout << "Found " << x << " at index of " << result << endl;
        
    else
        cout << "Not Found" << endl;
        
    return 0;
}
