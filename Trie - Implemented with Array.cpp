#include<bits/stdc++.h>
using namespace std;
 
#define   MAX_NODE  100005
#define   MAX_LEN   105

int       node[MAX_NODE][52];
int       isWord[MAX_NODE];
int       root, node_no;

void init()
{
    memset(isWord, 0, sizeof isWord);
    root = 0;
    node_no = 0;
    for(int i = 0; i < 52; ++i)
        node[root][i] = -1;
}

void insert(string str, int len)
{
    int now = root, id;
    for(int i = 0; i < len; ++i)
    {
        id = 0;
        
        if(str[i] >= 'A' && str[i] <= 'Z')
            id = str[i] - 'A';
            
        else if(str[i] >= 'a' && str[i] <= 'z')
            id = str[i] - 'a' + 26;
            
        if(node[now][id] == -1)
        {
            node[now][id] = ++node_no;
            for(int j = 0; j < 52; ++j)
                node[node_no][j] = -1;
        }
        now = node[now][id];
    }
    ++isWord[now];
}

int search(string str, int len)
{
    int now = root, id;
    for(int i = 0; i < len; ++i)
    {
        id = 0;
        
        if(str[i] >= 'A' && str[i] <= 'Z')
            id = str[i] - 'A';
            
        else if(str[i] >= 'a' && str[i] <= 'z')
            id = str[i] - 'a' + 26;
                
        if(node[now][id] == -1)
            return 0;
        
        now = node[now][id];
    }

    return isWord[now];
}

int main()
{
    int t, n, m;
    string str;

    cin >> t;
    for(int tc = 1; tc <= t; ++tc)
    {
        init();
        
        cin >> n;
        while(n--)
        {
            cin >> str;
            insert(str, str.size());
        }
        
        cin >> m;
        while(m--)
        {
            cin >> str;
            cout << search(str, str.size()) << endl;
        }
    }

    return 0;
}
