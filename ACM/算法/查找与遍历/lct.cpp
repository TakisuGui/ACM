#include <bits/stdc++.h>
using namespace std;

const int N=1e6+10;
int n,q;
int small;

vector<int> edges[N];

pair<int,int> bian[N];
bool st[N];

bool find1[N];

void change(int x)
{
    int new_x=bian[x].first;int new_y=bian[x].second;

    if(st[x]==true)
    {
        edges[new_x].erase(remove(edges[new_x].begin(),edges[new_x].end(),new_y),edges[new_x].end());
        edges[new_y].erase(remove(edges[new_y].begin(),edges[new_y].end(),new_x),edges[new_y].end());

        st[x]=false;
    }

    else
    {
        edges[new_x].push_back(new_y);
        edges[new_y].push_back(new_x);

        st[x]=true;

    }


}

void dfs(int l)
{

    find1[l]=true;

    for(auto u:edges[l])
    {
        if(!find1[u])
        {
            if(small>u)small=u;
                dfs(u);
        }
    }

}


int main()
{
    cin>>n>>q;

    memset(st,true,sizeof st);

    for(int i=1;i<n;i++)
    {
        int x;int y;cin>>x>>y;
        edges[x].push_back(y);
        edges[y].push_back(x);

        bian[i]={x,y};
        
    }

    for(int i=1;i<=q;i++)
    {
        int j,l;cin>>j>>l;

        change(j);
        small=l;
        memset(find1,false,sizeof find1);

        if(l==1)
        {
            cout<<"1"<<endl;
            continue;
        }

        if(!edges[l].size())
        {
            cout<<l<<endl;
            continue;
        }

        dfs(l);

        cout<<small<<endl;

    }


    return 0;
}