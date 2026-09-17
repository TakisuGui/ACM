#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=25;

int a[N];
int ans=0;
int n;

void dfs(int dex,double pos,int cnt)
{
    if(dex==n)
    {
        ans=max(ans,cnt);
        return;
    }

    double new_pos=pos+a[dex];
    int new_cnt=cnt+(pos<0&&new_pos>0 ? 1:0);
    dfs(dex+1,new_pos,new_cnt);

    new_pos=pos-a[dex];
    new_cnt=cnt+(pos>0&&new_pos<0 ? 1:0);
    dfs(dex+1,new_pos,new_cnt);
}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];

    dfs(0,0.5,0);
    cout<<ans<<endl;

    return 0;
}