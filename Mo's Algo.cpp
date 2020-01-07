#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

const int MAX = 1e6 + 10;

int BLOCK_SIZE, ar[MAX];
ll sum, ans[MAX];

struct Node
{
    int l, r, id;

    Node() {};

    Node(int _l, int _r, int _id)
    {
        l = _l;
        r = _r;
        id = _id;
    }

    bool operator<(const Node &b) const
    {
        if( (l / BLOCK_SIZE) != (b.l / BLOCK_SIZE) )
            return (l / BLOCK_SIZE) < (b.l / BLOCK_SIZE);

        return r < b.r;
    }
} qr[MAX];

void add(int x)
{
    sum += ar[x];
}

void del(int x)
{
    sum -= ar[x];
}

int main()
{
    int n, m, l, r;
    scanf("%d %d", &n, &m);
    BLOCK_SIZE = sqrt(n);

    for(int i = 0; i < n; ++i)
        scanf("%d", &ar[i]);

    for(int i = 0; i < m; ++i)
    {
        scanf("%d %d", &l, &r);
        qr[i] = Node(l, r, i);
    }

    sort(qr, qr+m);

    int L, R, cur_L = 0, cur_R = 0;
    for(int i = 0; i < m; ++i)
    {
        L = qr[i].l;
        R = qr[i].r;

        while(cur_L < L)
        {
            del(cur_L);
            ++cur_L;
        }
        
        while(cur_L > L) 
        {
            add(cur_L-1);
            cur_L--;
        }
        
        while(cur_R <= R) 
        {
            add(cur_R);
            cur_R++;
        }
        
        while(cur_R > R+1) 
        {
            del(cur_R-1);
            cur_R--; 
        }

        ans[ qr[i].id ] = sum;
    }

    for(int i = 0; i < m; ++i)
        printf("%lld\n", ans[i]);

    return 0;
}
