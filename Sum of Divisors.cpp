#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

#define MAX 10000000

ull spf[MAX+5];

void sieve(ull n) 
{
    ull lim = sqrt(n+1);
    
    spf[1] = 1;
    for(ull i = 2; i <= n; i += 2)
        spf[i] = 2;

    for(ull i = 3; i <= n; i += 2)
    {
        if(!spf[i])
        {
            spf[i] = i;
            if(i <= lim)
                for(ull j = i*i; j <= n; j += i*2)
                    spf[j] = i;
        }
    }
}

map<ull, int> getFactorization(ull x)
{
    sieve(x);

    map<ull, int> ret;
    while(x != 1)
    {
        ++ret[ spf[x] ];
        x = x / spf[x];
    }
    
    return ret;
}

ull sumOfDivisors(ull n)
{
    if(n == 0)
        return 0;
    
    ull sum = 1, cnt, factor;
    map<ull, int> factors = getFactorization(n);
    for(auto it : factors)
    {
        factor = it.first;
        cnt = it.second + 1;

        sum *= ( ((ull) pow(factor, cnt)) - 1 ) / (factor - 1);
    }

    return sum;		
}

int main() 
{
    cout << sumOfDivisors(MAX) << endl;
    return 0;
}
