#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using ull=unsigned long long;
#define int ll
const int N= 15000+10;
const int MOD=1e9+7;


int a[N],b[N];
int mina[N],minb[N];
bool used[N];

void solve()
{
    int n,m;
    if(!(cin>>n>>m))return;

    for(int i=1;i<=n+m;i++){
        used[i]=false;
    }

    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]!=0)used[a[i]]=true;
    }
    for(int i=0;i<m;i++){
        cin>>b[i];
        if(b[i]!=0)used[b[i]]=true;
    }

    int cur=1e9;
    for(int i=n-1;i>=0;i--){
        if(a[i]!=0)cur=a[i];
        mina[i]=cur;
    }

    cur=1e9;
    for(int i=m-1;i>=0;i--){
        if(b[i]!=0)cur=b[i];
        minb[i]=cur;
    }
    

    int i=0,j=0;
    int beforea=0,beforeb=0;

    for(int k=1;k<=n+m;k++){
        if(used[k])continue;

        while(i<n&&a[i]!=0) beforea=a[i],i++;
        while(j<m&&b[j]!=0) beforeb=b[j],j++;

        if(i>=n){
            b[j++]=k;
            continue;
        }
        if(j>=m){
            a[i++]=k;
            continue;
        }

        if(mina[i]<minb[j])
        {
            a[i++]=k;
            beforea=k;
        }
        else if(mina[i]> minb[j])
        {
            b[j++]=k;
            beforeb=k;
        }
        else
        {
            if(beforea<beforeb)
            {
                a[i++]=k;
                beforea=k;
            }
            else
            {
                 b[j++]=k;
                beforeb=k;
            }
        }
    }

    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    cout<<endl;
    for(int i=0;i<m;i++) cout<<b[i]<<" ";
}


signed main()
{
    ll t; t=1;
    while(t--)
    {
        solve();
    }

    return 0;
}