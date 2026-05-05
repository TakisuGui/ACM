#include<bits/stdc++.h>
using namespace std;
 

const int N=1e5+10;

int n;
vector<int> edges[N];
bool st[N];

void bfs(){

    queue<int> q;
    q.push(1);
    st[1]=true;

    while(q.size())
    {
        int u=q.front();
        q.pop();
        cout<<u<<" ";


        for(auto v:edges[u]){
            if(!st[v]){
                q.push(v);
                st[v]=true;
            }
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

    bfs();

    return 0;
}


#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;

int h[N],e[2*N],ne[2*N],id;
bool st[N];

void add(int a,int b){
    id++;
    e[id]=b;

    ne[id]=h[a];
    h[a]=id;
}

void bfs(){
    queue<int> q;
    q.push(1);
    st[1]=true;

    while(q.size())
    {
        int u=q.front();
        q.pop(); 
        cout<<u<<" ";

        for(int v=h[u];v;v=ne[v]){
            if(!st[e[v]]){
                q.push(e[v]);
                st[e[v]]=true;
            }
        }
    }


}




int main(){
    int n;
    cin>>n;
    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        add(a,b);
        add(b,a);

    }
    
    bfs();






    return 0;
}
