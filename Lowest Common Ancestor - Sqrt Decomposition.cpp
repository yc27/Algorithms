#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e5+5;

int block_sz;
int depth[MAX];
int parent[MAX];
int jump_parent[MAX];

vector <int> adj[MAX];

int LCANaive(int u,int v) 
{
    if(u == v)
        return u;
    
    if(depth[u] > depth[v])
        swap(u,v);
    
    v = parent[v];
    
    return LCANaive(u,v);
}

int LCA(int u, int v)
{
    while(jump_parent[u] != jump_parent[v])
    {
        if(depth[u] > depth[v])
            swap(u,v);
        
        v = jump_parent[v];
    }
    
    return LCANaive(u,v);
}

void dfs(int cur, int prev)
{
    depth[cur] = depth[prev] + 1;
    
    parent[cur] = prev;

    if(depth[cur] % block_sz == 0)
        jump_parent[cur] = parent[cur];
    else
        jump_parent[cur] = jump_parent[prev];

    for(int i = 0; i < adj[cur].size(); ++i)
        if(adj[cur][i] != prev)
            dfs(adj[cur][i], cur);
}

void init(int height)
{
    block_sz = sqrt(height); 
    depth[0] = -1;
    
    dfs(1, 0); 
}

int getHeight(int u, int par, int h)
{
    int height = h;
    for(int v : adj[u])
        if(v != par)
            height = getHeight(v, u, h+1);
    return height;
}

int main()
{
    int n, q, u, v;
    cin >> n;
    for(int i = 1; i < n; ++i)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    int height = getHeight(1, 1, 0);
    init(height);
    
    cin >> q;
    while(q--)
    {
        cin >> u >> v;
        cout << LCA(u, v) << endl;
    }

    return 0;
}

// NOTE: 1 Based Indexing
