#include<bits/stdc++.h>
using namespace std;

#define INF (1<<28)

struct node
{
    int u;
    int cost;
    bool operator <(const node &a) const
    {
        return cost > a.cost;
    }
};

priority_queue <node> PQ;
vector <node> vec[100];
int nodes, edges, dist[100];


void dijkstra(int start)
{
    node u, v;
    int uu, vv, cst;
    v.u = start;
    v.cost = dist[start];
    PQ.push(v);
    
    while(PQ.size())
    {
        u = PQ.top();
        PQ.pop();
        uu = u.u;
        for(int i = 0; i < vec[uu].size(); ++i)
        {
            vv = vec[uu][i].u;
            cst = vec[uu][i].cost;
            if(dist[uu]+cst < dist[vv])
            {
                dist[vv] = dist[uu]+cst;
                v.u = vv;
                v.cost = dist[vv];
                PQ.push(v);
            }
        }
    }

    return;
}

int main()
{
    int a, b, c;
    node v;
    cin >> nodes >> edges;
    for(int i = 1; i <= nodes; ++i)
        dist[i] = INF;

    for(int i = 1; i <= edges; ++i)
    {
        cin >> a >> b >> c;
        v.u = b;
        v.cost = c;
        vec[a].push_back(v);
    }

    dist[1] = 0;
    dijkstra(1);
    for(int i = 1; i <= nodes; ++i)
        cout << dist[i] << " ";


    return 0;

}