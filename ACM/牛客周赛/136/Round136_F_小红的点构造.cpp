#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n; ll k; cin>>n>>k;

    vector<pair<pair<int,int>,int>> seq;
    seq.push_back({{0,0},0});

    int s=2;
    while(seq.size()<n)
    {
        for(int x=0;x<=s-2&&seq.size()<n;x++)
        {
            seq.push_back({{x,s-1},(x==0)?1:2});
        }
        for(int y=0;y<=s-2&&seq.size()<n;y++)
        {
            seq.push_back({{s-1,y},(y==0)?1:2});
        }

        if(seq.size()<n)
        {
            seq.push_back({{s-1,s-1},2});
        }

        s++;
    }

    ll max_dex=0;
    for(int i=0;i<n;i++) max_dex+=seq[i].second;

    if(k>max_dex)
    {
        cout<<"No"<<endl;
        return 0;
    }

    cout<<"Yes"<<endl;
    ll need=k;
    int far_x=2e6;

    for(int i=0;i<n;i++)
    {
        if(i==0)
        {
            cout<<seq[0].first.first<<" "<<seq[0].first.second<<endl;
            continue;
        }

        int gain=seq[i].second;

        if(need>=gain)
        {
            cout<<seq[i].first.first<<" "<<seq[i].first.second<<endl;
            need-=gain;
        }
        else if(need==1&&gain==2)
        {
            cout<<"-1 0"<<endl;
            need-=1;
        }
        else
        {
            cout<<far_x<<" 1000000"<<endl;
            far_x+=2;
        }
    }

    return 0;
}