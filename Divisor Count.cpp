#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define MAX 100005

ll divcnt[MAX];

void DivisorCount(ll n)
{
    for(int i = 1; i <= n; ++i)
        for(int j = i; j <= n; j += i)
            divcnt[j]++;
}

int main()
{
    DivisorCount(10);
    cout << divcnt[10] << endl;
    
    return 0;
}
    
