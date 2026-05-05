#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=20;

string a,b;
unordered_map<string,int> dis;
int n;
string x[N],y[N];

int bfs()
{
    if(a==b) return 0;

    queue<string> q;
    q.push(a);
    dis[a]=0;

    while(!q.empty())
    {
        string s=q.front(); q.pop();

        if(dis[s]>=10) return -1;

        for(int i=0;i<n;i++)
        {
            int pos=0;
            while(s.find(x[i],pos)!=-1)
            {
                string tmp=s.substr(0,pos)+y[i]+s.substr(pos+x[i].size());
                pos++;
                if(dis[tmp]) continue;

                dis[tmp]=dis[s]+1;
                q.push(tmp);

                if(tmp==b) return dis[tmp];
            }
        }
    }

    return -1;
}

int main()
{
    cin>>a>>b;
    while(cin>>x[n]>>y[n]) n++;

    int ans=bfs();

    if(ans==-1) cout<<"NO ANSWER!"<<endl;
    else cout<<ans<<endl;

    return 0;
}
