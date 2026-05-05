#include<bits/stdc++.h>
using namespace std;

const int N=3e6+10;
int p[N],e[N];
int tree[N][26];
int dex;
bool used[N];

int n,m;

void get_insert(string &line)
{
    int cur=0;
    p[cur]++;

    for(auto c: line)
    {
        int path= c-'a';
        if(tree[cur][path]==0) tree[cur][path]=++dex;
        cur=tree[cur][path];
        p[cur]++;

    }
    e[cur]++;
}

void to_find(string &s)
{
    int cur=0;
    for(auto c: s)
    {
        int path=c-'a';
        if(tree[cur][path]==0) 
        {
            cout<<"WRONG"<<endl;
            return;
        }

        cur=tree[cur][path];
    }

    if(e[cur]==0)
        {
            cout<<"WRONG"<<endl;
            return;
        }
    
    if(!used[cur])
    {
        cout<<"OK"<<endl;
        used[cur]=true;
    }
    else cout<<"REPEAT"<<endl;   

}


int main()
{
    cin>>n;
    while(n--)
    {
        string line;cin>>line;
        get_insert(line);
    }

    cin>>m;
    while(m--)
    {
        string s;cin>>s;
        to_find(s);
    }

    return 0;
}