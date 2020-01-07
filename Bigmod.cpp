#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll BigMod(ll b, ll p, ll m)
{
    if(!p)
        return 1 % m;
        
    ll x = BigMod(b, p/2, m);
    x = (x * x) % m;

    if(p&1)
        x = (x * b) % m;
    return x;
}

int main()
{
    ll b, p, m, t;
    
    cin >> t;
    for(int i = 1; i <= t; ++i)
    {
        cin >> b >> p >> m;
        cout << "Case " << i << ": ";
        cout << BigMod(b, p, m) << endl;
    }
    return 0;
}
