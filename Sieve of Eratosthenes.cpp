#include<bits/stdc++.h>
using namespace std;

#define MAX 10000000

bool mask[MAX+5];
vector<int> primes;

void sieve(int n)
{
    int lim = sqrt(n+1);
    
    for(int i = 4; i <= n; i += 2)
        mask[i] = true;

    primes.push_back(2);

    for(int i = 3; i <= n; i += 2)
    {
        if(!mask[i])
        {
            primes.push_back(i);
            if(i <= lim)
                for(int j = i*i; j <= n; j += i*2)
                    mask[j] = true;
        }
    }

    return;
}

int main()
{
    sieve(MAX);
    printf("Total number of prime less than %d : %d", MAX, (int) primes.size());
}
