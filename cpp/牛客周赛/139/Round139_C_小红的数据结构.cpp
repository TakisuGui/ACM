#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
int a[N];
vector<int> qans,sans;

int main()
{
    int n,t; cin>>n>>t;
    for(int i=0;i<n;i++) cin>>a[i];

    queue<int> q;stack<int> s;
    for(int i=0;i<t;i++)
    {
        int step; cin>>step;
        if(step==1)
        {
            int x; cin>>x;
            q.push(x);
            s.push(x);
        }
        else
        {
            int top_s=s.top(); s.pop(); sans.push_back(top_s);
            int top_q=q.front(); q.pop(); qans.push_back(top_q);
        }
    }

    bool qpass=true, spass=true;

    for(int i=0;i<n;i++) if(sans[i]!=a[i]) {spass=false; break;}
    for(int i=0;i<n;i++) if(qans[i]!=a[i]) {qpass=false; break;}

    if(spass&&qpass) cout<<"both"<<endl;
    else if(spass&&!qpass) cout<<"stack"<<endl;
    else if(!spass&&qpass) cout<<"queue"<<endl;
    else cout<<"-1"<<endl;

    return 0;
}