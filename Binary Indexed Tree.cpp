#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

const int MAX = 1e5 + 10;
const int MOD = 1e9 + 7;
const ll INF = 1LL << 62;

int arr[MAX], n;
ll tree[MAX];

ll query(int idx)
{
    ll ret = 0;
    while(idx > 0)
    {
        ret += tree[idx];
        idx -= idx & -idx;
    }
    
    return ret;
}

ll query(int l, int r)
{
    return query(r) - query(l - 1);
}

void update(int idx, int val)
{
    while(idx <= n)
    {
        tree[idx] += val;
        idx += idx & -idx;
    }
}

void build()
{
    for(int i = 1; i <= n; ++i)
        update(i, arr[i]);
}

int main()
{
    int q, l, r;
    scanf("%d %d", &n, &q);
    
    for(int i = 1; i <= n; ++i)
        scanf("%d", &arr[i]);
    
    build();
    
    while(q--)
    {
        scanf("%d %d", &l, &r);
        printf("%lld\n", query(l, r));
    }
    
    return 0;
}
