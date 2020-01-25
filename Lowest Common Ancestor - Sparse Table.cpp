#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

const int MAX = 2e5 + 10;

int L[MAX];
int P[MAX][22];
int T[MAX];
vector <int> G[MAX];

void dfs(int u, int par, int dep)
{
    T[u] = par;
    L[u] = dep;

    for(int v : G[u])
    {
        if(v == par)
            continue;

        dfs(v, u, dep + 1);
    }
}

int lca_query(int p, int q)
{
    if(L[p] < L[q])
        swap(p, q);

    // calculate log(L[p])
    int lg;
    for(lg = 1; 1 << lg <= L[p]; ++lg)
        ;
    --lg;

    // lift p to the same level as q
    for(int i = lg; i >= 0; i--)
        if(L[p] - (1 << i) >= L[q])
            p = P[p][i];

    if(p == q)
        return p;

    // lift p and q same time
    for(int i = lg; i >= 0; i--)
        if(P[p][i] != -1 && P[p][i] != P[q][i])
            p = P[p][i], q = P[q][i];

    return T[p];
}

void lca_init(int n)
{
    memset(P, -1, sizeof(P));

    for(int i = 0; i < n; i++)
        P[i][0] = T[i];

    for(int j = 1; 1 << j < n; j++)
        for(int i = 0; i < n; i++)
            if(P[i][j - 1] != -1)
                P[i][j] = P[P[i][j - 1]][j - 1];
}

int main()
{
    int n, u, v, q;
    scanf("%d", &n);

    for(int i = 1; i < n; i++) {
        scanf("%d %d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }

    dfs(0, 0, 0);
    lca_init(n);
    scanf("%d", &q);

    while(q--)
    {
        scanf("%d %d", &u, &v);
        printf("%d\n", lca_query(u, v));
    }

    return 0;
}

// NOTE: 0 Based Indexing
