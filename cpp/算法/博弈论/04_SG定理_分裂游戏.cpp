#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll
const int N=21;
const int M=101;
int n;
int sg[N];
int nums[N];
bool appear[M];

void buildsg()
{
    for(int i=1;i<N;i++)
    {
        appear[i]=false;

        for(int j=i-1;j>=0;j--)
        {
            for(int k=j;k>=0;k--)
            {
                appear[sg[k]^sg[j]]=true;
            }
        }

        for(int s=0;s<M;s++)
        {
            if(!appear[s]) {sg[i]=s; break;}
        }
    }
}

void compute_()
{
    int ans=0;
    for(int i=n-1;i>=0;i--)
    {
        if(nums[i]%2==1) ans^=sg[i];
    }

    if(ans==0) { cout<<"-1 -1 -1\n"<<"0"<<endl; return;}

    int cnt=0; int a=-1,b=-1,c=-1,pos;
    for(int i=n-1;i>=1;i--)
    {
        if(nums[i]>0)
        {
            for(int j=i-1;j>=0;j--)
            {
                for(int k=j;k>=0;k--)
                {
                    pos=ans^sg[i]^sg[j]^sg[k];
                    if(pos==0)
                    {
                        cnt++;
                        if(a==-1)
                        {
                            a=i,b=j,c=k;
                        }
                    }
                }
            }
        }
    }

    cout<<(n-1-a)<<" "<<(n-1-b)<<" "<<(n-1-c)<<endl<<cnt<<endl;
}

void solve()
{
    cin>>n;
    for(int i=n-1;i>=0;i--) cin>>nums[i];

    compute_();
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    buildsg();
    
    int t; cin>>t;
    while(t--)
    {
        solve();
    }

    return 0;
}