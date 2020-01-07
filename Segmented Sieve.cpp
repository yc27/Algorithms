#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;

vector<ull> primes;

void sieve(ull n)
{
    bool mask[n+5];
    memset(mask, false, sizeof(mask));

    ull lim = sqrt(n+1);
    
    for(ull i = 4; i <= n; i += 2)
        mask[i] = true;

    primes.push_back(2);

    for(ull i = 3; i <= n; i += 2)
    {
        if(!mask[i])
        {
            primes.push_back(i);
            if(i <= lim)
                for(ull j = i*i; j <= n; j += i*2)
                    mask[j] = true;
        }
    }
}

void primesInRange(ull low, ull high)
{
    low = max(low, 2ull);

    sieve(sqrt(high)+1);
    
    ull n = high - low + 1; 
  
    bool mask[n+5]; 
    memset(mask, false, sizeof(mask)); 
  
    for(int i = 0; i < primes.size(); ++i)
    {
        /*  Find the minimum number in [low..high] that is 
            a multiple of prime[i] (divisible by prime[i]) */
        ull loLim = floor(low / primes[i]) * primes[i];
        if(loLim < low)
            loLim += primes[i];
            
        if(loLim == primes[i]) 
            loLim += primes[i];
             
        /*  Mark multiples of prime[i] in [low..high]: 
            We are marking j - low for j, i.e. each number 
            in range [low, high] is mapped to [0, high - low] */
        for(ull j = loLim; j <= high; j += primes[i]) 
            mask[ j-low ] = true; 
    } 
  
    for(ull i = low; i <= high; i++)
        if(!mask[ i-low ])
            cout << i << "  ";
} 

int main() 
{ 
    int low = 0, high = 200;
    primesInRange(low, high); 
    return 0; 
}
