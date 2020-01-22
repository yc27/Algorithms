#include<bits/stdc++.h>
using namespace std;

const int Max = 1e5 + 10;

int arr[Max];
int seg[Max * 4];

void build(int node, int l, int r)
{
    if(l == r)
    {
        seg[node] = arr[l];
        return;
    }

    int mid = (l + r) >> 1;
    int lf = node * 2;
    int rt = node * 2 + 1;

    build(lf, l, mid);
    build(rt, mid + 1, r);
    seg[node] = seg[lf] + seg[rt];
}

int update(int node, int l, int r, int idx, int val)
{
    if(l == r)
    {
        seg[node] = val;
        return seg[node];
    }

    int mid = (l + r) >> 1, u = seg[node * 2], v = seg[node * 2 + 1];
    if(mid >= idx)
        u = update(2 * node, l, mid, idx, val);
    else
        v = update(2 * node + 1, mid + 1, r, idx, val);

    return seg[node] = u + v;
}

int query(int node, int l, int r, int L, int R)
{
    if(R < l || L > r)
        return 0;

    if(L <= l && r <= R)
        return seg[node];

    int mid = (l + r) >> 1;
    int u = query(node * 2, l, mid, L, R);
    int v = query(node * 2 + 1, mid + 1, r, L, R);

    return u + v;
}

int main()
{
    for(int i = 1; i <= 100000; ++i)
        arr[i] = 1;
        
    build(1, 1, 100000);
    cout << nooo;

    return 0;
}
