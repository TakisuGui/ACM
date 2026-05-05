#include<bits/stdc++.h>
using namespace std;

const int N=3e6+10;
int p[N],e[N];
int tree[N][26];
int dex;

int T;

int get_idx(char c) {
    if ('a' <= c && c <= 'z')
    {
        return c-'a';
    } 
    else if ('A' <= c && c <= 'Z') 
    {
        return c - 'A' + 26;    
    } 
    else 
    {  
        return c - '0' + 52;      
    }
}

void get_insert(string &line)
{
    int cur=0;
    p[cur]++;

    for(auto c:line)
    {
        int path=get_idx(c);
        if(tree[cur][path]==0) tree[cur][path]=++dex;

        cur=tree[cur][path];
        p[cur]++;
    }
    e[cur]++;
}

int find_pre(string &s)
{
    int cur=0;

    for(auto c:s)
    {
        int path=get_idx(c);
        if(tree[cur][path]==0) return 0;
        cur=tree[cur][path];      
    }

    return p[cur];
}

int main()
{
    cin>>T;

    while(T--)
    {
        for (int i = 0; i <= dex; i++) 
        {
            memset(tree[i], 0, sizeof(tree[i]));
            p[i] = 0;
        }
        dex = 0;

        int n,q;cin>>n>>q;

        for(int i=0;i<n;i++)
        {
            string line;cin>>line;
            get_insert(line);
        }

        for(int i=0;i<q;i++)
        {
            string s;cin>>s;
            cout<<find_pre(s)<<endl;
        }
    }

    return 0;

}