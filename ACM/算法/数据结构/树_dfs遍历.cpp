#include<bits/stdc++.h>
using namespace std;


const int N=1e5+10;

int n;
vector <int> edges[N];//存储树

bool st[N];//标记哪些点已经访问过了

void dfs(int u){

    cout<<u<<" ";
    st[u]=true;

    //访问所有孩子
    for(auto v:edges[u])
    {
        if(!st[v]){
            dfs(v);
        }
    }
}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int a,b;cin>>a>>b;

        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    //深度优先遍历；
    dfs(1);




    return 0;
}



#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;

int h[N],e[2*N],ne[2*N],id;
int n;
bool st[N];

void add(int a,int b){
    id++;
    e[id]=b;

    ne[id]=h[a];
    h[a]=id;
}


void dfs(int u){
    cout<<u<<" ";
    st[u]=true;

    for(int i=h[u];i;i=ne[i]){

        if(!st[e[i]])
        {
            dfs(e[i]);
        }
    }

}




int main()
{
    cin>>n;
    for(int i=1;i<n;i++)
    {
        int a,b;cin>>a>>b;
        add(a,b);
        add(b,a);
    }

    dfs(1);
}