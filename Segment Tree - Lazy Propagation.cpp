#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
const int MAX = 1e5 + 10;

ll arr[MAX];
struct Node
{
    ll prop, sum;
} tree[MAX * 4];

void build(ll node, ll l, ll r)
{
    if(l == r)
    {
        tree[node].sum = arr[l];
        return;
    }

    ll lf = node << 1;
    ll rt = (node << 1) + 1;
    ll mid = (l + r) >> 1;

    build(lf, l, mid);
    build(rt, mid + 1, r);

    tree[node].sum = tree[lf].sum + tree[rt].sum;
    tree[node].prop = 0;
}

ll query(ll node, ll l, ll r, ll L, ll R, ll cary = 0)      // returns result for the range (L, R) inclusive
{
    if(L > r || R < l)
        return 0;

    if(l >= L and r <= R)
        return tree[node].sum + cary * (r - l + 1);

    ll lf = node << 1;
    ll rt = (node << 1) + 1;
    ll mid = (l + r) >> 1;

    ll u = query(lf, l, mid, L, R, cary + tree[node].prop);
    ll v = query(rt, mid + 1, r, L, R, cary + tree[node].prop);

    return u + v;
}

void update(ll node, ll l, ll r, ll L, ll R, ll val)        // updates the values of the range (L, R) inclusive with 'val'
{
    if(L > r || R < l)
        return;

    if(l >= L && r <= R)
    {
        tree[node].sum += ((r - l + 1) * val);
        tree[node].prop += val;
        return;
    }
    
    ll lf = node << 1;
    ll rt = (node << 1) + 1;
    ll mid = (l + r) >> 1;
    
    update(lf, l, mid, L, R, val);
    update(rt, mid + 1, r, L, R, val);
    
    tree[node].sum = tree[lf].sum + tree[rt].sum + (r - l + 1) * tree[node].prop;
}

int main()
{
    for(int i = 1; i <= 100000; ++i)
        arr[i] = 1;
        
    build(1, 1, 100000);
    
    cout << query(1, 1, 100000, 10, 20) << endl;
    update(1, 1, 100000, 10, 20, 2);
    cout << query(1, 1, 100000, 10, 20) << endl;

    return 0;
}
