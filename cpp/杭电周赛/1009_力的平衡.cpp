#include <bits/stdc++.h>
using namespace std;
const int LIMIT=500;
const int OFFSET=LIMIT;
const int SIZE=2*LIMIT+1;

int slove()
{
    int k; cin>>k;
    vector<pair<int,int>> force(k);

    bool have_zero=false;
    for(int i=0;i<k;i++)
    {
        cin>>force[i].first>>force[i].second;
        if(force[i].first==0&&force[i].second==0) have_zero=true;
    }

    if(have_zero) return 1;

    bool pos_x=false,neg_x=false,zero_x=false;
    bool pos_y=false,neg_y=false,zero_y=false;

    for(auto &p:force)
    {
        if(p.first>0) pos_x=true;
        else if(p.first<0) neg_x=true;
        else zero_x=true;

        if(p.second>0) pos_y=true;
        else if(p.second<0) neg_y=true;
        else zero_y=true;
    }

    if ((pos_x&&!neg_x&&!zero_x)||(!pos_x&&neg_x&&!zero_x)) return -1;
    if ((pos_y&&!neg_y&&!zero_y)||(!pos_y&&neg_y&&!zero_y)) return -1;

    queue<pair<int,int>> q;
    vector<vector<int>> dist(SIZE,vector<int>(SIZE,-1));
    dist[0+OFFSET][0+OFFSET]=0;
    q.push({0,0});

    while(!q.empty())
    {
        auto[x,y]=q.front(); q.pop();
        int d=dist[x+OFFSET][y+OFFSET];
        for(auto &f:force)
        {
            int nx=x+f.first;
            int ny=y+f.second;

            if(nx<-LIMIT||nx>LIMIT||ny<-LIMIT||ny>LIMIT) continue;

            int nx_idx=nx+OFFSET;
            int ny_idx=ny+OFFSET;
            
            if(dist[nx_idx][ny_idx]!=-1) continue;

            dist[nx_idx][ny_idx]=d+1;

            if(nx==0&&ny==0)
            {
                return d+1;
            }            
            q.push({nx,ny});
        }
    }

    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;
    while(t--)
    {
        cout<<slove()<<endl;
    }

    return 0;
}