#include<bits/stdc++.h>
using namespace std;

struct Activity
{
    int id;
    int start;
    int finish;
};

bool comp(Activity a, Activity b)
{ 
    return (a.finish < b.finish); 
} 

int main()
{
    int n;
    
    cin>>n;
    
    Activity act[n+5];
    
    for(int i = 0; i < n; ++i)
        cin >> act[i].id >> act[i].start >> act[i].finish;
        
    sort(act, act+n, comp);
    
    int j=0;
    cout << act[j].id << endl;
    for(int i = 1; i < n; ++i)
    {
        if(act[i].start >= act[j].finish)
        {
            cout << act[i].id <<endl;
            j = i;
        }
    }
}
