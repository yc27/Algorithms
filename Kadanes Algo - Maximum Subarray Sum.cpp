#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll maxSubArraySum(const ll arr[], int start, int end)
{
    int left = 0, right = 0;
    ll localMax = 0, globalMax = INT_MIN;

    for(int i = 0; i <= end; ++i)
    {
        localMax = max(arr[i], arr[i]+localMax);
        
        if(localMax == arr[i] && arr[i-1] != 0)
            left = i;   // subarray starts here
            
        if(localMax >= globalMax)
            right = i;  // subarray ends here		
        
        globalMax = max(globalMax, localMax);
    }

    cout << left << " " << right << endl;

    return globalMax;
}

int main()
{
    ll n, arr[100005];

    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> arr[i];
        
    cout << maxSubArraySum(arr, 0, n-1);

    return 0;
}
