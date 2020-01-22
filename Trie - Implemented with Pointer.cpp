#include <bits/stdc++.h>
using namespace std;

class Trie
{
    public:
    struct node
    {
        bool endmark;
        node* next[26];
        node()
        {
            endmark = false;
            for (int i = 0; i < 26; i++)
                next[i] = NULL;
        }
    };
    node* root = new node();

    void insert(string str, int sz)
    {
        node* curr = root;
        for (int i = 0; i < sz; i++)
        {
            int id = str[i] - 'a';
            if (curr->next[id] == NULL)
                curr->next[id] = new node();
            curr = curr->next[id];
        }
        curr->endmark = true;
    }

    bool search(string str, int sz)
    {
        node* curr = root;
        for (int i = 0; i < sz; i++)
        {
            int id = str[i] - 'a';
            if (curr->next[id] == NULL)
                return false;
            curr = curr->next[id];
        }
        return curr->endmark;
    }

    void del(node* cur)
    {
        for(int i = 0; i < 26; i++)
            if(cur->next[i] != NULL)
                del(cur->next[i]);

        delete cur;
    }
};

int main()
{
    int t, n;
    cin >> t;
    for(int tc = 0; tc < t; ++tc)
    {
        Trie boss;
        string str[10005];
        bool f = 0;
        
        cin >> n;
        for(int i = 0; i < n; ++i)
        {
            cin >> str[i];
            boss.insert(str[i], str[i].size());
        }
        
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < str[i].size()-1; ++j)
            {
                string s = str[i].substr(0, j+1);
                if(boss.search(s, j+1))
                {
                    f = 1;
                    break;
                }
            }
            if(f)
                break;
        }
        if(f)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
        
        boss.del(boss.root);
    }

    return 0;
}
