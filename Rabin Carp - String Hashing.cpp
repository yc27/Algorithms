#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
const int BASE = 331;

const int MAX = 2e6 + 10;
const int MOD = 1e9 + 7;
const ll  INF = 1LL << 62;

ll powr[MAX];
ll hashVal[MAX];

void pre_power()
{
    powr[0] = 1;
    for(int i = 1; i < MAX; ++i)
        powr[i] = (powr[i-1] * BASE) % MOD;
}

void hashing(string str, int len)
{
    hashVal[0] = 0;
    for(int i = 0; i < len; ++i)
        hashVal[i] = (hashVal[i-1] * BASE + str[i]) % MOD;
}

ll findHash(int l, int r)   // returns hash for the substring from string[l] to string[r], l & r inclusive
{
    return (hashVal[r] - (hashVal[l-1] * powr[ r-l+1 ]) % MOD + MOD) % MOD;
}

int main()
{
    int n;
    string str;
    
    pre_power();
    cin >> n >> str;
    hashing(str, n);
    
    for(int i = 0; i < n; ++i)
        cout << findHash(0, i) << endl;
    
    return 0;
}
